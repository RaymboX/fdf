/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:07:40 by mraymond          #+#    #+#             */
/*   Updated: 2022/04/01 11:11:38 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//return 1 if c is letter or number else 0
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 0 && ft_isdigit(c) == 0)
		return (0);
	else
		return (1);
}
