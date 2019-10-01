
#include "ft_ls.h"

void	ft_display_files(t_files *node, t_args *flags)
{
	while (node)
	{
		if (node->name[0] == '.' && flags->isactivated_flags[2])
			printf("%s\t", node->name);
		if (node->name[0] != '.')
			printf("%s\t", node->name);
		node = node->next;
	}
}