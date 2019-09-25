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

void	opti(t_env *env)
{
	SDL_SetRenderDrawColor(env->render, 0, 0, 0, 0);
	SDL_RenderClear(env->render);
	render(env, &env->p);
	SDL_RenderPresent(env->render);
}

void	wolf(t_env *env)
{
	opti(env);
	while (!env->quit)
	{
		const Uint8 *keystates = SDL_GetKeyboardState(NULL);
		while (SDL_PollEvent(&env->e) != 0 || env->e.key.repeat != 0)
		{
			if (env->e.type == SDL_QUIT || keystates[SDL_SCANCODE_ESCAPE])
				env->quit = 1;
			if (keystates[SDL_SCANCODE_A])
				env->turn = 1;
			else if (keystates[SDL_SCANCODE_D])
				env->turn = -1;
			else
				env->turn = 0;
			if (keystates[SDL_SCANCODE_W])
				env->walk = 1;
			else if (keystates[SDL_SCANCODE_S])
				env->walk = -1;
			else
				env->walk = 0;
			if (env->turn != 0 || env->walk != 0)
				opti(env);
		}
	}
}