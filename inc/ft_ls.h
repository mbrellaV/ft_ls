//
// Created by Miss Brella on 30/09/2019.
//

#ifndef FT_LS_FT_LS_H
#define FT_LS_FT_LS_H


#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../libft/libft.h"
#include "pwd.h"
#include "grp.h"
#include "time.h"
#include <sys/xattr.h>

# define COUNT_FLAGS 7

typedef struct		s_dop
{
	int				maxlink;
	int				maxsize;
}					t_dop;

typedef struct		s_args
{
	char	*flags;
	int		isactivated_flags[COUNT_FLAGS];
}					t_args;

typedef struct		s_files
{
	char			*name;
	char			*permissions;
	char			type;
	int				num_links;
	int				size;
	char			islink;
	unsigned int	user;
	unsigned int	group;
	int				time;
	int 			num_blocks;
	char			*name_to_link;
	struct s_files	*next;
}					t_files;

void	ft_sort_args(int i, char **argv, int argc);
int					ft_error(int error);
void				ft_destroy_list(t_files *node);
t_files				*ft_show_dir(char	*dir_name, t_args *flags);
t_args				*ft_create_args(t_args *node);
t_files				*ft_node_push_forward(char *file, t_files *node);
t_files				*ft_create_file(char *file, t_files *node, char *full_name);
void				ft_display_files(t_files *node, t_args *flags);
void				ft_sort_files(t_files *node, t_args *flags);

#endif //FT_LS_FT_LS_H
