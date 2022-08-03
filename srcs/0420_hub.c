/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0420_hub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:22:03 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/20 12:12:58 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	hub_show(t_vars *vars)
{
	if (vars->hub % 2 == 0)
	{
		hub_list1(vars);
		hub_list2(vars);
		hub_list3(vars);
	}
}

void	hub_list1(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0xFFFFFF, "angle azx:");
	mlx_str_itoa(vars, 170, 10, (int)craddeg(vars->azx));
	mlx_string_put(vars->mlx, vars->win, 10, 30, 0xFFFFFF, "angle axy:");
	mlx_str_itoa(vars, 170, 30, (int)craddeg(vars->axy));
	mlx_string_put(vars->mlx, vars->win, 10, 50, 0xFFFFFF, "dist. map-plane:");
	mlx_str_itoa(vars, 170, 50, (int)craddeg(vars->dpl));
	mlx_string_put(vars->mlx, vars->win, 10, 70, 0xFFFFFF, "dist. plane-obs:");
	mlx_str_itoa(vars, 170, 70, (int)craddeg(vars->dpo));
	mlx_string_put(vars->mlx, vars->win, 10, 90, 0xFFFFFF, "scale:");
	mlx_str_itoa(vars, 170, 90, (int)craddeg(vars->scale));
	mlx_string_put(vars->mlx, vars->win, 10, 110, 0xFFFFFF, "x_offset:");
	mlx_str_itoa(vars, 170, 110, (int)craddeg(vars->x_offset));
	mlx_string_put(vars->mlx, vars->win, 10, 130, 0xFFFFFF, "y_offset:");
	mlx_str_itoa(vars, 170, 130, (int)craddeg(vars->y_offset));
	mlx_string_put(vars->mlx, vars->win, 10, 150, 0xFFFFFF, "z_offset:");
	mlx_str_itoa(vars, 170, 150, (int)craddeg(vars->z_offset));
	mlx_string_put(vars->mlx, vars->win, 10, 170, 0xFFFFFF, "z_stretch * 10:");
	mlx_str_itoa(vars, 170, 170, (int)craddeg(vars->z_stretch));
}

void	hub_list2(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 260, 0xFFFFFF,
		"angle azx:       up / down arrows");
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 240, 0xFFFFFF,
		"angle axy:       left right arrows");
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 220, 0xFFFFFF,
		"dist. map-plane: z x");
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 200, 0xFFFFFF,
		"dist. plane-obs: a s");
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 180, 0xFFFFFF,
		"scale:           q w");
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 160, 0xFFFFFF,
		"x_offset:        d c");
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 140, 0xFFFFFF,
		"y_offset:        f v");
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 120, 0xFFFFFF,
		"z_offset:        g b");
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 100, 0xFFFFFF,
		"z_stretch * 10:  t y");
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 80, 0xFFFFFF,
		"observer angle:  i k j l");
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 60, 0xFFFFFF,
		"diagonales:      o p");
}

void	hub_list3(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 40, 0xFFFFFF,
		"reset view:      r");
	mlx_string_put(vars->mlx, vars->win, 10, SCREEN_H - 20, 0xFFFFFF,
		"hide hub:        h");
}

void	mlx_str_itoa(t_vars *vars, int x, int y, int val)
{
	char	*str;

	str = ft_itoa(val);
	mlx_string_put(vars->mlx, vars->win, x, y, 0xFF00FF, str);
	free(str);
}
