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

float	d_to_r(float x)
{
	return(PI * x / 180);
}

void	draw_line(t_env *env, float dist)
{
	float p_height;
	int i;

	p_height = (SIZE / dist) * env->sdist;
	i = (env->height / 2) - (p_height / 2);
	////printf("NBD = %d | i = %d, height = %f\n", env->ray_nb, i, p_height), fflush(stdout);
	////printf(" p_dist = %f, p_height = %f\n\n\n", env->p_dist, p_height), fflush(stdout);
	while (i < (env->height / 2) + (p_height /2))
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
	//printf("---\n");
	while (env->hhit != 1)
		horizontal_ray(env, &a, &dh);
	//printf("--------------\n");
	vertical_init(env, p, &b, &dv);
	//printf("---\n");
	while (env->vhit != 1)
		vertical_ray(env, &b, &dv);
	dist = fabsf(p->xpos - a.x / env->cos_t[(int)p->alpha]);
	dist2 = fabsf(p->xpos - b.x / env->cos_t[(int)p->alpha]);
	//printf("dist = %f | %f\n alpha = %f", dist, dist2, p->alpha), fflush(stdout);
	if (dist > dist2)
		draw_line(env, dist2);
	else
		draw_line(env, dist);
	env->vhit = 0;
	env->hhit = 0;
}

void	render(t_env *env)
{
	t_player p;

	p.xpos = 96;
	p.ypos = 224;
	p.alpha = 30;
	p.height = 32;
	env->ray_nb = 0;
	env->p_dist = SIZE / env->sdist;
	//cast_ray(env, &p);
	while(env->ray_nb < env->width)
	{
		//printf("NB %d, alpha = %f\n", env->ray_nb, p.alpha), fflush(stdout);
		cast_ray(env, &p);
		p.alpha += env->rangle;
		env->ray_nb++;
	}
}
