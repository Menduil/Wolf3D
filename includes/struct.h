/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/04 13:56:01 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/04 13:56:01 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_STRUCT_H
# define WOLF3D_STRUCT_H

# include "sdl2/SDL.h"

typedef struct  s_map_line
{
	int		nbl;
	char	*line;
	void	*next;
}				t_map_line;

typedef struct  s_map
{
	int		**map;
	int		width;
	int		height;
}				t_map;

typedef struct s_env
{
	SDL_Window *win;
	SDL_Event	e;
	t_map		map;
	int			quit;
}				t_env;

#endif
