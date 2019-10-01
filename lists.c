/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:50:58 by mbrella           #+#    #+#             */
/*   Updated: 2019/09/30 15:51:01 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"

t_files		*ft_create_file(char *file, t_files *node)
{
	struct stat *buf;
	node = (t_files*)malloc(sizeof(t_files));
	buf = (struct stat*)malloc(sizeof(struct stat));
	node->next = NULL;
	stat(file, buf);
	//node->name = (char*)malloc(strlen(file));
	strlcat(node->name, file, strlen(file));
	node->size = buf->st_size;
	node->num_links = buf->st_nlink;
	node->user = buf->st_uid;
	node->group = buf->st_gid;
	node->type = S_ISDIR(buf->st_mode) ? "d" : (S_ISLNK(buf->st_mode) ? "l" : '-');
	node->permissions = "----------";
	node->permissions[0] = node->type;
	node->permissions[1] = (buf->st_mode & S_IRUSR) ? 'r' : '-';
	node->permissions[2] = (buf->st_mode & S_IWUSR) ? 'w' : '-';
	node->permissions[3] = (buf->st_mode & S_IXUSR) ? 'x' : '-';
	node->permissions[4] = (buf->st_mode & S_IRGRP) ? 'r' : '-';
	node->permissions[5] = (buf->st_mode & S_IWGRP) ? 'w' : '-';
	node->permissions[6] = (buf->st_mode & S_IXGRP) ? 'x' : '-';
	node->permissions[7] = (buf->st_mode & S_IROTH) ? 'r' : '-';
	node->permissions[8] = (buf->st_mode & S_IWOTH) ? 'w' : '-';
	node->permissions[9] = (buf->st_mode & S_IXOTH) ? 'x' : '-';
	return (node);
}

t_args		*ft_create_args(t_args *node)
{
	int i;

	i = 0;
	node =  (t_args*)malloc(sizeof(t_args));
	node->flags = "rRalt";
	while (i++ < COUNT_FLAGS)
		node->isactivated_flags[i] = 0;
	return (node);
}

t_files		*ft_node_push_forward(char *file, t_files *node)
{
	if (!node)
	{
		//ft_create_file(file);
		return (NULL);
	}
	node->next = ft_create_file(file, node);
	return (node->next);
}