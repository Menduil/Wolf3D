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

void    draw_sky(t_env *env, int x, int p_height)
{
    int i;
    SDL_Color   c;

    i = 0;
    c.r = 135;
    c.g = 206;
    c.b = 235;
    while (i < (env->height - p_height) / 2)
    {
        put_pixel(env->surf, x, i, SDL_MapRGB(env->surf->format, c.r, c.g, c.b));
        i++;
    }
}

void    draw_floor(t_env *env, int x, int y)
{
    SDL_Color c;

    c.r = 128;
    c.g = 128;
    c.b = 128;
    while (y < env->height)
    {
        put_pixel(env->surf, x, y, SDL_MapRGB(env->surf->format, c.r, c.g, c.b));
        y++;
    }
}

void	draw_line(t_env *env, int y, int x, int p_height, int offset)
{
    SDL_Color c;
    int i;
    float pas;
    float yp;
    int ypd;

    pas = SIZE / (float)p_height;
    i = 0;
    yp = 1;
    ypd = 0;

    draw_sky(env, x, p_height);
    while (i < p_height)
    {
        if (x >= 0 && y >= 0 && x < env->width && y < env->height)
        {
            if (ypd != trunc(yp))
            {
                SDL_GetRGB(get_pixel(env->text, offset, trunc(yp)), env->surf->format, &c.r, &c.g, &c.b);
                ypd = trunc(yp);
            }
            put_pixel(env->surf, x, y, SDL_MapRGB(env->surf->format, c.r, c.g, c.b));
        }
        if (yp < 64 - pas)
            yp += pas;
        y++;
        i++;
    }
    draw_floor(env, x, y);
}
