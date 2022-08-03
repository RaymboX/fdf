/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:00:36 by mraymond          #+#    #+#             */
/*   Updated: 2022/04/07 10:53:55 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*l;

	l = lst;
	if (l != NULL)
	{
		while (l->next != NULL)
		{
			f(l->content);
			l = l->next;
		}
		f(l->content);
	}
}
