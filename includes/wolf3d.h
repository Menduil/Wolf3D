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
# include "struct.h"
# include "../libft/libft.h"

# define BUFF_SIZE 5000

void	wolf(t_env *env);
void    	map_line_next(t_map_line *map_line, char *str);
t_map_line	*map_line_new(void);
int			get_next_line(const int fd, char **line);

#endif
