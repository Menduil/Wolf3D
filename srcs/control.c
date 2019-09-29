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

void    p_limits(t_env *env, int x, int y)
{
    if (x <= 65 || y <= 65
        || x > (env->map.width - 1) * 64 - 1 || y > (env->map.height - 1) * 64 - 1)
        return ;
    env->p.xpos = x;
    env->p.ypos = y;
}

void	control_next(t_env *env, const Uint8 *keystates)
{
	int alpha_s;
	int x;
	int y;
	alpha_s = angle_adjust(env->p.alpha + 90);
	if (keystates[SDL_SCANCODE_D])
	    p_limits(env, env->p.xpos - round(env->cos_t[alpha_s] * (env->p.speed / 2)),
	            env->p.ypos + round(env->sin_t[alpha_s] * (env->p.speed / 2)));
	else if (keystates[SDL_SCANCODE_A])
        p_limits(env, env->p.xpos + round(env->cos_t[alpha_s] * (env->p.speed / 2)),
                 env->p.ypos - round(env->sin_t[alpha_s] * (env->p.speed / 2)));
	SDL_GetRelativeMouseState(&x, &y);
	if ((x > 3 || x < -3))
		env->p.alpha -= x / 10;
	env->p.alpha = angle_adjust(env->p.alpha);
	if (env->e.key.keysym.scancode == SDL_SCANCODE_SPACE)
	{
		if (SDL_GetRelativeMouseMode() == SDL_TRUE)
			SDL_SetRelativeMouseMode(SDL_FALSE);
		else
			SDL_SetRelativeMouseMode(SDL_TRUE);
	}
}

void	control(t_env *env, const Uint8 *keystates)
{
    if (env->e.type == SDL_QUIT || keystates[SDL_SCANCODE_ESCAPE])
        env->quit = 1;
    if (keystates[SDL_SCANCODE_Q])
        env->p.alpha += 1;
    else if (keystates[SDL_SCANCODE_E])
        env->p.alpha -= 1;
    if (keystates[SDL_SCANCODE_W])
        p_limits(env, env->p.xpos + round(env->cos_t[env->p.alpha] * env->p.speed),
                 env->p.ypos - round(env->sin_t[env->p.alpha] * env->p.speed));
    else if (keystates[SDL_SCANCODE_S])
        p_limits(env, env->p.xpos - round(env->cos_t[env->p.alpha] * env->p.speed),
                 env->p.ypos + round(env->sin_t[env->p.alpha] * env->p.speed));
    if (keystates[SDL_SCANCODE_LSHIFT])
        env->p.speed = 10;
    else
        env->p.speed = 5;
    if (keystates[SDL_SCANCODE_LCTRL])
        env->p.height = 32;
    else
        env->p.height = 52;
    control_next(env, keystates);
}
