/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   control.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/24 15:28:05 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/24 15:28:05 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	strafe(t_env *env, const Uint8 *keystates)
{
	int alpha_s;
	alpha_s = angle_adjust(env->p.alpha + 90);
	if (keystates[SDL_SCANCODE_Q])
	{
		env->p.xpos += round(env->cos_t[alpha_s] * (env->p.speed / 2));
		env->p.ypos -= round(env->sin_t[alpha_s] * (env->p.speed / 2));
	}
	else if (keystates[SDL_SCANCODE_E])
	{
		env->p.xpos -= round(env->cos_t[alpha_s] * (env->p.speed / 2));
		env->p.ypos += round(env->sin_t[alpha_s] * (env->p.speed / 2));
	}
}

void	control(t_env *env, const Uint8 *keystates)
{
	if (env->e.type == SDL_QUIT || keystates[SDL_SCANCODE_ESCAPE])
		env->quit = 1;
	if (keystates[SDL_SCANCODE_A])
		env->p.alpha += 2;
	else if (keystates[SDL_SCANCODE_D])
		env->p.alpha -= 2;
	env->p.alpha = angle_adjust(env->p.alpha);
	if (keystates[SDL_SCANCODE_W])
	{
		env->p.xpos += round(env->cos_t[env->p.alpha] * env->p.speed);
		env->p.ypos -= round(env->sin_t[env->p.alpha] * env->p.speed);
	}
	else if (keystates[SDL_SCANCODE_S])
	{
		env->p.xpos -= round(env->cos_t[env->p.alpha] * env->p.speed);
		env->p.ypos += round(env->sin_t[env->p.alpha] * env->p.speed);
	}
	if (keystates[SDL_SCANCODE_LSHIFT])
		env->p.speed = 10;
	else
		env->p.speed = 5;
	strafe(env, keystates);
}