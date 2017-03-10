/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_cordin_myplayer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:49:44 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/10 10:51:35 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	take_cordin_myplayer(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->my_player)
			{
				data->myx = i;
				data->myy = j;
			}
			if (data->map[i][j] == data->op_player)
			{
				data->opx = i;
				data->opy = j;
			}
			j++;
		}
		i++;
	}
}
