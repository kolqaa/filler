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
# define DELTAX (map->col / 8)
# define DELTAY (map->row / 8)
# define SHIFTX (map->col / 2)
# define SHIFTY (map->row / 2)

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
	int Adiagx;
	int Adiagy;
	int Bdiagx;
	int Bdiagy;
	int ver;
	int hor;
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

int		ft_pow(int nb, int power);
int 	ft_sqrt(int nb);
void 	write_coor_in_lst(t_flist **lst, int i, int j, t_check *test);
void 	select_short_way_tocenr(t_flist **lst, t_map *map, t_pla *player, t_check *test);
void 	rebuild_myfig(t_fig *fig, t_check *test, t_pla *player);
int  	check_put(t_fig *fig, t_map *map, int i, int j, t_pla *player, t_check *test);
int  	take_cor_where_to_put(t_fig *fig, t_map *map, t_pla *player, t_check *test);
void  	put_my_fig(t_fig *fig, t_pla *player, t_map *map, t_check *test);
char    get_player(char *str, t_pla *player);
void	get_map_size(char **line, t_map *map);
void	take_figure_size(char *line, struct s_fig *fig);
void	take_cordin_myplayer(t_map *map, t_pla *player, t_check *test);
void	struct_init(t_map *map, t_pla *player, t_fig *fig);
void	reset_all_value(t_map *map, t_fig *fig);
void 	short_way_to_diagA(t_flist **lst, t_map *map, t_pla *player, t_check *test);
void 	short_way_to_diagB(t_flist **lst, t_map *map, t_pla *player, t_check *test);
void	analyze_fig(t_fig *fig, t_map *map, t_check *test);


#endif
