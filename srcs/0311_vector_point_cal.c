/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0311_vector_point_cal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:46:01 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/20 12:12:29 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

//calcul le vector map observer
void	cal_vmo(t_vars *vars, t_ni_data *ni)
{
	ni->pm->x = ni->x * vars->scale;
	ni->pm->y = ni->y * vars->scale * -1;
	ni->pm->z = vars->pm_z[vars->map_nbx * ni->y + ni->x] * vars->scale
		* vars->z_stretch;
	ni->vmo->x = ni->po->x - ni->pm->x;
	ni->vmo->y = ni->po->y - ni->pm->y;
	ni->vmo->z = ni->po->z - ni->pm->z;
	ni->vmo->p = sqrt(ni->vmo->x * ni->vmo->x + ni->vmo->y * ni->vmo->y
			+ ni->vmo->z * ni->vmo->z);
	if (ni->vmo->x != 0)
		ni->vmo->axy = atan((double)ni->vmo->y / (double)ni->vmo->x);
	if (ni->vmo->p != 0)
		ni->vmo->azx = acos((double)ni->vmo->z / (double)ni->vmo->p);
}

void	cal_pi(t_ni_data *ni)
{
	ni->pi->x = ni->po->x + ni->vmo->x * ni->t;
	ni->pi->y = ni->po->y + ni->vmo->y * ni->t;
	ni->pi->z = ni->po->z + ni->vmo->z * ni->t;
}

void	cal_vlo(t_ni_data *ni)
{
	ni->vlo->x = ni->po->x - ni->pl->x;
	ni->vlo->y = ni->po->y - ni->pl->y;
	ni->vlo->z = ni->po->z - ni->pl->z;
	ni->vlo->p = sqrt(ni->vlo->x * ni->vlo->x + ni->vlo->y * ni->vlo->y
			+ ni->vlo->z * ni->vlo->z);
	if (ni->vlo->x != 0)
		ni->vlo->axy = atan((double)ni->vlo->y / (double)ni->vlo->x);
	else
		ni->vlo->axy = crc2rad(0.5);
	if (ni->vlo->p != 0)
		ni->vlo->azx = acos((double)ni->vlo->z / (double)ni->vlo->p);
}

void	cal_vli(t_ni_data *ni)
{
	ni->vli->x = ni->pi->x - ni->pl->x;
	ni->vli->y = ni->pi->y - ni->pl->y;
	ni->vli->z = ni->pi->z - ni->pl->z;
	ni->vli->p = sqrt(ni->vli->x * ni->vli->x + ni->vli->y * ni->vli->y
			+ ni->vli->z * ni->vli->z);
	if (ni->vli->x != 0)
		ni->vli->axy = (double)atan((double)ni->vli->y / (double)ni->vli->x);
	else
		ni->vli->axy = crc2rad(0.5);
	if (ni->vli->p != 0)
		ni->vli->azx = (double)acos((double)ni->vli->z / (double)ni->vli->p);
	if (ni->vli->z != 0)
		ni->vli_pole->axy = (double)atan((double)ni->vli->y
				/ (double)ni->vli->z);
	else
		ni->vli_pole->axy = crc2rad(0.5);
	if (ni->vli->p != 0)
		ni->vli_pole->azx = (double)acos((double)ni->vli->x
				/ (double)ni->vli->p);
}

//calcul le t de l'equation intersection plane3d / droite
int	cal_t_equ_plane(t_ni_data *ni)
{
	if ((ni->vmo->x * ni->vlppm->x + ni->vmo->y * ni->vlppm->y
			+ ni->vmo->z * ni->vlppm->z) == 0)
		return (1);
	ni->t = (ni->d - (ni->vlppm->x * ni->po->x + ni->vlppm->y * ni->po->y
				+ ni->vlppm->z * ni->po->z)) / (ni->vmo->x * ni->vlppm->x
			+ ni->vmo->y * ni->vlppm->y + ni->vmo->z * ni->vlppm->z);
	return (0);
}
