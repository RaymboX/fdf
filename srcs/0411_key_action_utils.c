/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0411_key_action_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:43:34 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/26 14:05:49 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	axy_azx_ajust(double *axy, double *azx)
{
	if (*axy < crc2rad(0))
		*axy += crc2rad(2);
	if (*axy >= crc2rad(2))
		*axy -= crc2rad(2);
	if (*azx < crc2rad(0))
		*azx += crc2rad(2);
	if (*azx >= crc2rad(2))
		*azx -= crc2rad(2);
}

void	cal_rpl_offset(t_vars *vars, double *axy_mod, double *azx_mod)
{
	int	po_x;
	int	po_y;
	int	po_z;

	po_x = (vars->dpl) * sin(vars->azx) * cos(vars->axy)
		+ vars->x_offset;
	po_y = (vars->dpl) * sin(vars->azx) * sin(vars->axy)
		+ vars->y_offset;
	po_z = (vars->dpl) * cos(vars->azx) + vars->z_offset;
	axy_azx_ajust(axy_mod, azx_mod);
	vars->x_offset = po_x - (vars->dpl) * sin(*azx_mod)
		* cos(*axy_mod);
	vars->y_offset = po_y - (vars->dpl) * sin(*azx_mod)
		* sin(*axy_mod);
	vars->z_offset = po_z + (vars->dpl) * cos(*azx_mod);
	vars->axy = *axy_mod + crc2rad(1);
	vars->azx = *azx_mod + crc2rad(1);
	axy_azx_ajust(&vars->axy, &vars->azx);
}
