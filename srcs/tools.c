/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/24 17:33:40 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/24 17:33:40 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

float	d_to_r(float x)
{
	return(PI * x / 180);
}

float	angle_adjust(float angle)
{
	if (angle < 0)
		angle = 359 + angle;
	else if (angle > 359)
		angle = 0 - (360 - angle);
	return (angle);
}
