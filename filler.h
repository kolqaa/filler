//
// Created by Nick Simonov on 2/24/17.
//

#ifndef FT_FILLER_H
# define FT_FILLER_H
# include <fcntl.h>
# include <libc.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

# define P1 'o'
# define P2 'x'

typedef struct s_fig
{
	char **fig;
	char **map;
	int col;
	int row;
	int fd;
	int fcol;
	int frow;
}				t_fig;


typedef t_fig t_map;
typedef t_map t_check;

typedef struct s_player
{
	char my_player;
	char op_player;
}				t_pla;
#endif
