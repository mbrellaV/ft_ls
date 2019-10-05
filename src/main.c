/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:31:27 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/30 14:31:29 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_print_usage()
{
	printf("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
	exit(0);
}

int		ft_error(int error)
{
	if (error == 1)
		perror("");
	if (error == 3)
		perror("ft_ls: ");
	return (0);
}

int		ft_parse_flags(char *str, t_args *flags)
{
	int		i;

	str++;
	while (*str)
	{
		i = 0;
		while (i < COUNT_FLAGS)
		{
			if (*str == flags->flags[i])
				flags->isactivated_flags[i] = 1;
			i++;
		}
		str++;
	}
	i = 0;
	while (i++ < COUNT_FLAGS)
		if (flags->isactivated_flags[i] == 1)
			return (1);
	ft_print_usage();
	return (0);
}

void	ft_show_dop(char *name, t_args *flags)
{
	t_files *node;
	char	*tmp;
	char	*tmp1;
	t_files	*dop;

	if (!(node = ft_show_dir(name, flags)))
		return ;
	dop = node;
	if (flags->isactivated_flags[1] == 1)
	{
		while (node)
		{
			if (node->permissions[0] == 'd' && (ft_strcmp(node->name, ".") != 0 && ft_strcmp(node->name, "..") != 0))
			{
				if (node->name[0] != '.' || (flags->isactivated_flags[2] && node->name[0] == '.'))
				{
					tmp = ft_strjoin(name, node->name);
					printf("\n%s:\n", tmp);
					tmp1 = tmp;
					tmp = ft_strjoin(tmp, "/");
					ft_strdel(&tmp1);
					ft_show_dop(tmp, flags);
					ft_strdel(&tmp);
				}
			}
			node = node->next;
		}
	}
	ft_destroy_list(dop);
}

void	ft_print_args(int i, char **argv, t_args *flags, int argc)
{
	char c;

	c = '\0';
	if (i == argc)
	{
		ft_destroy_list(ft_show_dir(argv[i], flags));
		exit(0);
	}
	printf("d: %s ", argv[i]);
	ft_sort_args(i, argv, argc);
	printf("2: %s ", argv[i]);
	printf("2: %s ", argv[i + 1]);
	while (argv[i])
	{
		if (opendir (argv[i]))
		{
			ft_printf("%c%s:\n", c, argv[i]);
			ft_show_dop(argv[i][ft_strlen(argv[i]) - 1] == '/' ? argv[i] : ft_strjoin(argv[i], "/"), flags);
			c = '\n';
		}
		else
			ft_error(1);
		i++;
	}
	exit(0);
}

int main (int argc, char **argv)
{
	char	*dir_name;
	int		i;
	t_args	*flags;

	i = 0;
	dir_name = "./";
	flags = ft_create_args(flags);
	if (argc == 1)
	{
		ft_destroy_list(ft_show_dir(dir_name, flags));
		exit(0);
	}
	while (++i < argc && argv[i][0] == '-')
		ft_parse_flags(argv[i], flags);
	if (i == argc)
		ft_show_dop(dir_name, flags);
	else if (argc - i == 1)
	{
		ft_show_dop(ft_strjoin(argv[i], "/"), flags);
		exit(0);
	}
	else
		ft_print_args(i, argv, flags, argc);
	exit(0);
}

t_files		*ft_show_dir(char *dir_name, t_args *flags)
{
	struct dirent *pDirent;
	DIR *pDir;
	t_files *tmp;
	t_files *dop;
	int i = 0;

	if (!(pDir = opendir (dir_name)))
	{
		ft_printf("ft_ls: %s: ", ft_strsub(dir_name, 0, ft_strlen(dir_name) - 1));
		ft_error(1);
		return (NULL);
	}
	pDirent = readdir(pDir);
	tmp = ft_create_file(pDirent->d_name, tmp, pDirent->d_name);
	dop = tmp;
	while ((pDirent = readdir(pDir)) != NULL)
	{
		i++;
		ft_printf(" %d ", i);
		tmp->next = ft_create_file(pDirent->d_name, tmp->next, dir_name);
		tmp = tmp->next;
	}
	ft_sort_files(dop, flags);
	ft_display_files(dop, flags);
	printf("\n");
	closedir (pDir);
	return (dop);
}