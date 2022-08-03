/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0321_draw_line_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:46:34 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/20 12:12:42 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	draw_line_xtox(t_vars *vars, t_draw_data *ddraw)
{
	int	i;

	i = 0;
	ddraw->side = side_setter(ddraw->ps0_x, ddraw->ps1_x);
	while (ddraw->ps0_x + i != ddraw->ps1_x)
	{
		ddraw->line_x = ddraw->ps0_x + i;
		ddraw->line_y = ddraw->m * ddraw->line_x + ddraw->ps1_y
			- (double)(ddraw->m * ddraw->ps1_x);
		put_on_image2(vars, ddraw, i);
		i += ddraw->side;
	}
}

void	draw_line_ytoy(t_vars *vars, t_draw_data *ddraw)
{
	int	i;

	i = 0;
	ddraw->side = side_setter(ddraw->ps0_y, ddraw->ps1_y);
	while (ddraw->ps0_y + i != ddraw->ps1_y)
	{
		ddraw->line_y = ddraw->ps0_y + i;
		ddraw->line_x = (ddraw->line_y + ddraw->m * ddraw->ps1_x - ddraw->ps1_y)
			/ ddraw->m;
		put_on_image2(vars, ddraw, i);
		i += ddraw->side;
	}
	put_on_image2(vars, ddraw, i);
}

void	draw_line_vertical(t_vars *vars, t_draw_data *ddraw)
{
	int	i;

	i = 0;
	ddraw->side = side_setter(ddraw->ps0_y, ddraw->ps1_y);
	while (ddraw->ps0_y + i != ddraw->ps1_y)
	{
		ddraw->line_y = ddraw->ps0_y + i;
		ddraw->line_x = ddraw->ps0_x;
		put_on_image2(vars, ddraw, i);
		i += ddraw->side;
	}
}
