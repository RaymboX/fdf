/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0320_draw_new_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:46:25 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/26 13:56:40 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

//fonction qui creee la nouvelle image
void	draw_new_image(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (++y < vars->map_nby)
	{
		x = -1;
		while (++x < vars->map_nbx)
			draw_lines(vars, x, y);
	}
}

//dessine les lignes gauches droite et haut bas s'il y a lieu
void	draw_lines(t_vars *vars, int x, int y)
{
	t_draw_data	ddraw;

	ddraw.adr_0 = vars->map_nbx * y + x;
	if (vars->map_nbx - x > 1)
	{
		ddraw.adr_1 = vars->map_nbx * y + x + 1;
		draw_line(vars, &ddraw);
	}
	if (vars->map_nby - y > 1)
	{
		ddraw.adr_1 = vars->map_nbx * (y + 1) + x;
		draw_line(vars, &ddraw);
	}
	if (vars->diag1 % 2 == 0 && vars->map_nby - y > 1 && vars->map_nbx - x > 1)
	{
		ddraw.adr_1 = vars->map_nbx * (y + 1) + x + 1;
		draw_line(vars, &ddraw);
	}
	if (vars->diag2 % 2 == 0 && vars->map_nby - y > 1 && x > 0)
	{
		ddraw.adr_1 = vars->map_nbx * (y + 1) + x - 1;
		draw_line(vars, &ddraw);
	}
}

void	draw_line(t_vars *vars, t_draw_data *ddraw)
{
	set_xy(vars, ddraw);
	if (line_too_long(ddraw) == 0)
	{
		if (ddraw->ps0_x != ddraw->ps1_x)
		{
			ddraw->m = ((double)(ddraw->ps1_y - ddraw->ps0_y))
				/ ((double)(ddraw->ps1_x - ddraw->ps0_x));
			draw_line_xtox(vars, ddraw);
			draw_line_ytoy(vars, ddraw);
		}
		else
			draw_line_vertical(vars, ddraw);
	}
}

//inscrit les valeurs xy dans ps
void	set_xy(t_vars *vars, t_draw_data *ddraw)
{
	ddraw->ps0_x = vars->pp[ddraw->adr_0].x;
	ddraw->ps0_y = vars->pp[ddraw->adr_0].y;
	ddraw->ps1_x = vars->pp[ddraw->adr_1].x;
	ddraw->ps1_y = vars->pp[ddraw->adr_1].y;
}

int	line_too_long(t_draw_data *ddraw)
{
	double	len;

	len = sqrt(ft_pow(ddraw->ps0_x - ddraw->ps1_x, 2)
			+ ft_pow(ddraw->ps0_y - ddraw->ps0_y, 2));
	if (len > SCREEN_H || len > SCREEN_W)
		return (1);
	return (0);
}
