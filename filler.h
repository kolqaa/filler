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

# define P1 'O'
# define P2 'X'
# define BEGINING_OF_THE_GAME 2016

typedef struct s_flist
{
	int x;
	int y;
	struct s_flist *next;
}				t_flist;

typedef struct s_fig
{
	char **figmap;
	char **map;
	int col;
	int row;
	int fd;
	int fcol;
	int frow;
	int flag_for_fig;
	int m;
	int f;
	int first_fig_done;
	int cenx;
	int ceny;
	t_flist *lst;
}				t_fig;


typedef t_fig t_map;
typedef t_map t_check;

typedef struct s_player
{
	char my_player;
	char op_player;
	int myx;
	int myy;
	int opx;
	int opy;
}				t_pla;

#endif
