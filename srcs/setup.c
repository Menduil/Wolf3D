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

void	texture_load(t_env *env)
{
	env->text_n = load_texture(env, "texture/stonemold.bmp");
	env->text_s = load_texture(env, "texture/bluegrey.bmp");
	env->text_e = load_texture(env, "texture/steelwall.bmp");
	env->text_w = load_texture(env, "texture/woodbrick.bmp");
}

void	setup(t_env *env)
{
	env->p.alpha = 164;
	env->p.speed = 1;
	env->fov = 60;
	env->vhit = 0;
	env->width = WIDTH;
	env->height = HEIGHT;
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
	env->render = SDL_CreateRenderer(env->win, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(env->render, 0, 0, 0, 255);
	angle_table(env);
	texture_load(env);
	SDL_SetRelativeMouseMode(SDL_TRUE);
}
