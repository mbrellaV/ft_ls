/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:05:23 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/30 16:05:27 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort_files(t_files *node)
{
	t_files	*tmp;
	int		i;
	int		cn;

	i = 0;
	cn = 0;
	tmp = node;
	while (node)
	{
		i++;
		node = node->next;
	}
	while (cn < i)
	{
		node = tmp;
		while (node)
		{
			if (ft_strcmp(node->name, node->next->name))
		}
	}
}