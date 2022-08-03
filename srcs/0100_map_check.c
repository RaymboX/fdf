/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0100_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:43:52 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/21 14:01:59 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static int	map_size_check(t_vars *vars);
static int	nbx_cmp(t_vars *vars, int *nbx_now);

//verifie .fdf + map size 0=ok
int	map_check(t_vars *vars, char *map_name)
{
	int	ret_val;

	ret_val = 0;
	vars->map_name = map_name;
	write(1, "Checking map...", 15);
	if (ft_strncmp(&map_name[ft_strlen(map_name) - 4], ".fdf", 4) == 0)
	{
		vars->map_fd = open(map_name, O_RDONLY);
		if (vars->map_fd == -1 || map_size_check(vars) != 0)
			ret_val = 1;
		close(vars->map_fd);
		if (ret_val == 0)
			write(1, "...Map ok\nLoading map....", 25);
		return (ret_val);
	}
	return (2);
}

//compte nbx nby, verifie pas vide + all row meme n 0=ok
static int	map_size_check(t_vars *vars)
{
	int		nbx_now;
	char	buf;
	char	last_c;

	vars->map_nbx = -1;
	vars->map_nby = 0;
	nbx_now = 0;
	last_c = ' ';
	while (read(vars->map_fd, &buf, 1) != 0 && !(buf == '\n' && last_c == '\n'
			&& vars->map_nby > 0) && ft_isascii(buf) == 1)
	{
		if (buf == '\n' || ft_isspace(buf) == 1)
		{
			if (ft_isspace(last_c) != 1)
				nbx_now += 1;
			if (buf == '\n' && nbx_cmp(vars, &nbx_now) != 0)
				return (1);
		}
		last_c = buf;
	}
	if (vars->map_nbx == -1)
		return (1);
	if (last_c != '\n' && nbx_now != 0)
		vars->map_nby += 1;
	return (0);
}

//verifier nb point par row sont meme et que map pas vide ou row pas vide 0=ok
static int	nbx_cmp(t_vars *vars, int *nbx_now)
{
	if ((vars->map_nbx != -1 && *nbx_now != vars->map_nbx) || *nbx_now == 0)
		return (1);
	vars->map_nbx = *nbx_now;
	*nbx_now = 0;
	vars->map_nby += 1;
	return (0);
}
