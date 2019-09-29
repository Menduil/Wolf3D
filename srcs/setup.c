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

void	setup(t_env *env)
{
	env->p.xpos = 222;
    env->p.ypos = 221;
    env->p.alpha = 164;
    env->p.height = 52;
    env->p.speed = 1;
    env->fov = 60;
    env->vhit = 0;
    env->width = 1200;
    env->height = 1024;
    env->hhit = 0;
    env->xmov = 0;
    env->ymov = 0;
    env->rect = malloc(sizeof(SDL_Rect));
    env->rect->x = 0;
	env->rect->y = 0;
    SDL_GetWindowSize(env->win, &env->rect->w, &env->rect->h);
    env->surf = create_surface(env->rect->w, env->rect->h);
	env->sdist = (env->width / 2) / tan(d_to_r(env->fov / 2));
	env->r_inc = (float)env->fov / (float)env->width;
	env->r_angle = 0;
	env->textN = load_texture(env, "texture/stonemold.bmp");
	env->textS = load_texture(env, "texture/bluegrey.bmp");
	env->textE = load_texture(env, "texture/brick.bmp");
	env->textW = load_texture(env, "texture/woodbrick.bmp");
	env->render = SDL_CreateRenderer(env->win, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(env->render, 0, 0, 0, 255);
	angle_table(env);
	SDL_SetRelativeMouseMode(SDL_TRUE);
}