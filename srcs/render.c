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

void	draw_slice(t_env *env, float dist, int type)
{
	int p_height;
	int i;

	if (type == 0)
	{
		if (env->r_angle > 0 && env->r_angle < 180)
			SDL_SetRenderDrawColor(env->render, 0, 255, 0, 255);
		else
			SDL_SetRenderDrawColor(env->render, 255, 0, 0, 255);
	}
	else
	{
		if (env->r_angle > 270 || env->r_angle < 90)
			SDL_SetRenderDrawColor(env->render, 0, 0, 255, 255);
		else
			SDL_SetRenderDrawColor(env->render, 255, 0, 255, 255);
	}
	p_height = SIZE / dist * env->sdist;
	if (p_height > env->height)
		p_height = env->height;
	i = (env->height / 2) - (p_height / 2);
	while (i < (env->height / 2) + (p_height / 2))
	{
		SDL_RenderDrawPoint(env->render, env->ray_nb, i);
		i += 3;
	}
//	SDL_RenderDrawPoint(env->render, env->ray_nb, (env->height / 2) - (p_height / 2));
//	SDL_RenderDrawPoint(env->render, env->ray_nb, (env->height / 2) + (p_height / 2));

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
	printf("disth = %f, phx = %d, phy = %d\n", disth, ph->x, ph->y), fflush(stdout);
	printf("distv = %f, pvx = %d, pvy = %d\n\n", distv, pv->x, pv->y), fflush(stdout);
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

	init_horizontal(env, p, &dh, &ph);
	init_vertical(env, p, &dv, &pv);
	while (env->hhit == 0)
		horizontal_ray(env, &ph, &dh);
	while (env->vhit == 0)
		vertical_ray(env, &pv, &dv);
	calc_dist(env, p, &ph, &pv);
	env->vhit = 0;
	env->hhit = 0;
}

//void	SinCostest(t_env *env)
//{
//	int x = 0;
//	while (x < 360)
//	{
//
//		SDL_SetRenderDrawColor(env->render, 0, 255, 0, 255);
//		SDL_RenderDrawPoint(env->render, x, env->cos_t[x] * 300 + env->height / 2);
//		SDL_SetRenderDrawColor(env->render, 0, 0, 255, 255);
//		SDL_RenderDrawPoint(env->render, x, env->sin_t[x] * 300 + env->height / 2);
//		x++;
//	}
//}

void	render(t_env *env, t_player *p)
{
	env->ray_nb = 0;
	env->p_dist = SIZE / env->sdist;

	if (env->turn == 1)
		p->alpha += 2;
	else if (env->turn == -1)
		p->alpha -= 2;
	if (p->alpha < 0)
		p->alpha = 359 + p->alpha;
	else if (p->alpha > 359)
		p->alpha = 0 - (360 - p->alpha);
	printf("alpha %d, PX %f, PY %f \n", p->alpha, p->xpos, p->ypos),fflush(stdout);
	if (env->walk == 1)
	{
		p->xpos += env->cos_t[p->alpha] * p->speed;
		p->ypos -= env->sin_t[p->alpha] * p->speed;
	}
	else if (env->walk == -1)
	{
		p->xpos -= env->cos_t[p->alpha] * p->speed;
		p->ypos += env->sin_t[p->alpha] * p->speed;
	}
	env->r_angle = p->alpha + (env->fov / 2);
	if (env->r_angle < 0)
		env->r_angle = 359 + env->r_angle;
	else if (env->r_angle > 359)
		env->r_angle = 0 - (360 - env->r_angle);

//	cast_ray(env, p);
//	SinCostest(env);
	while(env->ray_nb < env->width)
	{
		cast_ray(env, p);
		env->r_angle -= env->r_inc;
		if (env->r_angle < 0)
			env->r_angle = 359 + env->r_angle;
		else if (env->r_angle > 359)
			env->r_angle = 0 - (360 - env->r_angle);
		env->ray_nb++;
	}
}