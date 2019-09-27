/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   setup.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/04 15:11:38 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/04 15:11:38 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	angle_table(t_env *env)
{
	int i;

	i = 0;
	while (i <= 360)
	{
		env->cos_t[i] = cos(PI * i / 180);
		i++;
	}
	i = 0;
	while (i <= 360)
	{
		env->sin_t[i] = sin(PI * i / 180);
		i++;
	}
	i = 0;
	while (i <= 360)
	{
		env->tan_t[i] = tan(PI * i / 180);
		i++;
	}
}

void byte_mask(Uint32 *rmask, Uint32 *gmask, Uint32 *bmask, Uint32 *amask)
{
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
    {
        *rmask = 0xff000000;
        *gmask = 0x00ff0000;
        *bmask = 0x0000ff00;
        *amask = 0x000000ff;
    }
    else
    {
       *rmask = 0x000000ff;
       *gmask = 0x0000ff00;
       *bmask = 0x00ff0000;
       *amask = 0xff000000;
    }
}

SDL_Surface *create_surface(int w, int h)
{
    Uint32 rmask;
    Uint32 gmask;
    Uint32 bmask;
    Uint32 amask;
    SDL_Surface *surface;

    byte_mask(&rmask, &gmask, &bmask, &amask);
    surface = SDL_CreateRGBSurface(0, w, h, 32, rmask, gmask, bmask, amask);
    return (surface);
}

void	setup(t_env *env)
{
	env->p.xpos = 222;
    env->p.ypos = 221;
    env->p.alpha = 164;
    env->p.height = 52;
    env->p.speed = 1;
    env->fov = 60;
    env->width = 1200;
    env->height = 1024;
    env->vhit = 0;
    env->hhit = 0;
    env->xmov = 0;
    env->ymov = 0;
//    env->surf = create_surface(env->width, env->height);
	env->sdist = (env->width / 2) / tan(d_to_r(env->fov / 2));
	env->r_inc = (float)env->fov / (float)env->width;
	env->r_angle = 0;
	env->render = SDL_CreateRenderer(env->win, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(env->render, 0, 0, 0, 0);
	SDL_RenderClear(env->render);
	SDL_SetRenderDrawColor(env->render, 0, 255, 0, 255);
	angle_table(env);
}