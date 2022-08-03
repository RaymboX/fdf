/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0400_keypress_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:46:55 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/20 12:12:49 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	keypress_handler(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_win(vars);
	if (keycode == 15)
		vars_map_init(vars);
	key_translation(keycode, vars);
	key_zoom(keycode, vars);
	key_rotate(keycode, vars);
	key_rotate_pl(keycode, vars);
	key_z_stretch(keycode, vars);
	render_next_frame(vars);
	return (0);
}

int	exit_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->pp);
	free(vars->pm_z);
	exit(0);
	return (1);
}

int	render_next_frame(t_vars *vars)
{
	mlx_destroy_image (vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, SCREEN_W, SCREEN_H);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	new_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	hub_show(vars);
	return (0);
}
