/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/29 16:13:01 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/29 16:13:01 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_sky(t_env *env, int x, int p_height)
{
	int			i;
	SDL_Color	c;

	i = 0;
	c.r = 135;
	c.g = 206;
	c.b = 235;
	while (i < (env->height - p_height) / 2)
	{
		put_pixel(env->surf, x, i,
				SDL_MapRGB(env->surf->format, c.r, c.g, c.b));
		i++;
	}
}

void	draw_floor(t_env *env, int x, int y)
{
	SDL_Color	c;

	c.r = 128;
	c.g = 128;
	c.b = 128;
	while (y < env->height)
	{
		put_pixel(env->surf, x, y,
				SDL_MapRGB(env->surf->format, c.r, c.g, c.b));
		y++;
	}
}

void	pixel_set(t_env *env, t_draw *d, int offset, t_pt *col)
{
	if (d->ypd != trunc(d->yp))
	{
		SDL_GetRGB(get_pixel(env->text, offset, trunc(d->yp)),
				env->surf->format, &d->c.r, &d->c.g, &d->c.b);
		d->ypd = trunc(d->yp);
	}
	put_pixel(env->surf, col->x, col->y,
			SDL_MapRGB(env->surf->format, d->c.r, d->c.g, d->c.b));
}

void	draw_line(t_env *env, t_pt *col, int p_height, int offset)
{
	t_draw		d;
	int			i;

	i = 0;
	d.pas = SIZE / (float)p_height;
	d.yp = 1;
	d.ypd = 0;
	draw_sky(env, col->x, p_height);
	while (i < p_height)
	{
		if (col->x >= 0 && col->y >= 0
		&& col->x < env->width && col->y < env->height)
		{
			pixel_set(env, &d, offset, col);
		}
		if (d.yp < 64 - d.pas)
			d.yp += d.pas;
		col->y++;
		i++;
	}
	draw_floor(env, col->x, col->y);
}
