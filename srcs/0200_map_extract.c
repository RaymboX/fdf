/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0200_map_extract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:14:23 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/20 12:12:16 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

//store z map dans pm_z & fix color dans pp->color + lock & scale
void	map_extract(t_vars *vars)
{
	vars->pm_z = (int *)calloc(sizeof(int), vars->map_nby * vars->map_nbx);
	vars->pp = (t_pp *)calloc(sizeof(t_pp), vars->map_nby * vars->map_nbx);
	vars->map_fd = open(vars->map_name, O_RDONLY);
	line_by_line_extract(vars);
	close(vars->map_fd);
	vars_map_init(vars);
	write(1, "...Map loaded\nDrawing....", 25);
}

void	line_by_line_extract(t_vars *vars)
{
	char	**split_line;
	char	*line;
	int		y;
	int		i_split;

	y = -1;
	vars->pm_z_moy = 0;
	vars->pm_z_lower = 0;
	vars->pm_z_higher = 0;
	while (++y < vars->map_nby)
	{
		line = get_next_line(vars->map_fd);
		split_line = ft_split(line, ' ');
		z_extract(vars, split_line, y);
		free(line);
		i_split = -1;
		while (split_line[++i_split] != NULL)
			free(split_line[i_split]);
		free(split_line);
		if (vars->map_nby > 200)
			progress_bar(0, vars->map_nby - 1, y, 20);
	}
	vars->pm_z_moy /= vars->map_nbx * vars->map_nby;
}

void	z_extract(t_vars *vars, char **split_line, int y)
{
	int	x;

	y = vars->map_nbx * y;
	x = 0;
	while (x < vars->map_nbx)
	{
		vars->pm_z[y + x] = ft_atoi(split_line[x]);
		pm_z_moy_high_low(vars, x, y);
		if (ft_strnstr(split_line[x], ",0x", ft_strlen(split_line[x])) != NULL)
			color_extract(vars, split_line[x], y, x);
		x++;
	}
}

void	pm_z_moy_high_low(t_vars *vars, int x, int y)
{
	vars->pm_z_moy += vars->pm_z[y + x];
	if (vars->pm_z_lower > vars->pm_z[y + x])
		vars->pm_z_lower = vars->pm_z[y + x];
	if (vars->pm_z_higher < vars->pm_z[y + x])
		vars->pm_z_higher = vars->pm_z[y + x];
}

void	color_extract(t_vars *vars, char *color_info, int y, int x)
{
	char	*color_c;

	color_c = ft_substr(color_info, ft_strlen(color_info) - 6, 2);
	vars->pp[y + x].color_r = ft_atoi_base(color_c, 16);
	free(color_c);
	color_c = ft_substr(color_info, ft_strlen(color_info) - 4, 2);
	vars->pp[y + x].color_g = ft_atoi_base(color_c, 16);
	free(color_c);
	color_c = ft_substr(color_info, ft_strlen(color_info) - 2, 2);
	vars->pp[y + x].color_b = ft_atoi_base(color_c, 16);
	free(color_c);
	vars->pp[y + x].color_t = 0;
	vars->pp[y + x].color_lock = 1;
}
