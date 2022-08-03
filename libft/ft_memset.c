/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:23:15 by mraymond          #+#    #+#             */
/*   Updated: 2022/04/01 11:11:31 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Fill b with c for len
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*a;

	a = (char *)b;
	i = -1;
	while (++i < len)
		a[i] = (char)c;
	return (a);
}
