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

void	make_step(t_map *map, t_pla *player, t_fig *fig)
{
	int i;
	int j;

	i = 0;
	j = 0;

}

int can_put(t_map *map, t_fig *fig)
{
	return (0);
}


void take_first_coordin(t_map *map, t_pla *player, t_check *test)
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
	map->m = 0;
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
		/*ft_putstr_fd("this is line ", test->fd);
		ft_putstr_fd(line, test->fd);
		ft_putchar_fd('\n', test->fd);*/
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
		if(fig->f == fig->fcol && fig->flag_for_fig)
		{
			if (player->myx == BEGINING_OF_THE_GAME)
			{
				take_first_coordin(map, player, test);
				ft_putnbr_fd(player->myx, 1);
				ft_putchar_fd(' ', 1);
				ft_putnbr_fd(player->myy, 1);
				ft_putchar_fd('\n', 1);
				player->myx = 0;
			}
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
