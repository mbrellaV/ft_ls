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

#include "ft_ls.h"

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);

}

void	ft_sort_files(t_files *node)
{
	t_files	*tmp;
	int		i;
	int		cn;
	char	*dopstr;

	i = 0;
	cn = 0;
	tmp = node;
	while (node)
	{
		i++;
		printf("%s", node->name);
		node = node->next;
	}
	while (cn < i)
	{
		node = tmp;
		while (node)
		{
			printf("%s", node->name);
			if (ft_strcmp(node->name, node->next->name) < 0)
			{
				dopstr = node->name;
				node->name = node->next->name;
				node->next->name = dopstr;
			}
			node = node->next;
		}
		cn++;
	}
}