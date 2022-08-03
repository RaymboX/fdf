/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0322_draw_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:46:46 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/21 14:10:42 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	side_setter(int val0, int val1)
{
	if (val0 < val1)
		return (1);
	else
		return (-1);
}

void	put_on_image2(t_vars *vars, t_draw_data *ddraw, int i)
{
	if (ddraw->line_x > 0 && ddraw->line_x < SCREEN_W
		&& ddraw->line_y > 0 && ddraw->line_y < SCREEN_H)
		my_mlx_pixel_put(vars, ddraw->line_x, ddraw->line_y,
			color_shift(vars, ddraw, i));
}

//fait la graduation des couleurs entre les points
int	color_shift(t_vars *vars, t_draw_data *ddraw, int i)
{
	double	r;
	int		shift[4];

	if (abs(vars->pp[ddraw->adr_1].x - vars->pp[ddraw->adr_0].x) != 0)
		r = (double)i / (double)abs(vars->pp[ddraw->adr_1].x
				- vars->pp[ddraw->adr_0].x);
	else if (abs(vars->pp[ddraw->adr_1].y - vars->pp[ddraw->adr_0].y) != 0)
		r = i / abs(vars->pp[ddraw->adr_1].y - vars->pp[ddraw->adr_0].y);
	else
		r = 0;
	shift[0] = r * (vars->pp[ddraw->adr_1].color_t
			- vars->pp[ddraw->adr_0].color_t) + vars->pp[ddraw->adr_0].color_t;
	shift[1] = r * (vars->pp[ddraw->adr_1].color_r
			- vars->pp[ddraw->adr_0].color_r) + vars->pp[ddraw->adr_0].color_r;
	shift[2] = r * (vars->pp[ddraw->adr_1].color_g
			- vars->pp[ddraw->adr_0].color_g) + vars->pp[ddraw->adr_0].color_g;
	shift[3] = r * (vars->pp[ddraw->adr_1].color_b
			- vars->pp[ddraw->adr_0].color_b) + vars->pp[ddraw->adr_0].color_b;
	return (create_trgb(shift[0], shift[1], shift[2], shift[3]));
}

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
