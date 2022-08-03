/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0312_vplane2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:05:54 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/20 12:12:32 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	cal_vplane2d(t_vars *vars, t_ni_data *ni)
{
	if ((vars->azx >= crc2rad(0.25) && vars->azx < crc2rad(0.75))
		|| (vars->azx >= crc2rad(1.25) && vars->azx < crc2rad(1.75)))
	{
		ni->vplane2d->y = atan(ni->vli->azx - ni->vlo->azx)
			* vars->dpl;
		ni->vplane2d->x = atan(vplane2d_angle_axy(vars->axy, ni->vli->axy))
			* vars->dpl;
		if (vars->azx > crc2rad(1))
			ni->vplane2d->x *= -1;
	}
	else
		pole_angle(vars, ni);
}

double	vplane2d_angle_axy(double vars, double vli)
{
	double	add;

	add = 0;
	if (vars >= crc2rad(0.25) && vars < crc2rad(0.75))
		add = crc2rad(0.5);
	if (vars >= crc2rad(0.75) && vars < crc2rad(1.25))
		add = crc2rad(1);
	if (vars >= crc2rad(1.25) && vars < crc2rad(1.75))
		add = crc2rad(1.5);
	if (vars >= crc2rad(1.75))
		vars -= crc2rad(2);
	vli += add;
	if (vli - vars > 1)
		return (vli - crc2rad(0.5) - vars);
	if (vli - vars < -1)
		return (vli + crc2rad(0.5) - vars);
	return (vli - vars);
}

void	pole_angle(t_vars *vars, t_ni_data *ni)
{
	double	ayz;
	double	axz;

	if (ni->vlo->z != 0)
		ayz = atan((double)ni->vlo->y / (double)ni->vlo->z);
	else
		ayz = crc2rad(0.5);
	if (ni->vlo->p != 0)
		axz = acos((double)ni->vlo->x / (double)ni->vlo->p);
	else
		axz = crc2rad(0.5);
	ni->vplane2d->y = atan(ni->vli_pole->axy - ayz)
		* vars->dpl;
	ni->vplane2d->x = atan(ni->vli_pole->azx - axz)
		* vars->dpl;
}
