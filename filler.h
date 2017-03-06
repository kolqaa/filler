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
# define DELTAX (data->col / 8)
# define DELTAY (data->row / 8)
# define SHIFTX (data->col / 2)
# define SHIFTY (data->row / 2)

typedef struct s_flist
{
	int x;
	int y;
	struct s_flist *next;
}				t_flist;

typedef struct s_data
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
	int Adiagx;
	int Adiagy;
	int Bdiagx;
	int Bdiagy;
	int ver;
	int hor;
	t_flist *lst;
	char my_player;
	char op_player;
	int myx;
	int myy;
	int opx;
	int opy;
	int exist;
}				t_data;

int		ft_pow(int nb, int power);
int 	ft_sqrt(int nb);
void 	write_coor_in_lst(t_flist **lst, int i, int j, t_data *data);
void 	select_short_way_tocenr(t_flist **lst, t_data *data);
void 	rebuild_myfig(t_data *data);
int 	check_put(t_data *data, int i, int j);
int 	take_cor_where_to_put(t_data *data);
void 	put_my_fig(t_data *data);
char   	get_player(char *str, t_data *data);
void	get_map_size(char **line, t_data *data);
void	take_figure_size(char *line, t_data *data);
void 	take_cordin_myplayer(t_data *data);
void 	struct_init(t_data *data);
void 	reset_all_value(t_data *data);
void 	short_way_to_diagA(t_flist **lst, t_data *data);
void 	short_way_to_diagB(t_flist **lst, t_data *data);
void 	analyze_fig(t_data *data);


#endif
