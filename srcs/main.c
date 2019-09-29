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

void	set_spawn(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->map.height)
	{
		x = 0;
		while (x < env->map.width)
		{
			if (env->map.map[y][x] == 3)
			{
				env->p.xpos = x * 64;
				env->p.ypos = y * 64;
				break;
			}
			x++;
		}
		y++;
	}
}

void	init(t_env *env)
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("ERREUR : Init SDL > %s\n", SDL_GetError());
		exit(0);
	}
	if ((env->win = SDL_CreateWindow("Wolf3d",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			1200, 1024, SDL_WINDOW_RESIZABLE)) == NULL)
	{
		SDL_Log("ERREUR : Creation fenetre echouee > %s\n", SDL_GetError());
		exit(0);
	}
	set_spawn(env);
	setup(env);
	env->quit = 0;
}

int		main(int ac, char **av)
{
	t_env	env;

	env.map.width = 0;
	if (ac == 2)
		get_map(av[1], &env.map);
	else
		get_map("test.map", &env.map);
	init(&env);
	wolf(&env);
	SDL_FreeSurface(env.surf);
	free(env.rect);
	SDL_DestroyRenderer(env.render);
	SDL_DestroyWindow(env.win);
	SDL_Quit();
	return (0);
}