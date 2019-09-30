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



int main (int argc, char *argv[]) {
	struct dirent *pDirent;
	DIR *pDir;
	t_files *tmp;
	t_files *dop;

	if (argc < 2)
		argv[1] = ".";
	pDir = opendir (argv[1]);
	if (pDir == NULL) {
		printf ("Cannot open directory '%s'\n", argv[1]);
		return 1;
	}
	pDirent = readdir(pDir);
	printf("%s", pDirent->d_name);
	tmp = ft_create_file(pDirent->d_name);
	dop = tmp;
	printf("f: %s ", dop->name);
	while ((pDirent = readdir(pDir)) != NULL)
	{
		tmp = ft_node_push_forward(pDirent->d_name, tmp);
		printf("%s ", tmp->name);
	}
	printf(" str: %s ", dop->name);
	while (dop)
	{
		//if (dop->name[0] != '.')
		printf("%s\t\t", dop->name);
		dop = dop->next;
	}
	//ft_sort_files(dop);
	//ft_display_files(dop);
	printf("\n");
	closedir (pDir);
	return 0;
}