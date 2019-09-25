/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   texture.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/25 14:02:30 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/25 14:02:30 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	texture(t_env *env)
{
	void *tmp;
	SDL_Surface	*surfaceN;
	SDL_Texture *textureN;
	Uint32 *pixels;
	int pitch;
	int x;
	int y;
	SDL_Color c;
	SDL_PixelFormat *format;

	format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	surfaceN = SDL_LoadBMP("../texture/brick.bmp");
	textureN = SDL_CreateTextureFromSurface(env->render, surfaceN);
	SDL_LockTexture(textureN, NULL, &tmp, &pitch);
	pixels = tmp;
	x = 0;
	while(x < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			SDL_GetRGBA(pixels[x * SIZE + y], format, &c.r, &c.g, &c.b, &c.a);
//			printf("(%d, %d, %d, %d)", c.r, c.g, c.b, c.a);
			y++;
		}
		x++;
	}
	SDL_UnlockTexture(textureN);
}