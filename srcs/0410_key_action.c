/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0410_key_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:47:02 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/26 13:59:59 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	key_translation(int keycode, t_vars *vars)
{
	if (keycode == 8)
		vars->x_offset += vars->scale;
	if (keycode == 2)
		vars->x_offset -= vars->scale;
	if (keycode == 9)
		vars->y_offset += vars->scale;
	if (keycode == 3)
		vars->y_offset -= vars->scale;
	if (keycode == 11)
		vars->z_offset += vars->scale;
	if (keycode == 5)
		vars->z_offset -= vars->scale;
}

void	key_zoom(int keycode, t_vars *vars)
{
	if (keycode == 6)
		vars->dpl *= 1.1;
	if (keycode == 7)
		vars->dpl *= 0.9;
	if (keycode == 0)
		vars->dpo *= 1.1;
	if (keycode == 1)
		vars->dpo *= 0.9;
	if (keycode == 12)
		vars->scale *= 0.9;
	if (keycode == 13)
		vars->scale *= 1.1;
	if (vars->dpl < 10)
		vars->dpl = 10;
	if (vars->dpo < 10)
		vars->dpo = 10;
}

void	key_rotate(int keycode, t_vars *vars)
{
	if (keycode == 126)
		vars->azx -= 0.05;
	if (keycode == 125)
		vars->azx += 0.05;
	if (keycode == 123)
		vars->axy -= 0.05;
	if (keycode == 124)
		vars->axy += 0.05;
	axy_azx_ajust(&vars->axy, &vars->azx);
}

void	key_z_stretch(int keycode, t_vars *vars)
{
	if (keycode == 16)
		vars->z_stretch *= 1.1;
	if (keycode == 17 && vars->z_stretch * 0.9 * vars->scale > 10)
		vars->z_stretch *= 0.9;
	if (keycode == 31)
		vars->diag1 += 1;
	if (keycode == 35)
		vars->diag2 += 1;
	if (keycode == 4)
		vars->hub += 1;
}

void	key_rotate_pl(int keycode, t_vars *vars)
{
	double	axy_mod;
	double	azx_mod;

	if (keycode == 34 || keycode == 40 || keycode == 37 || keycode == 38)
	{
		axy_mod = vars->axy - crc2rad(1);
		azx_mod = vars->azx - crc2rad(1);
		if (keycode == 34)
			azx_mod -= 0.01;
		if (keycode == 40)
			azx_mod += 0.01;
		if (keycode == 38)
			axy_mod -= 0.01;
		if (keycode == 37)
			axy_mod += 0.01;
		cal_rpl_offset(vars, &axy_mod, &azx_mod);
	}
}
