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

void	draw_line(t_env *env, int y, int x, int p_height, int offset)
{
	SDL_Color c;
	int i;
	float pas;
	float yp;
	int ypd;

	pas = SIZE / (float)p_height;
	i = 0;
	yp = 0;
	ypd = 0;

	c.r = 135;
	c.g = 206;
	c.b = 235;
	while (i < (env->height - p_height) / 2)
	{
		put_pixel(env->surf, x, i, SDL_MapRGB(env->surf->format, c.r, c.g, c.b));
		i++;
	}
	i = 0;
    while (i < p_height)
	{
        if (x >= 0 && y >= 0 && x < env->width && y < env->height)
        {
            if (ypd != trunc(yp))
            {
                SDL_GetRGB(get_pixel(env->text, offset, floor(yp)), env->surf->format, &c.r, &c.g, &c.b);
                ypd = trunc(yp);
            }
            put_pixel(env->surf, x, y, SDL_MapRGB(env->surf->format, c.r, c.g, c.b));
        }
        yp += pas;
        y++;
        i++;
    }
	c.r = 128;
	c.g = 128;
	c.b = 128;
	while (y < env->height)
	{
		put_pixel(env->surf, x, y, SDL_MapRGB(env->surf->format, c.r, c.g, c.b));
    	y++;
	}
}
void	draw_slice(t_env *env, float dist, int type, t_pt *pi)
{
	int p_height;
	int offset;
	int y;

	if (dist <= 0)
		return;
	if (type == 0)
	{
		if (env->r_angle > 0 && env->r_angle < 180)
			env->text = env->textN;
		else
            env->text = env->textS;
		offset = (int)pi->x % SIZE;
	}
	else
	{
		if (env->r_angle > 270 || env->r_angle < 90)
            env->text = env->textE;
		else
            env->text = env->textW;
		offset = (int)pi->y % SIZE;
	}
	p_height = trunc(SIZE / dist * env->sdist);
	y = (env->height / 2) - (p_height / 2);
	draw_line(env, y, env->ray_nb, p_height, offset);
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
//	printf("distv = %f, pvx = %f, pvy = %f, vhit = %d\n\n", distv, pv->x, pv->y, env->vhit), fflush(stdout);
//	printf("disth = %f, phx = %f, phy = %f, hhit = %d\n", disth, ph->x, ph->y, env->hhit), fflush(stdout);

	if (disth > distv)
		draw_slice(env, distv * env->cos_t[abs((int)env->r_angle - p->alpha)], 1, pv);
	else
		draw_slice(env, disth * env->cos_t[abs((int)env->r_angle - p->alpha)], 0, ph);
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

void	render(t_env *env, t_player *p)
{
	env->ray_nb = 0;
	env->p_dist = SIZE / env->sdist;
//	printf("alpha %d, PX %d, PY %d \n", p->alpha, p->xpos, p->ypos),fflush(stdout);
	env->r_angle = angle_adjust(p->alpha + (env->fov / 2));
	while(env->ray_nb < env->width)
	{
		cast_ray(env, p);
		env->r_angle -= env->r_inc;
		env->r_angle = angle_adjust(env->r_angle);
		env->ray_nb++;
	}
}