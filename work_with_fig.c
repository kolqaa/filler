/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_fig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:51:16 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/10 10:00:03 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	analyze_horizontal(t_data *data)
{
	int i;
	int j;
	int countj;

	i = 0;
	while (data->figmap[i])
	{
		j = 0;
		countj = 0;
		while (data->figmap[i][j])
		{
			if (data->figmap[i][j] == '*')
				countj++;
			j++;
		}
		if (countj > data->hor)
			data->hor = countj;
		i++;
	}
}

void	analyze_vertical(t_data *data)
{
	int i;
	int j;
	int counti;

	i = 0;
	j = 0;
	while (data->figmap[i][j])
	{
		counti = 0;
		while (data->figmap[i])
		{
			if (data->figmap[i][j] == '*')
				counti++;
			i++;
			if (i == data->fcol)
				break ;
		}
		if (counti > data->ver)
			data->ver = counti;
		i = 0;
		j++;
	}
}

void	analyze_fig(t_data *data)
{
	analyze_horizontal(data);
	analyze_vertical(data);
	rebuild_myfig(data);
}

void	rebuild_myfig(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->figmap[i])
	{
		j = 0;
		while (data->figmap[i][j])
		{
			if (data->figmap[i][j] == '*')
				data->figmap[i][j] = data->my_player;
			if (data->figmap[i][j] == '.')
				data->figmap[i][j] = ',';
			j++;
		}
		i++;
	}
}
