/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/02 12:56:58 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/02 12:56:58 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wolf(t_env *env)
{
	while (!env->quit)
	{
		while (SDL_PollEvent(&env->e) != 0)
		{
			if (env->e.type == SDL_QUIT || env->e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				env->quit = 1;
			if (env->e.key.keysym.scancode == SDL_SCANCODE_A)
				env->turn = 1;
			if (env->e.key.keysym.scancode == SDL_SCANCODE_D)
				env->turn = -1;
		}
	}
}