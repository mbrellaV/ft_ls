/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 03:31:43 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/05 20:29:54 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *,
											size_t))
{
	t_list	*tmp;
	t_list	*tmp_save;

	if (!alst || !(*alst) || !del)
		return ;
	tmp = *alst;
	while (tmp)
	{
		tmp_save = tmp;
		ft_lstdelone(&tmp, del);
		tmp = tmp_save->next;
	}
	*alst = NULL;
}
