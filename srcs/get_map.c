/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_map.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/29 17:00:36 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/29 17:00:36 by brey-gal    ###    #+. /#+    ###.fr     */
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

void			fill_one(int *int_line, char *line, int max)
{
	int nbl;
	int i;

	i = 0;
	nbl = get_nb(line);
	while (i < nbl)
		i++;
	while (i < max)
	{
		int_line[i] = 1;
		i++;
	}

}


void    operation(int *i)
{
	i[2] = i[2] + i[1];
	i[1] = 0;
	i[0]++;
}

int             *line_convert(char *line, t_map *map)
{
	int             i[3];
	int             *int_line;
	char 			*tmp;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!(int_line = (int *)malloc(sizeof(int) * map->width + 1)))
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
	fill_one(int_line, line, map->width);
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
		map->map[i] = line_convert(map_line->line, map);
		map_line = map_line->next;
		i++;
	}
	map->map[i] = line_convert(map_line->line, map);
}

void	get_map(char *av, t_map *map)
{
	t_map_line	*map_line;
	char 		*line;
	int			fd;
	int 		tmp;

	if ((fd = open(av, O_RDONLY)) < 0)
		ft_puterror("Error : You picked the wrong map FOOL!!"
			  "   <wrong filename>\n");
	map_line = map_line_new();
	while (get_next_line(fd, &line) > 0)
	{
		map_line_next(map_line, line);
		tmp = get_nb(line);
		if (tmp > map->width)
			map->width = tmp;
		free(line);
	}
	if (map_line->next != NULL)
	{
		map_convert(map_line, map);
		map_line_del(map_line);
		return;
	}
	ft_puterror("Error : The map is a lie   <empty map>\n");
}