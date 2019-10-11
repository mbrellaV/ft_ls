/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:55:17 by mbrella           #+#    #+#             */
/*   Updated: 2019/10/11 10:55:20 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			ft_parse_flags(char *str, t_args *flags)
{
	int		i;
	int		d;

	str++;
	while (*str)
	{
		i = 0;
		d = 0;
		while (i < COUNT_FLAGS)
		{
			if (*str == flags->flags[i] && ++d > 0)
				flags->isactivated_flags[i] = 1;
			i++;
		}
		if (d == 0)
			return (ft_error(*str));
		str++;
	}
	i = -1;
	while (i++ < COUNT_FLAGS)
		if (flags->isactivated_flags[i] == 1)
			return (1);
	return (0);
}

void		ft_show_dop(char *name, t_args *flags)
{
	t_files *node;
	char	*tmp;
	char	*tmp1;
	t_files	*dop;

	if (!(node = ft_show_dir(name, flags)))
		return (!ft_destroy_list(node) ? NULL : (void)0);
	dop = node;
	while (node && flags->isactivated_flags[1] == 1)
	{
		if (node->rights[0] == 'd' && (ft_strcmp(node->name, ".") != 0 &&
			ft_strcmp(node->name, "..") != 0))
			if (node->name[0] != '.' || flags->isactivated_flags[2])
			{
				tmp = ft_strjoin(name, node->name);
				ft_printf("\n%s:\n", tmp);
				tmp1 = tmp;
				tmp = ft_strjoin(tmp, "/");
				ft_strdel(&tmp1);
				ft_show_dop(tmp, flags);
				ft_strdel(&tmp);
			}
		node = node->next;
	}
	ft_destroy_list(dop);
}

void		ft_print_args(int i, char **argv, t_args *flags, int argc)
{
	char	c;
	char	*tmp;

	c = '\0';
	ft_sort_args(i, argv, argc);
	while (argv[i])
	{
		ft_printf("%c%s:\n", c, argv[i]);
		tmp = ft_strjoin(argv[i], "/");
		ft_show_dop(argv[i][ft_strlen(argv[i]) - 1] == '/' ?
				argv[i] : tmp, flags);
		ft_strdel(&tmp);
		c = '\n';
		i++;
	}
	exit(0);
}

int			main(int argc, char **argv)
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
		if (ft_parse_flags(argv[i], flags) == 0)
			break ;
	if (i == argc)
		ft_show_dop(dir_name, flags);
	else if (argc - i == 1 && (dir_name = ft_strjoin(argv[i], "/")))
	{
		ft_show_dop(dir_name, flags);
		ft_strdel(&dir_name);
	}
	else
		ft_print_args(i, argv, flags, argc);
	exit(0);
}

t_files		*ft_show_dir(char *dir_name, t_args *flags)
{
	struct dirent	*pdirent;
	DIR				*dire;
	t_files			*tmp;
	t_files			*dop;

	if (dir_name == NULL)
		return (ft_error(5) == 0 ? NULL : dop);
	if (!(dire = opendir(dir_name)))
	{
		ft_printf("ft_ls: %s: ", dir_name);
		ft_error(1);
		return (NULL);
	}
	pdirent = readdir(dire);
	if (!(tmp = ft_create_file(pdirent->d_name, tmp, dir_name)))
		return (ft_error(5) == 0 ? dop : NULL);
	dop = tmp;
	while ((pdirent = readdir(dire)) != NULL)
		if (!(tmp->next = ft_create_file(pdirent->d_name, tmp->next, dir_name))
		|| !(tmp = tmp->next))
			return (ft_error(5) == 0 ? dop : NULL);
	ft_sort_files(dop, flags);
	ft_display_files(dop, flags);
	closedir(dire);
	return (dop);
}
