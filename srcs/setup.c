/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   setup.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/04 15:11:38 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/04 15:11:38 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

float	d_to_r(float x)
{
	return(PI * x / 180);
}

void	angle_table(t_env *env)
{
	int i;

	i = 0;
	while (i <= 360)
	{
		env->cos_t[i] = cos(PI * i / 180);
		i++;
	}
	i = 0;
	while (i <= 360)
	{
		env->sin_t[i] = sin(PI * i / 180);
		i++;
	}
	i = 0;
	while (i <= 360)
	{
		env->tan_t[i] = tan(PI * i / 180);
		i++;
	}
}

void	setup(t_env *env)
{
	t_player p;

	env->p.xpos = 222;
	env->p.ypos = 221;
	env->p.alpha = 164;
	env->lastc = 0;
	env->p.height = 52;
	env->p.speed = 5;
	env->fov = 60;
	env->width = 1200;
	env->height = 1024;
	env->vhit = 0;
	env->hhit = 0;
	env->turn = 0;
	env->xmov = 0;
	env->ymov = 0;
	env->walk = 0;
	env->sdist = (env->width / 2) / tan(d_to_r(env->fov / 2));
	env->r_inc = (float)env->fov / (float)env->width;
	env->r_angle = 0;
	env->render = SDL_CreateRenderer(env->win, -1, 0);
	SDL_SetRenderDrawColor(env->render, 0, 0, 0, 0);
	SDL_RenderClear(env->render);
	SDL_SetRenderDrawColor(env->render, 0, 255, 0, 255);
	angle_table(env);
}