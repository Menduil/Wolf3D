/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_one.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/29 19:29:19 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 14:08:10 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
		int_line[i] = 0;
		i++;
	}
}
