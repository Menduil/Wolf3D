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

void	angle_table(t_env *env)
{
	int i;

	i = 0;
	while (i < 360)
	{
		env->sin_t[i] = sin(i);
		env->cos_t[i] = cos(i);
		i++;
	}
}

void	setup(t_env *env);
{
	env->fov = 60;
	env->width = 800;
	env->height = 600;
	env->hit = 0;
	env->sdist = (env->width / 2) / tan(env->fov / 2);
	env->rangle = env->fov / env->width;
	env->render = SDL_CreateRenderer(env->win, -1, 0);
	angle_table(env);
}