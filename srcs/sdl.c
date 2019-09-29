/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sdl.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/27 19:02:06 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/27 19:02:06 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

SDL_Surface	*load_texture(t_env *env, char *path)
{
	SDL_Surface *tmp;
	SDL_Surface *surface;

	tmp = SDL_LoadBMP(path);
	if (tmp == NULL)
	{
		ft_puterror("Erreur de chargement de texture");
		exit(1);
	}
	surface = SDL_ConvertSurfaceFormat(tmp, env->surf->format->format, 0);
	SDL_FreeSurface(tmp);
	return (surface);
}

Uint32		get_pixel(SDL_Surface *surface, int x, int y)
{
	int		bpp;
	Uint8	*p;

	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	if (bpp == 2)
		return (*(Uint16 *)p);
	if (bpp == 4)
		return (*(Uint32 *)p);
	return (0);
}

void		put_pixel(SDL_Surface *surf, int x, int y, int color)
{
	Uint32 *pixels;

	pixels = (Uint32 *)surf->pixels;
	if (x >= 0 && y >= 0 && x < surf->w && y < surf->h)
		pixels[y * surf->w + x] = color;
}

SDL_Surface	*create_surface(int w, int h)
{
	Uint32		rmask;
	Uint32		gmask;
	Uint32		bmask;
	Uint32		amask;
	SDL_Surface	*surface;

	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = 0xff000000;
	surface = SDL_CreateRGBSurface(0, w, h, 32, rmask, gmask, bmask, amask);
	return (surface);
}
