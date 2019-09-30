
#include "ft_ls.h"

void	ft_display_files(t_files *node)
{
	while (node)
	{
		if (node->name[0] != '.')
			printf("%s\t\t", node->name);
		node = node->next;
	}
}