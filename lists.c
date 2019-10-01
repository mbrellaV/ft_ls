/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:50:58 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/30 15:51:01 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files		*ft_create_file(char *file, t_files *node)
{
	node = (t_files*)malloc(sizeof(t_files));
	node->next = NULL;
	node->name = (char*)malloc(100);
	strlcat(node->name, file, 100);
	return (node);
}

t_args		*ft_create_args(t_args *node)
{
	int i;

	i = 0;
	node =  (t_args*)malloc(sizeof(t_args));
	node->flags = "rRalt";
	while (i++ < COUNT_FLAGS)
		node->isactivated_flags[i] = 0;
	return (node);
}

t_files		*ft_node_push_forward(char *file, t_files *node)
{
	if (!node)
	{
		//ft_create_file(file);
		return (NULL);
	}
	node->next = ft_create_file(file, node);
	return (node->next);
}