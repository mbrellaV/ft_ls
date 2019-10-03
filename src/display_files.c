
#include "../inc/ft_ls.h"

void	ft_print_dop_inf(t_files *node, t_args *flags)
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
}

void	ft_display_files(t_files *node, t_args *flags)
{
	if (flags->isactivated_flags[3] == 1)
		ft_print_dop_inf(node, flags);
	if (flags->isactivated_flags[3] == 0)
	{
		while (node->next)
		{
			if (node->name[0] == '.' && flags->isactivated_flags[2])
				printf("%s\n", node->name);
			if (node->name[0] != '.')
				printf("%s\n", node->name);
			node = node->next;
		}
		printf("%s", node->name);
	}
}