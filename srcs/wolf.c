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

void	display(t_env *env)
{
	SDL_SetRenderDrawColor(env->render, 0, 0, 0, 0);
	SDL_RenderClear(env->render);
	SDL_SetRenderDrawColor(env->render, 0, 255, 0, 255);
	render(env, &env->p);
	SDL_RenderPresent(env->render);
}

void	wolf(t_env *env)
{
	display(env);
	while (!env->quit)
	{
		const Uint8 *keystates = SDL_GetKeyboardState(NULL);
		while (SDL_PollEvent(&env->e) != 0)
		{
			if (env->quit == 1)
				break;
			control(env, keystates);
			display(env);
		}
	}
}