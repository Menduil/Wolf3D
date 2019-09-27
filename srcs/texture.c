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
	SDL_Surface	*surfaceN, *tmps;
	SDL_Texture *textureN;
	SDL_PixelFormat *format;
	Uint32 formatS;
	int pitch;


	format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	tmps = SDL_LoadBMP("texture/brick.bmp");
    if (tmps == NULL)
    {
        fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
        exit(1);
    }
    surfaceN = SDL_ConvertSurfaceFormat(tmps, SDL_PIXELFORMAT_RGBA8888, 0);
    SDL_FreeSurface(tmps);
//    textureN = SDL_CreateTextureFromSurface(env->render, surfaceN);
//	fprintf(stderr, "Sauce %s", SDL_GetError()),fflush(stdout);
//	SDL_LockTexture(textureN, NULL, &tmp, &pitch);
//	pixels = tmp;

//	while (pixels[offset * SIZE + 0])
//	{
//		printf("offset %d, X %d\n", offset, offset * SIZE), fflush(stdout);
//		SDL_GetRGBA(pixels[offset * SIZE + 0], format, &c.r, &c.g, &c.b, &c.a);
//		SDL_SetRenderDrawColor(env->render, c.r, c.g, c.b, c.a);
//		offset++;
//	}
//	printf("(%d, %d, %d, %d)\n", c.r, c.g, c.b, c.a);
//	SDL_UnlockTexture(textureN);
}
