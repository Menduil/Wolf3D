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

void	texture(t_env *env, int offset, int j)
{
	void *tmp;
	SDL_Color c;
	Uint32 *pixels;
	SDL_Surface	*surfaceN;
	SDL_Texture *textureN;
	SDL_PixelFormat *format;
	int pitch;


	format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	surfaceN = SDL_LoadBMP("../texture/brick.bmp");
	textureN = SDL_CreateTextureFromSurface(env->render, surfaceN);
	SDL_LockTexture(textureN, NULL, &tmp, &pitch);
	pixels = tmp;
//	SDL_GetRGBA(pixels[offset * SIZE + 0], format, &c.r, &c.g, &c.b, &c.a);
//	SDL_SetRenderDrawColor(env->render, c.r, c.g, c.b, c.a);
//	printf("(%d, %d, %d, %d)\n", c.r, c.g, c.b, c.a);
	SDL_UnlockTexture(textureN);
}