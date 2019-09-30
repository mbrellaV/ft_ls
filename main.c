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

	if (argc < 2)
		argv[1] = ".";
	pDir = opendir (argv[1]);
	if (pDir == NULL) {
		printf ("Cannot open directory '%s'\n", argv[1]);
		return 1;
	}
	while ((pDirent = readdir(pDir)) != NULL)
	{
		if (pDirent->d_name[0] != '.')
			printf("%s\t\t", pDirent->d_name);
	}
	printf("\n");
	closedir (pDir);
	return 0;
}