/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:47:39 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/24 16:47:39 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

void	fig_to_myplayer(t_fig *fig, t_check *test, t_pla *player)
{
	int i;
	int j;

	i = 0;
	while (fig->figmap[i])
	{
		j = 0;
		while (fig->figmap[i][j])
		{
			if (fig->figmap[i][j] == '*')
				fig->figmap[i][j] = player->my_player;
			if (fig->figmap[i][j] == '.')
				fig->figmap[i][j] = ',';
			j++;
		}
		i++;
	}
}

int check_put(char **figmap, char **map, int i, int j, t_pla *player, t_check *test)
{
	ft_putstr_fd("check_put\n", test->fd);
	int x;
	int y;
	int newi;
	int newj;

	newi = i;
	newj = j;
	x = 0;
	while (figmap[x])
	{
		y = 0;
		while (figmap[x][y])
		{
			if (map[newi][newj] == figmap[x][y])
			{
				ft_putstr_fd("return (1)\n", test->fd);
				player->myx = i;
				player->myy = j;
				ft_putstr_fd("cord i -->>> ", test->fd);
				ft_putnbr_fd(i, test->fd);
				ft_putchar_fd('\n', test->fd);
				ft_putstr_fd("codr j -->>> ", test->fd);
				ft_putnbr_fd(j, test->fd);
				ft_putchar_fd('\n', test->fd);
				ft_putstr_fd("new i -->>> ", test->fd);
				ft_putnbr_fd(newi, test->fd);
				ft_putchar_fd('\n', test->fd);
				ft_putstr_fd("new j -->>> ", test->fd);
				ft_putnbr_fd(newj, test->fd);
				ft_putchar_fd('\n', test->fd);
				return (1);
			}
			y++;
			newj++;
		}
		x++;
		newi++;
	}
	return (0);
}


int to_put_coordin(char **figmap, char **mapp, t_fig *fig, t_map *map, t_pla *player, t_check *test)
{
	ft_putstr_fd("in to put\n", test->fd);
	int i;
	int j;

	i = 0;
	if (fig->fcol > map->col || fig->frow > map->row)
		return (0);
	while (i < (map->col - fig->fcol + 1))
	{
		j = 0;
		while (j < (map->row - fig->frow + 1))
		{
				/*ft_putstr_fd("i -->>> ", test->fd);
				ft_putnbr_fd(i, test->fd);
				ft_putchar_fd('\n', test->fd);
				ft_putstr_fd("j -->>> ", test->fd);
				ft_putnbr_fd(j, test->fd);
				ft_putchar_fd('\n', test->fd);*/
			if (check_put(figmap, mapp, i, j, player, test))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	put_my_fig(t_fig *fig, t_pla *player, t_map *map, t_check *test)
{
	ft_putstr_fd("in put my fig\n", test->fd);
	if (to_put_coordin(fig->figmap, map->map, fig, map, player, test) == 1)
	{
		ft_putnbr_fd(player->myx, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(player->myy, 1);
		ft_putchar_fd('\n', 1);
		player->myx = 0;
		fig->first_fig_done = 1;
	}
	else
	{
		ft_putstr_fd("FIGURA TVAR\n", test->fd);
		return ;
	}
}

char get_player(char *str, t_pla *player)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'p' && str[i + 1] == '1')
		{
			player->op_player = P2;
			return (P1);
		}

		if (str[i] == 'p' && str[i + 1] == '2')
		{
			player->op_player = P1;
			return (P2);
		}
		i++;
	}
	return (0);
}

void	get_map_size(char **line, t_map *map)
{
	while (**line)
	{
		if (**line >= '0' && **line <= '9')
		{
			if (map->col == 0)
				map->col = ft_atoi(*line);
			else
				map->row = ft_atoi(*line);
			while (**line >= '0' && **line <= '9')
				(*line)++;
		}
		(*line)++;
	}
	map->map = (char **)malloc(sizeof(char *) * (map->col + 1));
	if (map->map == NULL)
		return ;
	map->map[map->col] = 0;
}



void	take_figure_size(char *line, t_fig *fig)
{
	fig->fcol = ft_atoi(&line[6]);
	fig->frow = ft_atoi(ft_strchr(&line[6], ' ') + 1);
	fig->figmap = (char **) malloc(sizeof(char *) * (fig->fcol + 1));
	if (fig->figmap == NULL)
		return ;
	fig->figmap[fig->fcol] = 0;
}


/*
void	make_next_step(t_map *map, t_pla *player, t_fig *fig, t_check *test);
{
	go_to_centr(map, player, fig, test);

}
*/
void	take_fig_coordin(t_fig *fig, t_check *test)
{
	int i;
	int j;
	int flag;

	i = 0;
	flag = 0;
	while (fig->figmap[i])
	{
		j = 0;
		while (fig->figmap[i][j])
		{
			if (fig->figmap[i][j] == '*')
			{
				fig->figx = i;
				fig->figy = j;
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag)
			return ;
		i++;
	}
}

void take_cordin_myplayer(t_map *map, t_pla *player, t_check *test)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == player->my_player)
			{
				player->myx = i;
				player->myy = j;
			}
			if (map->map[i][j] == player->op_player)
			{
				player->opx = i;
				player->opy = j;
			}
			j++;
		}
		i++;
	}
}

void	struct_init(t_map *map, t_pla *player, t_fig *fig)
{
	player->my_player = 0;
	player->op_player = 0;
	player->myx = 0;
	player->myy = 0;
	player->opx = 0;
	player->opy = 0;
	map->col = 0;
	map->row = 0;
	fig->fcol = 0;
	fig->frow = 0;
	fig->flag_for_fig = 0;
	fig->f = 0;
	fig->first_fig_done = 0;
	map->m = 0;
	fig->figx = 0;
	fig->figy = 0;
	fig->putx = 0;
	fig->puty = 0;
}
void	reset_all_value(t_map *map, t_fig *fig)
{
	map->col = 0;
	map->row = 0;
	map->cenx = 0;
	map->ceny = 0;
	fig->fcol = 0;
	fig->frow = 0;
	fig->flag_for_fig = 0;
	fig->f = 0;
	map->m = 0;
	map->cenx = 0;
	map->ceny = 0;
	fig->figx = 0;
	fig->figy = 0;
	fig->putx = 0;
	fig->puty = 0;
	free(fig->figmap);
	free(map->map);
}


int main(void)
{
	char *line;
	t_map *map;
	t_fig *fig;
	t_pla *player;
	t_check *test;
	int i;
	int j;

	i = 0;
	j = 0;
	test = (t_check *) malloc(sizeof(*test));
	map = (t_map *) malloc(sizeof(*map));
	fig = (t_fig *) malloc(sizeof(*fig));
	player = (t_pla *) malloc(sizeof(*player));
	struct_init(map, player, fig);

	test->fd = open("debug1.txt", O_CREAT | O_RDWR);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$"))
		{
			player->my_player = get_player(line, player);
			player->myx = BEGINING_OF_THE_GAME;
		}
		if (ft_strstr(line, "Plateau"))
		{
			get_map_size(&line, map);
			/*ft_putstr_fd("col = ", test->fd);
			ft_putnbr_fd(map->col, test->fd);
			ft_putstr_fd("row = ", test->fd);
			ft_putnbr_fd(map->row, test->fd);*/
		}
		if (line[0] == '0')
		{
			ft_putstr_fd("my line1 -->>>   ", test->fd);
			ft_putstr_fd(line, test->fd);
			ft_putchar_fd('\n', test->fd);
			map->map[map->m] = &line[4];
			map->m++;
		}
		if (ft_strstr(line, "Piece"))
		{
			take_figure_size(line, fig);
			fig->flag_for_fig = 1;
		}
		if ((line[0] == '.' || line[0] == '*') && (fig->flag_for_fig))
		{
			ft_putstr_fd("my line -->>>   ", test->fd);
			ft_putstr_fd(line, test->fd);
			ft_putchar_fd('\n', test->fd);
			/*ft_putnbr_fd(fig->fcol, test->fd);
			ft_putnbr_fd(fig->frow, test->fd);*/
			fig->figmap[fig->f] = line;
			fig->f++;
		}
		if(fig->f == fig->fcol && fig->flag_for_fig) //here last line when fig is read
		{
			if (player->myx == BEGINING_OF_THE_GAME) // put first fig;
			{
				ft_putstr_fd("in BEGGING", test->fd);
				ft_putchar_fd('\n', test->fd);
				fig_to_myplayer(fig, test, player);
				i = 0;
				while (fig->figmap[i])
				{
					j= 0;
					while (fig->figmap[i][j])
					{
						ft_putchar_fd(fig->figmap[i][j], test->fd);
						j++;
					}
				ft_putchar_fd('\n', test->fd);
				i++;
				}
				take_cordin_myplayer(map, player, test);
				//take_fig_coordin(fig, test);
				/*ft_putstr_fd("my figx -->>> ", test->fd);
				ft_putnbr_fd(fig->figx, test->fd);
				ft_putchar_fd('\n', test->fd);
				ft_putstr_fd("my figy -->>> ", test->fd);
				ft_putnbr_fd(fig->figy, test->fd);
				ft_putchar_fd('\n', test->fd);*/
				put_my_fig(fig, player, map, test);
				reset_all_value(map, fig);
			}
			/*if (fig->first_fig_done)
			{
				make_next_step(map, fig, player, test);
				put_my_fig(fig, player);
				reset_all_value(map, fig);
			}*/
		}


		/*if (can_put(fig, map) == 1)
			make_step(map, player, fig);*/
		/*cord_my_fig(player, map);
		cord_op_fig(player, map);*/
	}
	/*i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			ft_putchar_fd(map->map[i][j], test->fd);
			j++;
		}
		ft_putchar_fd('\n', test->fd);
		i++;
	}
	i = 0;
	while (fig->figmap[i])
	{
		j = 0;
		while (fig->figmap[i][j])
		{
			ft_putchar_fd(fig->figmap[i][j], test->fd);
			j++;
		}
		ft_putchar_fd('\n', test->fd);
		i++;
	}*/
	return (0);
}

