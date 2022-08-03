/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:19:03 by mraymond          #+#    #+#             */
/*   Updated: 2022/04/01 11:11:16 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Return the location(ptr) of c in s. If no c in s, return NULL
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (s[i] != (char)c && i != 0)
		i--;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	else
		return (NULL);
}
