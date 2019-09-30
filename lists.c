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

t_files		*ft_create_file(char *file)
{
	t_files *node;
	node = (t_files*)malloc(sizeof(t_files));
	node->name = file;
	return (node);
}

t_files		*ft_node_push_forward(char *file, t_files *node)
{
	if (!node)
	{
		ft_create_file(file);
		return (NULL);
	}
	node->next = ft_create_file(file);
	return (node->next);
}