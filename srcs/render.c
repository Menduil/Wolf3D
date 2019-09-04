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

float	d_to_r(float x)
{
	return(PI * x / 180);
}

void	draw_slice(t_env *env, float dist)
{
	int p_height;
	int i;

	p_height = SIZE / dist * env->sdist;
	i = (env->height / 2) - (p_height / 2);
	while (i < (env->height / 2) + (p_height / 2))
	{
		SDL_RenderDrawPoint(env->render, env->ray_nb, i);
		i++;
	}

}

void	calc_dist(t_env *env, t_player *p, t_pt *ph, t_pt *pv)
{
	float	disth;
	float	distv;

	disth = abs(p->xpos - ph->x) * env->cos_t[(int)(d_to_r(p->alpha))]
			+ abs(p->ypos - ph->y) * env->sin_t[(int)(d_to_r(p->alpha))];
	distv = abs(p->xpos - pv->x) * env->cos_t[(int)(d_to_r(p->alpha))]
			+ abs(p->ypos - pv->y) * env->sin_t[(int)(d_to_r(p->alpha))];
//	if (disth > distv)
//		draw_slice(env, distv);
//	else
//		draw_slice(env, disth);
	draw_slice(env, disth);
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
	env->r_angle = p->alpha - (env->fov / 2);
	env->ray_nb = 0;
	env->p_dist = SIZE / env->sdist;
//	cast_ray(env, p);
	while(env->ray_nb < env->width)
	{
		printf("NB %d, alpha = %f\n", env->ray_nb, p->alpha), fflush(stdout);
		cast_ray(env, p);
		env->r_angle += env->r_inc;
		env->ray_nb++;
	}
}