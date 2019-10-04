
#include "../inc/ft_ls.h"

void		ft_count_tabs(t_files *node, t_args *flags, t_dop *dop, t_files *dopfile)
{
	int				blocks;

	while (node)
	{
		if (node->name[0] != '.' || (flags->isactivated_flags[2]))
			blocks += node->num_blocks;
		node = node->next;
	}
	ft_printf("total %d", blocks);
	node = dopfile;
	while (node)
	{
		if (node->name[0] != '.' || (flags->isactivated_flags[2]))
			if (ft_nbrlen(node->num_links) > dop->maxlink)
				dop->maxlink = ft_nbrlen(node->num_links);
		node = node->next;
	}
	node = dopfile;
	while (node)
	{
		if (node->name[0] != '.' || (flags->isactivated_flags[2]))
			if (ft_nbrlen(node->size) > dop->maxsize)
				dop->maxsize = ft_nbrlen(node->size);
		node = node->next;
	}
}

void	ft_print_dop_inf(t_files *node, t_args *flags)
{
	struct passwd	*dop;
	struct group	*dop1;
	time_t			time1;
	t_dop			*dop2;

	dop2 = (t_dop*)malloc(sizeof(t_dop));
	dop2->maxlink = 0;
	dop2->maxsize = 0;
	ft_count_tabs(node, flags, dop2, node);
	while (node)
	{
		dop = getpwuid(node->user);
		dop1 = getgrgid(node->group);
		time1 = node->time;
		if (node->name[0] != '.' || (flags->isactivated_flags[2]))
			ft_printf("\n%s  %p%d %s  %s  %p%d %s %s", node->permissions, dop2->maxlink - ft_nbrlen(node->num_links),
					node->num_links, dop->pw_name, dop1->gr_name, dop2->maxsize - ft_nbrlen(node->size),
					node->size, ft_strsub(ctime(&time1), 4, 12), node->name);
		//printf(" %d ", node->islink);
		if (node->permissions[0] == 'l')
			ft_printf(" -> %s", node->name_to_link);
		node = node->next;
	}
	ft_memdel((void**)(&dop2));
	ft_memdel((void**)(&dop));
	ft_memdel((void**)(&dop1));
}

/*void	ft_print_dop_inf(t_files *node, t_args *flags)
{
	struct passwd	*dop;
	struct group	*dop1;
	time_t			time1;

	while (node)
	{
		dop = getpwuid(node->user);
		dop1 = getgrgid(node->group);
		time1 = node->time;
		if (node->name[0] == '.' && flags->isactivated_flags[2])
			ft_printf("\n%s %d %s %s %d %s %s", node->permissions, node->num_links, dop->pw_name, dop1->gr_name, node->size, ctime(&time1), node->name);
		if (node->name[0] != '.')
			ft_printf("\n%s %d\t%s %s %d %s %s", node->permissions, node->num_links, dop->pw_name, dop1->gr_name, node->size, ft_strsub(ctime(&time1), 4, 12), node->name);
		node = node->next;
	}
}*/

void	ft_display_files(t_files *node, t_args *flags)
{
	if (flags->isactivated_flags[3] == 1)
		ft_print_dop_inf(node, flags);
	if (flags->isactivated_flags[3] == 0)
	{
		while (node->next)
		{
			//printf(" %s ", node->name);
			if (node->name[0] == '.' && flags->isactivated_flags[2])
				printf("%s\n", node->name);
			if (node->name[0] != '.')
				printf("%s\n", node->name);
			node = node->next;
		}
		if (node->name[0] != '.')
			printf("%s", node->name);
	}
}