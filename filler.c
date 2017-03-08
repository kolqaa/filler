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

	data = (t_data *) malloc(sizeof(*data));
	struct_init(data);
	data->fd = open("debug1.txt", O_CREAT | O_RDWR);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$") && data->exist == 0)
			data->my_player = get_player(line, data);
		if (ft_strstr(line, "Plateau"))
			get_map_size(&line, data);
		if (line[0] == '0')
			copy_map(line, data);
		if (ft_strstr(line, "Piece"))
			take_figure_size(line, data);
		if ((line[0] == '.' || line[0] == '*') && (data->col == data->m))
			copy_figure(line,data);
		if(data->f == data->fcol && data->flag_for_fig == 3 && data->col)
		{
				analyze_fig(data);
				take_cordin_myplayer(data);
				put_my_fig(data);
				reset_all_value(data);
		}
	}
	return (0);
}