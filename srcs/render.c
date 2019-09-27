/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/30 17:00:04 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/30 17:00:04 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_line(t_env *env, int y, int x, int p_height)
{
	SDL_Point *point;
	int i;

	i = 0;
	if (!(point = (SDL_Point*)malloc(sizeof(SDL_Point) * p_height)))
		return;
	while (i < p_height)
	{
		point[i].x = x;
		point[i].y = y;
		y++;
		i++;
	}
	SDL_RenderDrawPoints(env->render ,point , i);
	free(point);
}
void	draw_slice(t_env *env, float dist, int type)
{
	int p_height;
	int ymax;
	int y;

	if (dist <= 0)
		return;
	if (type == 0)
	{
		if (env->r_angle > 0 && env->r_angle < 180)
			SDL_SetRenderDrawColor(env->render, 255, 0, 34, 255);
		else
			SDL_SetRenderDrawColor(env->render, 115, 29, 215, 255);
	}
	else
	{
		if (env->r_angle > 270 || env->r_angle < 90)
			SDL_SetRenderDrawColor(env->render, 62, 195, 0, 255);
		else
			SDL_SetRenderDrawColor(env->render, 0, 79, 255, 255);
	}
	p_height = trunc(SIZE / dist * env->sdist);
	if (p_height > env->height)
		p_height = env->height;
	y = (env->height / 2) - (p_height / 2);
	if ((env->ray_nb % 1) == 0)
		draw_line(env, y, env->ray_nb, p_height);
}

void	calc_dist(t_env *env, t_player *p, t_pt *ph, t_pt *pv)
{
	float	disth;
	float	distv;

	if (env->hhit == 1)
		disth = sqrt((p->xpos - ph->x) * (p->xpos - ph->x) + (p->ypos - ph->y) * (p->ypos - ph->y));
	else
		disth = 99999;
	if (env->vhit == 1)
		distv = sqrt((p->xpos - pv->x) * (p->xpos - pv->x) + (p->ypos - pv->y) * (p->ypos - pv->y));
	else
		distv = 99999;
//	printf("distv = %f, pvx = %f, pvy = %f\n\n", distv, pv->x, pv->y), fflush(stdout);
//	printf("disth = %f, phx = %f, phy = %f\n", disth, ph->x, ph->y), fflush(stdout);

	if (disth > distv)
		draw_slice(env, distv * env->cos_t[abs((int)env->r_angle - p->alpha)], 1);
	else
		draw_slice(env, disth * env->cos_t[abs((int)env->r_angle - p->alpha)], 0);
}

void	cast_ray(t_env *env, t_player *p)
{
	t_pt	dv;
	t_pt	dh;
	t_pt	pv;
	t_pt	ph;
	int 	i;

	i = 0;
	init_horizontal(env, p, &dh, &ph);
	init_vertical(env, p, &dv, &pv);
	while (env->hhit == 0 && i < 500)
	{
		horizontal_ray(env, &ph, &dh);
		i++;
	}
	i = 0;
	while (env->vhit == 0 && i < 500)
	{
		vertical_ray(env, &pv, &dv);
		i++;
	}
	calc_dist(env, p, &ph, &pv);
	env->vhit = 0;
	env->hhit = 0;
}

void	render(t_env *env, t_player *p)
{
	env->ray_nb = 0;
	env->p_dist = SIZE / env->sdist;

	env->r_angle = angle_adjust(p->alpha + (env->fov / 2));
//	cast_ray(env, p);
	while(env->ray_nb < env->width)
	{
		cast_ray(env, p);
		env->r_angle -= env->r_inc;
		env->r_angle = angle_adjust(env->r_angle);
		env->ray_nb++;
	}
}