/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:24:49 by mraymond          #+#    #+#             */
/*   Updated: 2022/04/15 08:47:37 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double b, double exp)
{
	double	i;
	double	r_pow;

	i = -1;
	r_pow = 1;
	while (++i < exp)
		r_pow *= b;
	return (r_pow);
}
