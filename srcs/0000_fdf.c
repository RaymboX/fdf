/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0000_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:15:21 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/26 13:06:33 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 || map_check(&vars, argv[1]) != 0)
	{
		if (argc != 2)
			write(1, "arguments ", 10);
		write(1, "fail\n", 5);
		return (0);
	}
	map_extract(&vars);
	vars_mlx_init(&vars);
	new_image(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	hub_show(&vars);
	mlx_hook(vars.win, 2, 0, keypress_handler, &vars);
	mlx_hook(vars.win, 17, 0, exit_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	vars_mlx_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, SCREEN_W, SCREEN_H, "fdf");
	vars->img = mlx_new_image(vars->mlx, SCREEN_W, SCREEN_H);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
}
