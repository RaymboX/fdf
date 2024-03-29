/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:15:36 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/21 13:17:07 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//retourne la longueur de la chaine de caractere sans le \0
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i])
		i++;
	return (i);
}
