/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:25:06 by mbrella           #+#    #+#             */
/*   Updated: 2019/10/11 11:25:08 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_Ls.h"

void	ft_print_usage(void)
{
	ft_printf("usage: ls [-altrR1] [file ...]\n");
	exit(1);
}

int		ft_error(int error)
{
	if (error == 1)
		perror("");
	if (error == 5)
	{
		ft_printf("malloc error");
		return (0);
	}
	if (error == 3)
		perror("ls: ");
	if (error >= 32)
	{
		ft_printf("ft_ls: illegal option -- %c\n", error);
		ft_print_usage();
	}
	return (0);
}

void	dop_print(t_files *node, t_args *flags, t_dop *dop2)
{
	struct passwd	*dop;
	struct group	*dop1;

	dop = getpwuid(node->user);
	dop1 = getgrgid(node->group);
	if (node->rights[0] == 'b' || node->rights[0] == 'c')
		ft_printf("\n%s %p%d %s  %s  %d, %d ", node->rights, dop2->maxlink -
		ft_nbrlen(node->num_links), node->num_links, dop->pw_name,
		dop1->gr_name, major(node->st_rdev), minor(node->st_rdev));
	else
		ft_printf("\n%s %p%d %s  %s  %p%d ", node->rights, dop2->maxlink -
		ft_nbrlen(node->num_links), node->num_links, dop->pw_name,
		dop1->gr_name, dop2->maxsize - ft_nbrlen(node->size), node->size);
	if (ft_labs(time(0) - node->time) < 15811200)
		ft_printf("%s5 i16 %s", ctime(&node->time), node->name);
	else
		ft_printf("%s5 i10  %s21i24  %s", ctime(&node->time),
			ctime(&node->time), node->name);
}
