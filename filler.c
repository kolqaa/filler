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
	test = (t_check *) malloc(sizeof(test));
	map = (t_map *) malloc(sizeof(map));
	fig = (t_fig *) malloc(sizeof(fig));
	player = (t_pla *) malloc(sizeof(player));
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
			map->cenx = map->col / 2;
			map->ceny = map->row / 2;
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
				rebuild_myfig(fig, test, player);
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
				put_my_fig(fig, player, map, test);
				reset_all_value(map, fig);
				fig->first_fig_done = 1;
			}
			else if (fig->first_fig_done)
			{
				ft_putstr_fd("FRIST FIG DONE\n", test->fd);
				analyze_fig(fig, map, test);
				rebuild_myfig(fig, test, player);
				put_my_fig(fig, player, map, test);
				reset_all_value(map, fig);
			}
		}
	}
	return (0);
}