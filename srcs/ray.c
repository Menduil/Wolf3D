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

void	check_walls(t_env *env, t_pt *a, int type)
{
	if (type == 0)
	{
		printf("a.x = %d / %d\n", a->x, (int)(a->x / SIZE)), fflush(stdout);
		printf("a.y = %d / %d\n", a->y, (int)(a->y / SIZE)), fflush(stdout);
		if (env->map.map[(int)(a->x / SIZE)][(int)(a->y / SIZE)] == 1 ||
			(int)(a->x / SIZE) < 0 || (int)(a->y / SIZE) < 0)
			env->hhit = 1;
	}
	else
	{
		printf("b.x = %d / %d\n", a->x, (int)(a->x / SIZE)), fflush(stdout);
		printf("b.y = %d / %d\n", a->y, (int)(a->y / SIZE)), fflush(stdout);
		if (env->map.map[(int)(a->x / SIZE)][(int)(a->y / SIZE)] == 1 ||
			(int)(a->x / SIZE) < 0 || (int)(a->y / SIZE) < 0)
			env->vhit = 1;
	}
}

void	init_horizontal(t_env *env, t_player *p, t_pt *dh, t_pt *ph)
{
	int dy;

	dy = p->ypos % SIZE;
	if (env->r_angle > 0 && env->r_angle < 180)
	{
		ph->y = round(p->ypos - dy);
		ph->x = round(p->xpos + (dy / tan(d_to_r(env->r_angle))));
		dh->y = -SIZE;
		dh->x = round(1 / tan(d_to_r(45)) * SIZE);
	}
	else if (env->r_angle == 0 || env->r_angle == 180)
	{
		env->hhit = 2;
		return ;
	}
	else
	{
		ph->y = round(p->ypos + (SIZE - dy));
		ph->x = round(p->xpos - ((SIZE - dy) / tan(d_to_r(env->r_angle))));
		dh->y = SIZE;
		dh->x = round(-1 / tan(d_to_r(env->r_angle)) * SIZE);
	}
	printf("dy = %d \nph x %d, y %d \ndh x %d, y %d\n", dy, ph->x, ph->y, dh->x, dh->y), fflush(stdout);
	check_walls(env, ph, 0);

}

void	init_vertical(t_env *env, t_player *p, t_pt *dv, t_pt *pv)
{
	int dx;

	dx = SIZE - (p->xpos % SIZE);
	if (env->r_angle > 270 || env->r_angle < 90)
	{
		pv->x = round(p->xpos + dx);
		pv->y = round(p->ypos - (dx * tan(d_to_r(env->r_angle))));
		dv->x = SIZE;
		dv->y = round(-tan(d_to_r(env->r_angle)) * SIZE);
	}
	else if (env->r_angle == 0 || env->r_angle == 180)
	{
		env->vhit = 2;
		return ;
	}
	else
	{
		pv->x = round(p->xpos - (SIZE - dx));
		pv->y = round(p->ypos + (dx * tan(d_to_r(env->r_angle))));
		dv->y = round(tan(d_to_r(env->r_angle)) * SIZE);
		dv->x = -SIZE;
	}
	check_walls(env, pv, 1);
	printf("dx = %d \npv x %d, y %d \ndv x %d, y %d\n", dx, pv->x, pv->y, dv->x, dv->y), fflush(stdout);
}

void	horizontal_ray(t_env *env, t_pt *ph, t_pt *dh)
{
	ph->x = ph->x + dh->x;
	ph->y = ph->y + dh->y;
	check_walls(env, ph, 0);
}

void	vertical_ray(t_env *env, t_pt *pv, t_pt *dv)
{
	pv->x = pv->x + dv->x;
	pv->y = pv->y + dv->y;
	check_walls(env, pv, 1);
}