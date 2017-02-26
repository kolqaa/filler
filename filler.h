//
// Created by Nick Simonov on 2/24/17.
//

#ifndef FT_FILLER_H
# define FT_FILLER_H
# include <fcntl.h>
# include <libc.h>
# include <stdlib.h>
# include "libft/libft.h"

# define P1 'O'
# define P2 'X'

typedef struct s_fig
{
	char **figmap;
	char **map;
	int col;
	int row;
}				t_fig;

typedef t_fig t_map;

typedef struct s_player
{
	int my_player;
	int op_player;
}				t_player;
#endif
