/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:10:45 by mraymond          #+#    #+#             */
/*   Updated: 2022/04/07 09:35:28 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Return ptr de s commencant a start pour nbchar len
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	if (s != NULL)
	{
		if (start > (unsigned int)ft_strlen(s))
			return (ft_strdup(""));
		if (len > ft_strlen(s))
			len = ft_strlen(s) + 1;
		dst = (char *)ft_calloc(len + 1, sizeof(char));
		if (dst != NULL)
		{
			i = -1;
			while (++i < len)
				dst[i] = s[start + i];
			dst[i] = '\0';
		}
		return (dst);
	}
	else
		return (NULL);
}
