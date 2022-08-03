/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:28:44 by mraymond          #+#    #+#             */
/*   Updated: 2022/04/05 09:36:26 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copy char data from src to dst for len long
char	*ft_memcpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	if (dst != NULL || src != NULL)
	{
		i = -1;
		while (++i < len)
			dst[i] = src[i];
	}
	return (dst);
}
