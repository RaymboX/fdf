/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:14:16 by mraymond          #+#    #+#             */
/*   Updated: 2022/06/23 15:21:50 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr2len(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}

int	ft_ptr3len(void ***ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}

int	ft_ptr4len(void ****ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}
