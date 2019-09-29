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
# include <fcntl.h>
# include <math.h>
# include "sdl2/SDL.h"
# include <stdio.h>
# include "struct.h"
# include "../libft/libft.h"
# define SIZE 64
# define BUFF_SIZE 5000
# define PI 3.14159265359
# define CYAN 0xFFFFFF00

void		wolf(t_env *env);
void		render(t_env *env, t_player *p);
void		setup(t_env *env);
void		vertical_ray(t_env *env, t_pt *pv, t_pt *dv);
void		horizontal_ray(t_env *env, t_pt *ph, t_pt *dh);
void		init_vertical(t_env *env, t_player *p, t_pt *dv, t_pt *pv);
void		init_horizontal(t_env *env, t_player *p, t_pt *dh, t_pt *ph);
void		map_line_next(t_map_line *map_line, char *str);
t_map_line	*map_line_new(void);
int			get_next_line(const int fd, char **line);
float		d_to_r(float x);
void		check_walls(t_env *env, t_pt *a, int type);
void		control(t_env *env, const Uint8 *keystates);
float		angle_adjust(float angle);
void		map_line_del(t_map_line *map_line);
void		put_pixel(SDL_Surface *surf, int x, int y, int color);
SDL_Surface *create_surface(int w, int h);
SDL_Surface *load_texture(t_env *env, char *path);
Uint32		get_pixel(SDL_Surface *surface, int x, int y);
void		draw_line(t_env *env, t_pt *col, int p_height, int offset);
void		get_map(char *av, t_map *map);
void		fill_one(int *int_line, char *line, int max);

#endif
