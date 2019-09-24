/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   collision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:28:29 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 14:28:29 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_ptint	convert(t_pt *a)
{
	t_ptint b;

	b.x = (int)floor(a->x / SIZE);
	b.y = (int)floor(a->y / SIZE);
	return (b);

}

void	check_walls(t_env *env, t_pt *a, int type)
{
	t_ptint b;

//	printf("Type = %d\n", type), fflush(stdout);
//	printf("a = %f / %f\n", a->x, a->y), fflush(stdout);
	b = convert(a);
//	printf("b = %d / %d\n\n", b.x, b.y), fflush(stdout);
	if (b.x < 0 || b.y < 0
		|| b.x > 7 || b.y > 11)
	{
		if (type < 2)
			env->hhit = -1;
		else
			env->vhit = -1;
	}
	else if (type < 2)
	{
		if (type == 0)
		{
			if (env->map.map[b.y - 1][b.x] == 1)
				env->hhit = 1;
		}
		else
		{
			if (env->map.map[b.y][b.x] == 1)
				env->hhit = 1;
		}
	}
	else
	{
		if (type == 2)
		{
			if (env->map.map[b.y][b.x] == 1)
				env->vhit = 1;
		}
		else
		{
			if (env->map.map[b.y][b.x - 1] == 1)
				env->vhit = 1;
		}
	}
}