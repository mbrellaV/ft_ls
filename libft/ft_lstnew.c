/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 02:05:30 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/06 11:07:37 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content,
		size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		if (!(tmp->content = malloc(content_size)))
		{
			free(tmp);
			return (NULL);
		}
		ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	return (tmp);
}
