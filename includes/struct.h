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

typedef struct  s_pt
{
	float		x;
	float		y;
}				t_pt;

typedef struct  s_ptint
{
	int         x;
	int         y;
}				t_ptint;

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
	int		alpha;
	int		speed;
}				t_player;

typedef struct s_env
{
	t_player		p;
	int				width;
	int				height;
	SDL_Window		*win;
	SDL_Event		e;
	SDL_Renderer	*render;
	SDL_Texture		*texture;
	SDL_Surface     *surf;
    SDL_Surface     *textN;
    SDL_Surface     *textS;
    SDL_Surface     *textE;
    SDL_Surface     *textW;
    SDL_Surface     *text;
    SDL_Rect		*rect;
	t_map			map;
	int				quit;
	int				xmov;
	int				ymov;
	int				fov;
	float			sdist;
	int				vhit;
	int				hhit;
	float			r_angle;
	float			r_inc;
	float			cos_t[360];
	float			sin_t[360];
	float			tan_t[360];
	int				ray_nb;
	float			p_dist;
}				t_env;

#endif
