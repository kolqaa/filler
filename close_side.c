/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_side.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:55:35 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/10 09:57:42 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		right_side_closed(t_data *data)
{
	int i;

	i = 0;
	while (data->map[i][data->row - 1])
	{
		if (data->map[i][data->row - 1] == data->my_player)
			return (1);
		if (i == data->col - 1)
			break ;
		i++;
	}
	return (0);
}

int		down_side_closed(t_data *data)
{
	int	j;

	j = 0;
	while (data->map[data->col - 1][j])
	{
		if (data->map[data->col - 1][j] == data->my_player)
			return (1);
		j++;
	}
	return (0);
}

int		in_center(t_data *data)
{
	int i;
	int j;

	i = data->cenx - DELTAX;
	while (i < data->cenx + DELTAX)
	{
		j = data->ceny - DELTAY;
		while (j < data->ceny + DELTAY)
		{
			if (data->map[i][j] == data->my_player ||
				data->map[i][j] == data->op_player)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		left_side_closed(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] == data->my_player)
			return (1);
		if (i == data->col - 1)
			break ;
		i++;
	}
	return (0);
}

int		up_side_closed(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] == data->my_player)
			return (1);
		j++;
	}
	return (0);
}
