/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 03:47:33 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 18:40:45 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst,
		t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	if (!lst || !f || !(*f))
		return (NULL);
	if (lst)
	{
		tmp = f(lst);
		tmp->next = ft_lstmap(lst->next, f);
		return (tmp);
	}
	return (NULL);
}
