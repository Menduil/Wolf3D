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
	render(env, &env->p);
	SDL_DestroyTexture(env->texture);
	SDL_RenderClear(env->render);
	env->texture = SDL_CreateTextureFromSurface(env->render, env->surf);
	SDL_RenderCopy(env->render, env->texture, NULL, env->rect);
	SDL_RenderPresent(env->render);
	SDL_FillRect(env->surf,NULL,SDL_MapRGB(env->surf->format, 0, 0, 0));
}

void	wolf(t_env *env)
{
	const Uint8	*keystates;
	display(env);
	while (!env->quit)
	{
		while (SDL_PollEvent(&env->e) != 0 || env->e.key.repeat == 0)
		{
			keystates = SDL_GetKeyboardState(NULL);
			if (env->quit == 1)
				break;
			control(env, keystates);
			display(env);
		}
		usleep(200);
	}
}