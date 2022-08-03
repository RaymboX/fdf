/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0310_pp_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:54:46 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/20 12:12:25 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

//boucle pour remplir coord xy des points d'intersection sur le plan
void	fill_all_pp(t_vars *vars, t_ni_data *ni)
{
	ni->y = -1;
	while (++ni->y < vars->map_nby)
	{
		ni->x = -1;
		while (++ni->x < vars->map_nbx)
			cal_fill_pp(vars, ni);
	}
}

//calcul pour each pp / v:vector m:map o:observer p:plane i:intersect
void	cal_fill_pp(t_vars *vars, t_ni_data *ni)
{
	cal_vmo(vars, ni);
	if (cal_t_equ_plane(ni) == 1)
		pp_center_plane(vars, ni);
	else
	{
		cal_pi(ni);
		cal_vli(ni);
		cal_vlo(ni);
		cal_vplane2d(vars, ni);
		fill_pp(vars, ni);
	}
	pp_color_apply(vars, ni);
}

//insere l'information x y  de la screen dans vars->pp
void	fill_pp(t_vars *vars, t_ni_data *ni)
{
	vars->pp[vars->map_nbx * ni->y + ni->x].x = SCREEN_W / 2 + ni->vplane2d->x;
	vars->pp[vars->map_nbx * ni->y + ni->x].y = SCREEN_H / 2 + ni->vplane2d->y;
}

//selon les divisions != 0, applique le point au centre
void	pp_center_plane(t_vars *vars, t_ni_data *ni)
{
	vars->pp[vars->map_nbx * ni->y + ni->x].x = SCREEN_W / 2;
	vars->pp[vars->map_nbx * ni->y + ni->x].y = SCREEN_H / 2;
}

//par default, met la couleur verte si pas lock
void	pp_color_apply(t_vars *vars, t_ni_data *ni)
{
	if (vars->pp[vars->map_nbx * ni->y + ni->x].color_lock != 1)
	{
		vars->pp[vars->map_nbx * ni->y + ni->x].color_t = 0;
		vars->pp[vars->map_nbx * ni->y + ni->x].color_r = 3;
		vars->pp[vars->map_nbx * ni->y + ni->x].color_g = 245;
		vars->pp[vars->map_nbx * ni->y + ni->x].color_b = 147;
		vars->pp[vars->map_nbx * ni->y + ni->x].color_lock = 0;
	}
}
