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
#include "../inc/ft_ls.h"

void	dop_files(t_files *node, struct stat *buf)
{
	if (S_ISDIR(buf->st_mode))
		node->permissions[0] = 'd';
	else if (S_ISLNK(buf->st_mode))
		node->permissions[0] = 'l';
	else if (S_ISCHR(buf->st_mode))
		node->permissions[0] = 'c';
	else if (S_ISBLK(buf->st_mode))
		node->permissions[0] = 'b';
	else if (S_ISFIFO(buf->st_mode))
		node->permissions[0] = 'f';
	else if (S_ISSOCK(buf->st_mode))
		node->permissions[0] = 's';
	else
		node->permissions[0] = '-';
	node->permissions[1] = (buf->st_mode & S_IRUSR) ? 'r' : '-';
	node->permissions[2] = (buf->st_mode & S_IWUSR) ? 'w' : '-';
	node->permissions[3] = (buf->st_mode & S_IXUSR) ? 'x' : '-';
	node->permissions[4] = (buf->st_mode & S_IRGRP) ? 'r' : '-';
	node->permissions[5] = (buf->st_mode & S_IWGRP) ? 'w' : '-';
	node->permissions[6] = (buf->st_mode & S_IXGRP) ? 'x' : '-';
	node->permissions[7] = (buf->st_mode & S_IROTH) ? 'r' : '-';
	node->permissions[8] = (buf->st_mode & S_IWOTH) ? 'w' : '-';
	node->permissions[9] = (buf->st_mode & S_IXOTH) ? 'x' : '-';
}



/*t_files		*ft_create_file(char *file, t_files *node, char *full_name)
{
	struct stat *buf;

	node = (t_files*)malloc(sizeof(t_files));
	buf = (struct stat*)malloc(sizeof(struct stat));
	node->next = NULL;

	node->name = (char*)malloc(strlen(file));
	ft_strlcat(node->name, file, strlen(file) + 1);
	//printf(" str: %s ", full_name);
	stat(ft_strjoin(full_name, file), buf);
	node->size = buf->st_size;
	node->num_links = buf->st_nlink;
	node->user = buf->st_uid;
	node->group = buf->st_gid;
	node->type = S_ISDIR(buf->st_mode) ? 'd' : (S_ISLNK(buf->st_mode) ? 'l' : '-');
	node->permissions = (char*)malloc(10);
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
	node->time = buf->st_mtimespec.tv_sec;
	return (node);
}*/

t_files		*ft_create_file(char *file, t_files *node, char *full_name)
{
	struct stat *buf;
	char		*tmp;

	node = (t_files*)malloc(sizeof(t_files));
	buf = (struct stat*)malloc(sizeof(struct stat));
	node->next = NULL;
	node->name = (char*)malloc(ft_strlen(file) + 1);
	ft_strncpy(node->name, file, ft_strlen(file) + 1);
	tmp = ft_strjoin(full_name, file);
	lstat(tmp, buf);
	ft_strdel(&tmp);
	node->size = buf->st_size;
	node->num_links = buf->st_nlink;
	node->user = buf->st_uid;
	node->group = buf->st_gid;
	//node->type = S_ISDIR(buf->st_mode) ? 'd' : (S_ISLNK(buf->st_mode) ? 'l' : (S_ISCHR(buf->st_mode) ? 'l' : (S_ISBLK(buf->st_mode) ? 'l' : (S_ISFIFO(buf->st_mode) ? 'f' : (S_ISSOCK(buf->st_mode) ? 'l' : '-')))));
	node->permissions = (char*)malloc(10);
	node->time = buf->st_mtimespec.tv_sec;
	node->num_blocks = buf->st_blocks;
	dop_files(node, buf);
	node->islink = S_ISLNK(buf->st_mode) ? 1 : 0;
	//node->name_to_link = (char*)malloc(node->size + 1);
	//if (node->islink)
		//printf(" %d ", node->size);
		//readlink(node->name,node->name_to_link, node->size);
	//node->name_to_link[node->size] = '\0';
	//printf(" %d ", S_ISLNK(buf->st_mode) ? 1 : 0);
	//node->name_to_link = buf->;
	free(buf);
	return (node);
}

void	ft_destroy_list(t_files *node)
{
	t_files *tmp;

	tmp = node;
	while (node)
	{
		tmp = node->next;
		ft_strdel(&node->name);
		ft_strdel(&node->permissions);
		free(node);
		node = tmp;
	}
}

t_args		*ft_create_args(t_args *node)
{
	int i;

	i = 0;
	node =  (t_args*)malloc(sizeof(t_args));
	node->flags = "rRalt";
	while (i < COUNT_FLAGS)
	{
		node->isactivated_flags[i] = 0;
		i++;
	}
	return (node);
}