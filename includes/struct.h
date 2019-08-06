/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 16:32:52 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 16:32:52 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF_3D_STRUCT_H
# define WOLF_3D_STRUCT_H

typedef struct	s_pt
{
	int	x;
	int	y;
}				t_pt;

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

typedef	struct	s_player
{
	int		height;
	int		xpos;
	int		ypos;
	float	alpha;
}				t_player;

typedef struct s_env
{
	int				width;
	int				height;
	SDL_Window		*win;
	SDL_Event		e;
	SDL_Renderer	*render;
	t_map			map;
	int				quit;
	int				fov;
	float			sdist;
	int				hit;
	float			rangle;
	int				cos_t[360];
	int				sin_t[360];
	int				ray_nb;
}				t_env;

#endif
