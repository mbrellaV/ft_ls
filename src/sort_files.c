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

#include "../inc/ft_ls.h"

void	ft_sort_files(t_files *node, t_args *flags)
{
	t_files	*tmp;
	int		i;
	int		cn;
	t_files *doptmp;
	void	*dopspace;

	i = 0;
	cn = 0;
	tmp = node;
	while (node)
	{
		i++;
		//printf(" %s ", node->name);
		node = node->next;
	}
	dopspace = (void*)malloc(sizeof(t_files));
	//printf(" %lu ", sizeof(t_files*));
	while (cn < i)
	{
		node = tmp;
		while (node->next)
		{
			//printf(" %s ", node->name);
			if (flags->isactivated_flags[0] && ft_strcmp(node->name, node->next->name) < 0)
			{
				ft_memcpy(dopspace, node->next, sizeof(t_files) - 8);
				ft_memcpy(node->next, node, sizeof(t_files) - 8);
				ft_memcpy(node, dopspace, sizeof(t_files) - 8);
			}
			if (flags->isactivated_flags[0] == 0 && ft_strcmp(node->name, node->next->name) >= 0)
			{
				ft_memcpy(dopspace, node->next, sizeof(t_files) - 8);
				ft_memcpy(node->next, node, sizeof(t_files) - 8);
				ft_memcpy(node, dopspace, sizeof(t_files) - 8);
			}
			//doptmp = doptmp->next;
			node = node->next;
		}
		cn++;
	}
}