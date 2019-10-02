/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 03:44:45 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/06 11:03:52 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list
					*elem))
{
	t_list	*tmp;

	if (!f || !lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(tmp);
		tmp = tmp->next;
	}
}
