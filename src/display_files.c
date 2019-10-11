/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:56:32 by mbrella           #+#    #+#             */
/*   Updated: 2019/10/11 10:56:45 by mbrella          ###   ########.fr       */
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

void		ft_display_files_rev(t_files *node, t_args *flags)
{
	if (node == NULL)
		return ;
	if ((node->name[0] != '.' || flags->isactivated_flags[2]) &&
		!flags->isactivated_flags[0])
		ft_printf("%s\n", node->name);
	ft_display_files_rev(node->next, flags);
	if ((node->name[0] != '.' || flags->isactivated_flags[2]) &&
		flags->isactivated_flags[0])
		ft_printf("%s\n", node->name);
}

void		ft_display_files_dop_rev(t_files *node, t_args *flags, t_dop *dop2)
{
	char			*tmp;

	if (node == NULL)
		return ;
	if (flags->isactivated_flags[0] == 1)
		ft_display_files_dop_rev(node->next, flags, dop2);
	if (node->name[0] != '.' || (flags->isactivated_flags[2]))
		dop_print(node, flags, dop2);
	if (node->rights[0] == 'l')
		ft_printf(" -> %s", node->name_to_link);
	if (flags->isactivated_flags[0] == 0)
		ft_display_files_dop_rev(node->next, flags, dop2);
}

void		ft_display_files(t_files *node, t_args *flags)
{
	t_dop	*dop2;

	if (flags->isactivated_flags[3])
	{
		dop2 = (t_dop*)malloc(sizeof(t_dop));
		dop2->maxlink = 0;
		dop2->maxsize = 0;
		ft_count_tabs(node, flags, dop2, node);
		ft_display_files_dop_rev(node, flags, dop2);
		ft_memdel((void**)(&dop2));
		ft_printf("\n");
	}
	else
		ft_display_files_rev(node, flags);
}
