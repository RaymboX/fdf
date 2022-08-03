/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:44:10 by mraymond          #+#    #+#             */
/*   Updated: 2022/04/07 10:53:50 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lstdelall(t_list *lst, void (*del)(void *))
{
	if (lst->next != NULL)
	{
		lstdelall(lst->next, del);
		ft_lstdelone(lst, del);
	}
	else
		ft_lstdelone(lst, del);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	lstdelall(*lst, del);
	*lst = NULL;
}
