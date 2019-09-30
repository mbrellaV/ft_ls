//
// Created by Miss Brella on 30/09/2019.
//

#ifndef FT_LS_FT_LS_H
#define FT_LS_FT_LS_H


#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

typedef struct 		s_args
{

}					t_args;



typedef struct		s_files
{
	char			*name;
	struct s_files	*next;
}					t_files;



t_files		*ft_node_push_forward(char *file, t_files *node);
t_files		*ft_create_file(char *file);
void		ft_display_files(t_files *node);
void	ft_sort_files(t_files *node);

#endif //FT_LS_FT_LS_H
