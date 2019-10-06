/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:08:59 by mbrella           #+#    #+#             */
/*   Updated: 2019/10/06 18:20:10 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			do_acl(t_files *node, char *filename)
{
	ssize_t	xattr;

	node->name_to_link = (char*)malloc(1024);
	ft_bzero(node->name_to_link, sizeof(node->name_to_link));
	if (node->rights[0] == 'l')
		if (readlink(filename, node->name_to_link, 1023) < 0)
			perror("readlink");
	xattr = 0;
	xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		node->rights[10] = '@';
	else
		node->rights[10] = ' ';
	return (0);
}

void		dop_files(t_files *node, struct stat *buf, char *tmp)
{
	if (S_ISDIR(buf->st_mode))
		node->rights[0] = 'd';
	else if (S_ISLNK(buf->st_mode))
		node->rights[0] = 'l';
	else if (S_ISCHR(buf->st_mode))
		node->rights[0] = 'c';
	else if (S_ISBLK(buf->st_mode))
		node->rights[0] = 'b';
	else if (S_ISFIFO(buf->st_mode))
		node->rights[0] = 'f';
	else if (S_ISSOCK(buf->st_mode))
		node->rights[0] = 's';
	else
		node->rights[0] = '-';
	node->rights[1] = (buf->st_mode & S_IRUSR) ? 'r' : '-';
	node->rights[2] = (buf->st_mode & S_IWUSR) ? 'w' : '-';
	node->rights[3] = (buf->st_mode & S_IXUSR) ? 'x' : '-';
	node->rights[4] = (buf->st_mode & S_IRGRP) ? 'r' : '-';
	node->rights[5] = (buf->st_mode & S_IWGRP) ? 'w' : '-';
	node->rights[6] = (buf->st_mode & S_IXGRP) ? 'x' : '-';
	node->rights[7] = (buf->st_mode & S_IROTH) ? 'r' : '-';
	node->rights[8] = (buf->st_mode & S_IWOTH) ? 'w' : '-';
	node->rights[9] = (buf->st_mode & S_IXOTH) ? 'x' : '-';
}

t_files		*ft_create_file(char *file, t_files *node, char *full_name)
{
	struct stat	*buf;
	char		*tmp;

	node = (t_files*)malloc(sizeof(t_files));
	buf = (struct stat*)malloc(sizeof(struct stat));
	node->next = NULL;
	node->name = (char*)malloc(ft_strlen(file) + 1);
	ft_strncpy(node->name, file, ft_strlen(file) + 1);
	tmp = ft_strjoin(full_name, file);
	if ((lstat(tmp, buf)) == -1)
		ft_error(3);
	node->size = buf->st_size;
	node->num_links = buf->st_nlink;
	node->user = buf->st_uid;
	node->group = buf->st_gid;
	node->rights = (char*)malloc(12);
	node->rights[11] = '\0';
	do_acl(node, tmp);
	node->time = buf->st_mtimespec.tv_sec;
	node->num_blocks = buf->st_blocks;
	dop_files(node, buf, tmp);
	node->islink = S_ISLNK(buf->st_mode) ? 1 : 0;
	free(buf);
	ft_strdel(&tmp);
	return (node);
}

void		ft_destroy_list(t_files *node)
{
	t_files *tmp;

	while (node)
	{
		tmp = node->next;
		ft_strdel(&node->name);
		ft_strdel(&node->rights);
		ft_strdel(&node->name_to_link);
		free(node);
		node = tmp;
	}
}

t_args		*ft_create_args(t_args *node)
{
	int i;

	i = 0;
	node = (t_args*)malloc(sizeof(t_args));
	node->flags = "rRalt1";
	while (i < COUNT_FLAGS)
	{
		node->isactivated_flags[i] = 0;
		i++;
	}
	return (node);
}
