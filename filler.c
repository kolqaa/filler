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


char	get_player(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'p' && str[i + 1] == '1')
			return (P1);
		if (str[i] == 'p' && str[i + 1] == '2')
			return (P2);
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
}


void	take_figure_size(char *line, t_fig *fig)
{
	fig->fcol = ft_atoi(&line[6]);
	fig->frow = ft_atoi(ft_strchr(&line[6], ' ') + 1);
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
	test = (t_check *) malloc(sizeof(test));
	map = (t_map *) malloc(sizeof(map));
	fig = (t_fig *) malloc(sizeof(fig));
	player = (t_pla *) malloc(sizeof(player));
	struct_init(map, player, fig);

	test->fd = open("debug1.txt", O_CREAT | O_RDWR);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$"))
			player->my_player = get_player(line);
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
		if (ft_strstr(line, "00"))
		{
			map->map = (char **)malloc(sizeof(char *) * (map->col + 1));
			if (map->map == NULL)
				return (0);
			map->map[map->col] = 0;
			while (i < map->col)
			{
				map->map[i] = (char *)malloc(sizeof(char) * (map->row) + 1);
				if (map->map[i] == NULL)
					return (0);
				j = 0;
				line += 4;
				while (*line)
				{
					map->map[i][j] = *line;
					j++;
					line++;
				}
				map->map[i++][j] = '\0';
				get_next_line(0, &line);
			}
			i = 0;
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
		}
		if (ft_strstr(line, "Piece"))
		{
			take_figure_size(line, fig);
			/*ft_putstr_fd(line, test->fd);
			ft_putstr_fd("fig->fcol == ", test->fd);
			ft_putnbr_fd(fig->fcol, test->fd);
			ft_putstr_fd("fig->frow == ", test->fd);
			ft_putnbr_fd(fig->frow, test->fd);*/
			get_next_line(0, &line);
			ft_putchar_fd('\n', test->fd);
			i = 0;
			fig->figmap = (char **) malloc(sizeof(char *) * (fig->fcol + 1));
			if (fig->figmap == NULL)
				return (0);
			fig->figmap[fig->fcol] = 0;
			while (i < fig->fcol) {
				j = 0;
				fig->figmap[i] = (char *) malloc(sizeof(char) * (fig->frow + 1));
				if (fig->figmap[i] == NULL)
					return (0);
				while (*line) {
					fig->figmap[i][j] = *line;
					j++;
					line++;
				}
				fig->figmap[i++][j] = '\0';
				get_next_line(0, &line);
			}
			ft_putstr_fd("8 2\n", 1);
			i = 0;
			while (fig->figmap[i]) {
				j = 0;
				while (fig->figmap[i][j]) {
					ft_putchar_fd(fig->figmap[i][j], test->fd);
					j++;
				}
				ft_putchar_fd('\n', test->fd);
				i++;
			}

		}
		/*cord_my_fig(player, map);
		cord_op_fig(player, map);*/
	}
	return (0);
}