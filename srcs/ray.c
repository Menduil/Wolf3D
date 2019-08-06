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

void	check_walls(t_env *env, t_pt *a)
{
	if (map[(int)a->x][(int)a->y] == 1 || map[(int)a->x][(int)a->y - 1] == 1)
		env->hit = 1;
}

void	vertical_init(t_env *env, t_player *p, t_pt *b, t_pt *d)
{
	if (p->alpha < 90 || p->alpha > 270)
	{
		b->x = (int)(p->xpos / SIZE) * SIZE + 64;
		d->x = SIZE;
	}
	else if (p->alpha == 90 || p->alpha == 270)
	{
		b->x = p->xpos;
		d->x = 0;
	}
	else
	{
		b->x = (int)(p->ypos / SIZE) * SIZE - 1;
		d->x = -SIZE;
	}
	b->y = p->ypos + (p->xpos - b->x) * tan(p->alpha);
	d->y = SIZE * tan(p->alpha);
	check_walls(env, b);
}

void	horizontal_init(t_env *env, t_player *p, t_pt *a, t_pt *d)
{
	if (p->alpha < 180)
	{
		a->y = (int)(p->ypos / SIZE) * SIZE + SIZE;
		d->y = -SIZE;
	}
	else if (p->alpha == 0 || p->alpha == 180)
	{
		a->y = p->ypos;
		d->y = 0;
	}
	else
	{
		a->y = (int)(p->ypos / SIZE) * SIZE - 1;
		d->y = SIZE;
	}
	a->x = p->xpos + (p->ypos - a->y) / tan(p->alpha);
	d->x = SIZE / tan(p->alpha);
	check_walls(env, a);
}

void	vertical_ray(t_env *env, t_pt *b, t_pt *d)
{
	b->x += d->x;
	b->y += d->y;
	check_walls(env, b);
}

void	horizontal_ray(t_env *env, t_pt *a, t_pt *d)
{
	a->x += d->x;
	a->y += d->y;
	check_walls(env, a);
}