/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:12:34 by mraymond          #+#    #+#             */
/*   Updated: 2022/04/07 10:54:02 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	i;
	t_list			*l;

	if (!(lst))
		return (0);
	l = lst;
	i = 1;
	while ((*l).next != NULL)
	{
		l = (*l).next;
		i += 1;
	}
	return (i);
}
