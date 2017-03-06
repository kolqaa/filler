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
	t_data *data;
	int i;
	int j;

	i = 0;
	j = 0;
	data = (t_data *) malloc(sizeof(*data));
	struct_init(data);
	data->fd = open("debug1.txt", O_CREAT | O_RDWR);

while (get_next_line(0, &line) > 0)
	{

		if (ft_strstr(line, "$$$") && data->exist == 0)
		{
			data->my_player = get_player(line, data);
			data->myx = BEGINING_OF_THE_GAME;
		}
		if (ft_strstr(line, "Plateau"))
		{
			get_map_size(&line, data);
			data->cenx = data->col / 2;
			data->ceny = data->row / 2;
		}
		if (line[0] == '0')
		{
			ft_putstr_fd("my line1 -->>>   ", data->fd);
			ft_putstr_fd(line, data->fd);
			ft_putchar_fd('\n', data->fd);
			data->map[data->m] = &line[4];
			data->m++;
		}
		if (ft_strstr(line, "Piece"))
		{
			take_figure_size(line, data);
			data->flag_for_fig = 1;
		}
		if ((line[0] == '.' || line[0] == '*') && (data->flag_for_fig))
		{
			ft_putstr_fd("my line -->>>   ", data->fd);
			ft_putstr_fd(line, data->fd);
			ft_putchar_fd('\n', data->fd);
			/*ft_putnbr_fd(fig->fcol, test->fd);
			ft_putnbr_fd(fig->frow, test->fd);*/
			data->figmap[data->f] = line;
			data->f++;
		}
		if(data->f == data->fcol && data->flag_for_fig) //here last line when fig is read
		{/*
			if (data->myx == BEGINING_OF_THE_GAME) // put first fig;
			{
				ft_putstr_fd("in BEGGING", data->fd);
				ft_putchar_fd('\n', data->fd);
				rebuild_myfig(data);
				i = 0;
				while (data->figmap[i])
				{
					j= 0;
					while (data->figmap[i][j])
					{
						ft_putchar_fd(data->figmap[i][j], data->fd);
						j++;
					}
				ft_putchar_fd('\n', data->fd);
				i++;
				}
				take_cordin_myplayer(data);
				put_my_fig(data);
				reset_all_value(data);
				data->first_fig_done = 1;
			}
			else if (data->first_fig_done)
			{*/
				ft_putstr_fd("FRIST FIG DONE\n", data->fd);
				analyze_fig(data);
				rebuild_myfig(data);
				take_cordin_myplayer(data);
				put_my_fig(data);
				reset_all_value(data);
			//}
		}
	}
	return (0);
}