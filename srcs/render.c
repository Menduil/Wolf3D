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

void	texture_chooser(t_env *env, int type)
{
	if (type == 0)
	{
		if (env->r_angle > 0 && env->r_angle < 180)
			env->text = env->text_n;
		else
			env->text = env->text_s;
	}
	else
	{
		if (env->r_angle > 270 || env->r_angle < 90)
			env->text = env->text_e;
		else
			env->text = env->text_w;
	}
}

void	draw_slice(t_env *env, float dist, int type, t_pt *pi)
{
	int		p_height;
	int		offset;
	int		y;
	t_pt	col;

	if (dist <= 0)
		return ;
	texture_chooser(env, type);
	if (type == 0)
		offset = (int)pi->x % SIZE;
	else
		offset = (int)pi->y % SIZE;
	p_height = trunc(SIZE / dist * env->sdist);
	y = (env->height / 2) - (p_height / 2);
	col.y = y;
	col.x = env->ray_nb;
	draw_line(env, &col, p_height, offset);
}

void	calc_dist(t_env *env, t_player *p, t_pt *ph, t_pt *pv)
{
	float	disth;
	float	distv;

	if (env->hhit == 1)
		disth = sqrt((p->xpos - ph->x)
				* (p->xpos - ph->x) + (p->ypos - ph->y) * (p->ypos - ph->y));
	else
		disth = 99999;
	if (env->vhit == 1)
		distv = sqrt((p->xpos - pv->x)
				* (p->xpos - pv->x) + (p->ypos - pv->y) * (p->ypos - pv->y));
	else
		distv = 99999;
	if (disth > distv)
		draw_slice(env, distv
		* cos(d_to_r(abs((int)env->r_angle - p->alpha))), 1, pv);
	else
		draw_slice(env, disth
		* cos(d_to_r(abs((int)env->r_angle - p->alpha))), 0, ph);
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
	env->r_angle = angle_adjust(p->alpha + (env->fov / 2));
	while (env->ray_nb < env->width)
	{
		cast_ray(env, p);
		env->r_angle -= env->r_inc;
		env->r_angle = angle_adjust(env->r_angle);
		env->ray_nb++;
	}
}
