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

int             get_nb(char *line)
{
	int i;
	int nb;
	int space;

	i = 0;
	nb = 0;
	space = 0;
	while (line[i])
	{
		if (line[i] != ' ' && space == 0)
		{
			nb++;
			space = 1;
		}
		if (line[i] == ' ' && space == 1)
			space = 0;
		i++;
	}
	return (nb);
}

void    operation(int *i)
{
	i[2] = i[2] + i[1];
	i[1] = 0;
	i[0]++;
}

int             *line_convert(char *line)
{
	int             i[3];
	int             *int_line;
	char 			*tmp;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!(int_line = (int *)malloc(sizeof(int) * get_nb(line) + 1)))
		return (0);
	while (i[0] < get_nb(line))
	{
		while (line[i[2]] == ' ')
			i[2]++;
		while ((line[i[1] + i[2]] >= '0' && line[i[1] + i[2]] <= '9')
			   || line[i[1] + i[2]] == '-' || line[i[1] + i[2]] == '+')
			i[1]++;
		tmp = ft_strsub(line, i[2], i[1]);
		int_line[i[0]] = ft_atoi(tmp);
		free(tmp);
		operation(i);
	}
	return (int_line);
}


void	map_convert(t_map_line *map_line, t_map *map)
{
	t_map_line		*nb_line;
	int				i;

	nb_line = map_line;
	while (nb_line->next != NULL)
		nb_line = nb_line->next;
	if (!(map->map = (int **)malloc(sizeof(int *) * nb_line->nbl)))
		exit(1);
	map->height = nb_line->nbl;
	i = 0;
	map_line = map_line->next;
	while (map_line->next != NULL)
	{
		map->map[i] = line_convert(map_line->line);
		map_line = map_line->next;
		i++;
	}
	map->width = get_nb(map_line->line);
	map->map[i] = line_convert(map_line->line);

}

void	get_map(char *av, t_map *map)
{
	t_map_line	*map_line;
	char 		*line;
	int			fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		exit(1);
	map_line = map_line_new();
	while (get_next_line(fd, &line) > 0)
	{
		map_line_next(map_line, line);
		free(line);
	}
	map_convert(map_line, map);
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
			1000, 1000, SDL_WINDOW_RESIZABLE)) == NULL)
	{
		SDL_Log("ERREUR : Creation fenetre echouee > %s\n", SDL_GetError());
		exit(0);
	}
	setup(env);
	env->quit = 0;
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
		get_map(av[1], &env.map);
	init(&env);
	render(&env, &env.p);
	SDL_RenderPresent(env.render);
	wolf(&env);
	SDL_DestroyRenderer(env.render);
	SDL_DestroyWindow(env.win);
	SDL_Quit();
	return (0);
}