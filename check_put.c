/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:43:42 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/10 13:19:39 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_put(t_data *data, int i, int j, int newi)
{
	int x;
	int y;
	int newj;

	data->count = 0;
	x = 0;
	while (data->figmap[x] && data->map[newi])
	{
		y = 0;
		newj = j;
		while (data->figmap[x][y] && data->map[newi][newj])
		{
			if (data->map[newi][newj] == data->figmap[x][y])
				data->count++;
			if (data->map[newi][newj] == data->op_player &&
					data->figmap[x][y] == data->my_player)
				return ;
			y++;
			newj++;
		}
		x++;
		newi++;
	}
	if (data->count == 1)
		write_coor_in_lst(&(data->lst), i, j);
}
