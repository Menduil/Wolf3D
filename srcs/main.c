/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/01 03:29:34 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/01 03:29:34 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

#include <stdio.h>

int	main()
{
	SDL_Window	*window;
	SDL_Surface	*screenSurface;
	int is_running = 1;
	SDL_Event event;
	t_env env;
	env.height = 1000;
	env.width = 1000;
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("ERREUR : Init SDL > %s\n", SDL_GetError());
		exit(0);
	}
	if ((window = SDL_CreateWindow("Wolf3d",
			0, 0, env.width, env.height, SDL_WINDOW_RESIZABLE)) == NULL)
	{
		SDL_Log("ERREUR : Creation fenetre echouee > %s\n", SDL_GetError());
		exit(0);
	}
	while (is_running == 1) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				is_running = 0;
			}
		}
		wolf3d(&env);
		SDL_Delay(16);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}