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

typedef struct		s_pt
{
	float			x;
	float			y;
}					t_pt;

typedef	struct		s_draw
{
	float			pas;
	float			yp;
	int				ypd;
	SDL_Color		c;
}					t_draw;

typedef struct		s_ptint
{
	int				x;
	int				y;
}					t_ptint;

typedef struct		s_map_line
{
	int				nbl;
	char			*line;
	void			*next;
}					t_map_line;

typedef struct		s_map
{
	int				**map;
	int				width;
	int				height;
}					t_map;

typedef	struct		s_player
{
	int				xpos;
	int				ypos;
	int				alpha;
	int				speed;
}					t_player;

typedef struct		s_env
{
	t_player		p;
	SDL_Window		*win;
	SDL_Event		e;
	SDL_Renderer	*render;
	SDL_Texture		*texture;
	SDL_Surface		*surf;
	SDL_Surface		*text_n;
	SDL_Surface		*text_s;
	SDL_Surface		*text_e;
	SDL_Surface		*text_w;
	SDL_Surface		*text;
	SDL_Rect		*rect;
	t_map			map;
	int				width;
	int				height;
	int				quit;
	int				xmov;
	int				ymov;
	int				fov;
	int				vhit;
	int				hhit;
	int				ray_nb;
	float			sdist;
	float			r_angle;
	float			r_inc;
	float			cos_t[360];
	float			sin_t[360];
	float			tan_t[360];
	float			p_dist;
}					t_env;

#endif
