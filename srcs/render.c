/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/04 12:43:11 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/04 12:43:11 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_line(t_env *env, float dist)
{
	float height;
	int i;

	SDL_SetRenderDrawColor(env->render, 255, 0, 0, 255);
	height = (SIZE / dist) * env->sdist;
	i = (env->height / 2) - (height / 2)
	while (i < (env->height / 2) + (height /2))
	{
		SDL_RenderDrawPoint(env->render, env->ray_nb, i);
		i++;
	}
}

void	cast_ray(t_env *env, t_player *p)
{
	t_pt dh;
	t_pt dv;
	t_pt a;
	t_pt b;
	float dist;
	float dist2;

	horizontal_init(env, p, &a, &dh);
	vertical_init(env, p, &b, &dv);
	while (env->hit != 1)
	{
		horizontal_ray(env, p, &a, &dh)
		vertical_ray(env, p, &b, &dv);
	}
	dist = abs(p.xpos - a.x) / env->cos_t[p->alpha];
	dist2 = abs(p.xpos - b.x) / env->cos_t[p->alpha];
	if (dist > dist2)
		draw_line(env, dist2);
	else
		draw_line(env, dist);
	env->hit = 0;
}

void	render(t_env *env)
{
	t_player p;

	env->ray_nb = 0;
	while(env->ray_nb < env->width)
	{
		cast_ray(env, &p);
		env->ray_nb++;
	}
}
