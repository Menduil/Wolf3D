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
# include "struct.h"
# include "../libft/libft.h"
# define SIZE 64
# define BUFF_SIZE 5000

void		wolf(t_env *env);
void		render(t_env *env);
void		setup(t_env *env);
void		vertical_ray(t_env *env, t_pt *b, t_pt *d);
void		horizontal_ray(t_env *env, t_pt *a, t_pt *d);
void		vertical_init(t_env *env, t_player *p, t_pt *b, t_pt *d);
void		horizontal_init(t_env *env, t_player *p, t_pt *b, t_pt *d);
void    	map_line_next(t_map_line *map_line, char *str);
t_map_line	*map_line_new(void);
int			get_next_line(const int fd, char **line);

#endif
