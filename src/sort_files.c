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


void	ft_swap_void(t_files *node, t_args *flags, void *dopspace)
{
	ft_memcpy(dopspace, node->next, sizeof(t_files) - 8);
	ft_memcpy(node->next, node, sizeof(t_files) - 8);
	ft_memcpy(node, dopspace, sizeof(t_files) - 8);
}

void	ft_sort_norm(t_files *node, t_args *flags, void *dopspace, int i)
{
	t_files *tmp;
	int cn;

	tmp = node;
	cn = 0;
	while (cn < i)
	{
		node = tmp;
		while (node->next)
		{
			//printf(" %s ", node->name);
			if (flags->isactivated_flags[0] && ft_strcmp(node->name, node->next->name) < 0)
				ft_swap_void(node, flags, dopspace);
			if (flags->isactivated_flags[0] == 0 && ft_strcmp(node->name, node->next->name) >= 0)
				ft_swap_void(node, flags, dopspace);
			node = node->next;
		}
		cn++;
	}
}

void	ft_sort_time(t_files *node, t_args *flags, void *dopspace, int i)
{
	t_files *tmp;
	int cn;

	cn = 0;
	tmp = node;
	while (cn < i + 1)
	{
		node = tmp;
		while (node->next)
		{
			//printf(" %s ", node->name);
			if (flags->isactivated_flags[0] && node->time >= node->next->time)
				ft_swap_void(node, flags, dopspace);
			if (flags->isactivated_flags[0] == 0 && node->time < node->next->time)
				ft_swap_void(node, flags, dopspace);
			node = node->next;
		}
		cn++;
	}
}

void	ft_sort_args(int i, char **argv, int argc)
{
	int		d;
	int		c;
	char	*dop;

	d = i;
	c = i;
	while(d < argc)
	{
		while (c < argc - 1)
		{
			if (ft_strcmp(argv[c], argv[c + 1]) >= 0)
			{
				dop = argv[c];
				argv[c] = argv[c + 1];
				argv[c + 1] = dop;
			}
			c++;
		}
		d++;
	}
}

void	ft_sort_files(t_files *node, t_args *flags)
{
	t_files	*tmp;
	int		i;
	int		cn;
	void	*dopspace;

	i = 0;
	cn = 0;
	tmp = node;
	while (node)
	{
		i++;
		node = node->next;
	}
	dopspace = (void*)malloc(sizeof(t_files));
	if (flags->isactivated_flags[4] == 1)
		ft_sort_time(tmp, flags, dopspace, i);
	else
		ft_sort_norm(tmp, flags, dopspace, i);
	ft_memdel(&dopspace);
}