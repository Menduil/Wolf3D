/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/30 17:45:31 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/30 17:45:31 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_horizontal(t_env *env, t_player *p, t_pt *dh, t_pt *ph)
{
	int dy;
	dy = p->ypos % SIZE;

	if (trunc(env->r_angle) == 0 || trunc(env->r_angle) == 180)
	{
		env->hhit = 2;
		return ;
	}
	else if (env->r_angle > 0 && env->r_angle < 180)
	{
		ph->y = (p->ypos - dy);
		ph->x = (p->xpos + (dy / tan(d_to_r(env->r_angle))));
		dh->y = -SIZE;
		dh->x = (1 / tan(d_to_r(env->r_angle)) * SIZE);
		check_walls(env, ph, 0);
	}
	else
	{
		ph->y = (p->ypos + (SIZE - dy));
		ph->x = (p->xpos - (((SIZE - dy) / tan(d_to_r(env->r_angle)))));
		dh->y = SIZE;
		dh->x = (-1 / tan(d_to_r(env->r_angle)) * SIZE);
		check_walls(env, ph, 1);
	}
//	printf("H dy = %d \nph x %d, y %d \ndh x %d, y %d\n\n", dy, ph->x, ph->y, dh->x, dh->y), fflush(stdout);

}

void	init_vertical(t_env *env, t_player *p, t_pt *dv, t_pt *pv)
{
	int dx;

	dx = SIZE - (p->xpos % SIZE);
	if (trunc(env->r_angle) == 90 || trunc(env->r_angle) == 270)
	{
		env->vhit = 2;
		return ;
	}
	else if (env->r_angle > 270 || env->r_angle < 90)
	{
		pv->x = (p->xpos + dx);
		pv->y = (p->ypos - (dx * tan(d_to_r(env->r_angle))));
		dv->x = SIZE;
		dv->y = (-tan(d_to_r(env->r_angle)) * SIZE);
		check_walls(env, pv, 2);
	}
	else
	{
		pv->x = (p->xpos - (SIZE - dx));
		pv->y = (p->ypos + ((SIZE - dx) * tan(d_to_r(env->r_angle))));
		dv->x = -SIZE;
		dv->y = (tan(d_to_r(env->r_angle)) * SIZE);
		check_walls(env, pv, 3);
	}
//	printf("V dx = %d \npv x %d, y %d \ndv x %d, y %d\n\n", dx, pv->x, pv->y, dv->x, dv->y), fflush(stdout);

}

void	horizontal_ray(t_env *env, t_pt *ph, t_pt *dh)
{
	ph->x = ph->x + dh->x;
	ph->y = ph->y + dh->y;
	if (env->r_angle > 0 && env->r_angle < 180)
		check_walls(env, ph, 0);
	else
		check_walls(env, ph, 1);
}

void	vertical_ray(t_env *env, t_pt *pv, t_pt *dv)
{
	pv->x = pv->x + dv->x;
	pv->y = pv->y + dv->y;
	if (env->r_angle > 270 || env->r_angle < 90)
		check_walls(env, pv, 2);
	else
		check_walls(env, pv, 3);
}