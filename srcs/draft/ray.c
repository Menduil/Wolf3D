/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 14:58:55 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 14:58:55 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	check_walls(t_env *env, t_pt *a, int type)
{
	if (type == 0)
	{
		//printf("a.x = %d / %d\n", a->x, (int)(a->x / SIZE)), fflush(stdout);
		//printf("a.y = %d / %d\n", a->y, (int)(a->y / SIZE)), fflush(stdout);
		if (env->map.map[(int)(a->x / SIZE)][(int)(a->y / SIZE)] == 1 ||
			(int)(a->x / SIZE) < 0 || (int)(a->y / SIZE) < 0)
			env->hhit = 1;
	}
	else
	{
		//printf("b.x = %d / %d\n", a->x, (int)(a->x / SIZE)), fflush(stdout);
		//printf("b.y = %d / %d\n", a->y, (int)(a->y / SIZE)), fflush(stdout);
		if (env->map.map[(int)(a->x / SIZE)][(int)(a->y / SIZE)] == 1 ||
		(int)(a->x / SIZE) < 0 || (int)(a->y / SIZE) < 0)
			env->vhit = 1;
	}
}

void	horizontal_init(t_env *env, t_player *p, t_pt *a, t_pt *d)
{
	if (p->alpha > 180)
	{
		a->y = trunc((int)(p->ypos / SIZE) * SIZE + SIZE);
		d->y = SIZE;
	}
	else if (p->alpha == 0 || p->alpha == 180)
	{
		a->y = p->ypos;
		d->y = 0;
	}
	else
	{
		a->y = trunc((int)(p->ypos / SIZE) * SIZE - 1);
		d->y = -SIZE;
	}
	a->x = trunc(p->xpos + (p->ypos - a->y) / tan(d_to_r(p->alpha)));
	d->x = trunc(-d->y / tan(d_to_r(p->alpha)));
	//printf("d.x = %d\n", d->x), fflush(stdout);
	//printf("d.y = %d, tan = %f\n", d->y, tan(d_to_r(p->alpha))), fflush(stdout);
	check_walls(env, a, 0);
}

void	vertical_init(t_env *env, t_player *p, t_pt *b, t_pt *d)
{
	if (p->alpha < 90 || p->alpha > 270)
	{
		b->x = trunc((int)(p->xpos / SIZE) * SIZE + SIZE);
		d->x = SIZE;
	}
	else if (p->alpha == 90 || p->alpha == 270)
	{
		b->x = p->xpos;
		d->x = 0;
	}
	else
	{
		b->x = trunc((int)(p->ypos / SIZE) * SIZE - 1);
		d->x = -SIZE;
	}
	b->y = trunc(p->ypos + (p->xpos - b->x) * tan(d_to_r(p->alpha)));
	d->y = trunc(-d->x * tan(d_to_r(p->alpha)));
	//printf("d.x = %d\n", d->x), fflush(stdout);
	//printf("d.y = %d, tan = %f\n", d->y, tan(d_to_r(p->alpha))), fflush(stdout);
	check_walls(env, b, 1);
}

void	horizontal_ray(t_env *env, t_pt *a, t_pt *d)
{
	a->x = a->x + d->x;
	a->y = a->y + d->y;
	check_walls(env, a, 0);
}

void	vertical_ray(t_env *env, t_pt *b, t_pt *d)
{
	b->x = b->x + d->x;
	b->y = b->y + d->y;
	check_walls(env, b, 1);
}
