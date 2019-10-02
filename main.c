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

#include "ft_ls.h"

void	ft_print_usage()
{
	printf("usage: ft_ls [flags] dir");
	exit(0);
}

void	ft_error(int error)
{
	exit(0);
}

int		ft_parse_flags(char *str, t_args *flags)
{
	int		i;

	i = 0;
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
	return (0);
}

void	ft_show_dop(char *name, t_args *flags)
{
	if (flags->isactivated_flags[1] == 0)
	{
		ft_show_dir(name, flags);
		exit(0);
	}
	if (flags->isactivated_flags[1] == 1)
	{
		printf("%s", name);
	}
}

int main (int argc, char **argv)
{
	char	*dir_name;
	int		i;
	t_args	*flags;

	i = 1;
	dir_name = ".";
	flags = ft_create_args(flags);
	if (argc == 1)
	{
		ft_show_dir(".", flags);
		exit(0);
	}
	if (argv[argc - 1][0] == '-')
		ft_parse_flags(argv[argc - 1], flags);
	else
		dir_name = argv[argc - 1];
	while (i < argc - 1)
	{
		if (argv[i][0] == '-')
			ft_parse_flags(argv[i], flags);
		else
			ft_print_usage();
		i++;
	}
	ft_show_dop(dir_name, flags);
	return (0);
}

void	ft_show_dir(char *dir_name, t_args *flags)
{
	struct dirent *pDirent;
	DIR *pDir;
	t_files *tmp;
	t_files *dop;

	pDir = opendir (dir_name);
	if (pDir == NULL)
		ft_error(2);
	pDirent = readdir(pDir);
	tmp = ft_create_file(pDirent->d_name, tmp);
	dop = tmp;
	while ((pDirent = readdir(pDir)) != NULL)
	{
		tmp->next = ft_create_file(pDirent->d_name, tmp->next);
		tmp = tmp->next;
	}
	ft_sort_files(dop, flags);
	ft_display_files(dop, flags);
	printf("\n");
	closedir (pDir);
}