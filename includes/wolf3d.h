/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/01 03:28:19 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/01 03:28:19 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF3D_H
# define WOLF3D_WOLF3D_H

# include <unistd.h>
# include "sdl2/SDL.h"
# include "../libft/libft.h"

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

void	wolf(t_env *env);

#endif
