/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:22:05 by mbrella           #+#    #+#             */
/*   Updated: 2019/10/06 18:29:42 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		ft_count_tabs(t_files *node, t_args *flags,
		t_dop *dop, t_files *dopfile)
{
	int		blocks;
	int		i;

	i = 0;
	blocks = 0;
	while (node)
	{
		if ((node->name[0] != '.' || flags->isactivated_flags[2]) && (++i > 0))
			blocks += node->num_blocks;
		node = node->next;
	}
	if (i != 0 || flags->isactivated_flags[2])
		ft_printf("total %d", blocks);
	node = dopfile;
	while (node)
	{
		if (node->name[0] != '.' || (flags->isactivated_flags[2]))
		{
			if (ft_nbrlen(node->num_links) > dop->maxlink)
				dop->maxlink = ft_nbrlen(node->num_links);
			if (ft_nbrlen(node->size) > dop->maxsize)
				dop->maxsize = ft_nbrlen(node->size);
		}
		node = node->next;
	}
}

void		ft_print_dop_inf(t_files *node, t_args *flags)
{
	struct passwd	*dop;
	struct group	*dop1;
	t_dop			*dop2;
	char			*tmp;

	dop2 = (t_dop*)malloc(sizeof(t_dop));
	dop->maxlink = 0;
	dop->maxsize = 0;
	ft_count_tabs(node, flags, dop2, node);
	while (node)
	{
		dop = getpwuid(node->user);
		dop1 = getgrgid(node->group);
		tmp = ft_strsub(ctime(&node->time), 4, 12);
		if (node->name[0] != '.' || (flags->isactivated_flags[2]))
			ft_printf("\n%s %p%d %s  %s  %p%d %s %s", node->rights,
			dop2->maxlink, ft_nbrlen(node->num_links),
			node->num_links, dop->pw_name, dop1->gr_name, dop2->maxsize,
			ft_nbrlen(node->size), node->size, tmp, node->name);
		if (node->rights[0] == 'l')
			ft_printf(" -> %s", node->name_to_link);
		node = node->next;
	}
	ft_printf("\n");
	ft_memdel((void**)(&dop2));
}

void		ft_display_files(t_files *node, t_args *flags)
{
	if (flags->isactivated_flags[3] == 1)
		ft_print_dop_inf(node, flags);
	if (flags->isactivated_flags[3] == 0)
	{
		while (node->next)
		{
			if (node->name[0] == '.' && flags->isactivated_flags[2])
				ft_printf("%s\n", node->name);
			if (node->name[0] != '.')
				ft_printf("%s\n", node->name);
			node = node->next;
		}
		if (node->name[0] != '.' || flags->isactivated_flags[2])
			ft_printf("%s\n", node->name);
	}
}
