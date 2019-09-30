//
// Created by Miss Brella on 30/09/2019.
//

#ifndef FT_LS_FT_LS_H
#define FT_LS_FT_LS_H


#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct 		s_args
{

}					t_args;



typedef struct		s_files
{
	char			*name;
	struct t_files	*next;
}					t_files;



void		ft_node_push_forward(char *file, t_files *node);
t_files		*ft_create_file(char *file);

#endif //FT_LS_FT_LS_H
