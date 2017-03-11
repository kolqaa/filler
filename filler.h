/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:58:01 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/11 14:09:12 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H
# include <fcntl.h>
# include <libc.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

# define P1 'O'
# define P2 'X'
# define DELTAX	(data->col / 6)
# define DELTAY	(data->row / 6)
# define SHIFTX	(data->col / 4)
# define SHIFTY	(data->row / 3)

typedef struct			s_flist
{
	int				x;
	int				y;
	struct s_flist	*next;
}						t_flist;

typedef struct			s_data
{
	char	**figmap;
	char	**map;
	int		col;
	int		row;
	int		fd;
	int		fcol;
	int		frow;
	int		flag_for_fig;
	int		m;
	int		f;
	int		first_fig_done;
	int		cenx;
	int		ceny;
	int		adiagx;
	int		adiagy;
	int		bdiagx;
	int		bdiagy;
	int		ver;
	int		hor;
	t_flist	*lst;
	char	my_player;
	char	op_player;
	int		myx;
	int		myy;
	int		opx;
	int		opy;
	int		opstartdown;
	int		count;
}						t_data;

int						ft_atoi(const char *str);
void					ft_memdel(void **ap);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strnew(size_t size);
char					*ft_strstr(const char *big, const char *little);
void					*ft_memset(void *b, int c, size_t len);
size_t					ft_strlen(const char *s);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
int						ft_pow(int nb, int power);
int						ft_sqrt(int nb);
void					write_coor_in_lst(t_flist **lst, int i, int j);
void					rebuild_myfig(t_data *data);
void					check_put(t_data *data, int i, int j, int newi);
int						take_cor_where_to_put(t_data *data);
void					put_my_fig(t_data *data);
char					get_player(char *str, t_data *data);
void					get_map_size(char **line, t_data *data);
void					take_figure_size(char *line, t_data *data);
void					take_cordin_myplayer(t_data *data);
void					struct_init(t_data *data);
void					reset_all_value(t_data *data);
void					analyze_fig(t_data *data);
void					copy_map(char *line, t_data *data);
void					copy_figure(char *line, t_data *data);
void					short_way_to_diaga(t_flist **lst, t_data *data);
void					short_way_to_diagb(t_flist **lst, t_data *data);
void					select_short_way_tocenr(t_flist **lst, t_data *data);
void					select_short_way_enemy(t_flist **lst, t_data *data);
int						right_side_closed(t_data *data);
int						down_side_closed(t_data *data);
int						in_center(t_data *data);
int						left_side_closed(t_data *data);
int						up_side_closed(t_data *data);
int						ft_sqrt(int nb);
int						ft_pow(int nb, int power);

#endif
