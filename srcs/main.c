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

//void	get_map(char *av)
//{
//
//}

void	init(t_env *env)
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("ERREUR : Init SDL > %s\n", SDL_GetError());
		exit(0);
	}
	if ((env->win = SDL_CreateWindow("Wolf3d",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			800, 600, SDL_WINDOW_RESIZABLE)) == NULL)
	{
		SDL_Log("ERREUR : Creation fenetre echouee > %s\n", SDL_GetError());
		exit(0);
	}
	env->quit = 0;
}

int		main(int ac, char **av)
{
	t_env	env;

	ac = 0;
	(void)av;
//	if (ac == 2)
//		get_map(avp[1]);
	init(&env);
	wolf(&env);
	SDL_DestroyWindow(env.win);
	SDL_Quit();
	return (0);
}