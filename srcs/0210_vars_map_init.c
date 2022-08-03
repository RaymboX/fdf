/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0210_vars_map_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:43:11 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/20 12:12:20 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	vars_map_init(t_vars *vars)
{
	if (vars->pm_z_higher - vars->pm_z_lower > vars->map_nbx
		&& vars->pm_z_higher - vars->pm_z_lower > vars->map_nby)
		vars->scale = SCREEN_H / (vars->pm_z_higher - vars->pm_z_lower);
	else if (vars->map_nbx > vars->map_nby)
		vars->scale = SCREEN_W / vars->map_nbx;
	else
		vars->scale = SCREEN_H / vars->map_nby;
	if (vars->scale < 1)
		vars->scale = 1;
	vars->x_offset = ((vars->map_nbx - 1) * vars->scale) / 2;
	vars->y_offset = ((vars->map_nby - 1) * vars->scale * -1) / 2;
	vars->z_offset = vars->pm_z_moy * vars->scale / 2;
	set_dpl_dpo(vars);
	vars->axy = AXY_INIT * PI;
	vars->azx = AZX_INIT * PI;
	vars->scale *= 1;
	vars->diag1 = 1;
	vars->diag2 = 1;
	vars->z_stretch = 1;
	vars->hub = 1;
}

void	set_dpl_dpo(t_vars *vars)
{
	int	bigger;

	bigger = vars->pm_z_higher - vars->pm_z_lower;
	if (bigger < SCREEN_H)
		bigger = SCREEN_H;
	if (bigger < SCREEN_W)
		bigger = SCREEN_W;
	vars->dpl = bigger * 5;
	vars->dpo = bigger * 4;
}
