/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0300_new_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:01:59 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/20 12:12:23 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

//lorsque changement dans donnee angle ou position pl, pp, po
void	new_image(t_vars *vars)
{
	t_ni_data	ni;

	calloc_ni_data(&ni);
	pl_ppm_po_xyz(vars, &ni);
	cal_plane_equation_d(&ni);
	fill_all_pp(vars, &ni);
	draw_new_image(vars);
	free_ni_data(&ni);
}

void	calloc_ni_data(t_ni_data *ni)
{
	ni->vlppm = (t_vector *)calloc(1, sizeof(t_vector));
	ni->vmo = (t_vector *)calloc(1, sizeof(t_vector));
	ni->vli = (t_vector *)calloc(1, sizeof(t_vector));
	ni->vli_pole = (t_vector *)calloc(1, sizeof(t_vector));
	ni->vlo = (t_vector *)calloc(1, sizeof(t_vector));
	ni->vplane2d = (t_vector *)calloc(1, sizeof(t_vector));
	ni->pi = (t_point *)calloc(1, sizeof(t_point));
	ni->pl = (t_point *)calloc(1, sizeof(t_point));
	ni->ppm = (t_point *)calloc(1, sizeof(t_point));
	ni->po = (t_point *)calloc(1, sizeof(t_point));
	ni->pm = (t_point *)calloc(1, sizeof(t_point));
}

void	free_ni_data(t_ni_data *ni)
{
	free(ni->vlppm);
	free(ni->vmo);
	free(ni->vli);
	free(ni->vli_pole);
	free(ni->vlo);
	free(ni->vplane2d);
	free(ni->pi);
	free(ni->pl);
	free(ni->ppm);
	free(ni->po);
	free(ni->pm);
}

//calcul point milieu du plan et point observer
void	pl_ppm_po_xyz(t_vars *vars, t_ni_data *ni)
{
	ni->pl->x = vars->x_offset;
	ni->pl->y = vars->y_offset;
	ni->pl->z = vars->z_offset;
	ni->ppm->x = vars->dpl * sin(vars->azx) * cos(vars->axy) + ni->pl->x;
	ni->ppm->y = vars->dpl * sin(vars->azx) * sin(vars->axy) + ni->pl->y;
	ni->ppm->z = vars->dpl * cos(vars->azx) + ni->pl->z;
	ni->po->x = (vars->dpl + vars->dpo) * sin(vars->azx) * cos(vars->axy)
		+ ni->pl->x;
	ni->po->y = (vars->dpl + vars->dpo) * sin(vars->azx) * sin(vars->axy)
		+ ni->pl->y;
	ni->po->z = (vars->dpl + vars->dpo) * cos(vars->azx) + ni->pl->z;
}

//selon equation d'un plan 3d, trouve d dans l'equation + vector de look a plane
void	cal_plane_equation_d(t_ni_data *ni)
{
	ni->vlppm->x = ni->ppm->x - ni->pl->x;
	ni->vlppm->y = ni->ppm->y - ni->pl->y;
	ni->vlppm->z = ni->ppm->z - ni->pl->z;
	ni->d = ni->vlppm->x * ni->ppm->x + ni->vlppm->y * ni->ppm->y
		+ ni->vlppm->z * ni->ppm->z;
}
