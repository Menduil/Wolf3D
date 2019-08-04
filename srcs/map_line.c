/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_line.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/04 14:01:17 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/04 14:01:17 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_map_line	*map_line_new(void)
{
	t_map_line	*new_map_line;

	if (!(new_map_line = (t_map_line *)malloc(sizeof(t_map_line))))
		return (NULL);
	new_map_line->line = NULL;
	new_map_line->next = NULL;
	return (new_map_line);
}

void    map_line_next(t_map_line *map_line, char *str)
{
	t_map_line		*new_line;
	int				i;

	i = 1;
	new_line = map_line_new();
	while (map_line->next != NULL)
	{
		map_line = map_line->next;
		i++;
	}
	map_line->next = new_line;
	new_line->nbl = i;
	new_line->line = ft_strdup(str);
}
