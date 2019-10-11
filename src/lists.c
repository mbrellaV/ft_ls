/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:57:59 by mbrella           #+#    #+#             */
/*   Updated: 2019/10/11 10:58:01 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			do_acl(t_files *node, char *filename, struct stat *buf)
{
	ssize_t	xattr;

	ft_bzero(node->name_to_link, sizeof(node->name_to_link));
	if (node->rights[0] == 'l')
		if (readlink(filename, node->name_to_link, 1023) < 0)
			perror("readlink");
	node->st_rdev = buf->st_rdev;
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
	node->num_links = buf->st_nlink;
}

t_files		*ft_create_file(char *file, t_files *node, char *full_name)
{
	struct stat	*buf;
	char		*tmp;

	if (!(node = (t_files*)malloc(sizeof(t_files)))
		|| !(buf = (struct stat*)malloc(sizeof(struct stat)))
		|| !(node->name = (char*)malloc(ft_strlen(file) + 1))
		|| !(tmp = ft_strjoin(full_name, file))
		|| !(node->rights = (char*)malloc(12))
		|| !(node->name_to_link = (char*)malloc(1024)))
		return (ft_error(5) == 0 ? NULL : node->next);
	ft_strncpy(node->name, file, ft_strlen(file) + 1);
	node->next = NULL;
	if ((lstat(tmp, buf)) == -1)
		ft_error(3);
	node->size = buf->st_size;
	node->user = buf->st_uid;
	node->group = buf->st_gid;
	node->time = buf->st_mtimespec.tv_sec;
	node->num_blocks = buf->st_blocks;
	node->rights[11] = '\0';
	dop_files(node, buf, tmp);
	do_acl(node, tmp, buf);
	free(buf);
	ft_strdel(&tmp);
	return (node);
}

int			ft_destroy_list(t_files *node)
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
	return (0);
}

t_args		*ft_create_args(t_args *node)
{
	int i;

	i = 0;
	if (!(node = (t_args*)malloc(sizeof(t_args))))
		return (NULL);
	node->flags = "rRalt1";
	while (i < COUNT_FLAGS)
	{
		node->isactivated_flags[i] = 0;
		i++;
	}
	return (node);
}
