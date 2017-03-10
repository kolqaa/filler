/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_cor_where_to_put.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:48:46 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/10 09:53:23 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	take_cor_where_to_put(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i <= (data->col - data->fcol))
	{
		j = 0;
		while (j <= (data->row - data->frow))
		{
			check_put(data, i, j, i);
			j++;
		}
		i++;
	}
	if (data->lst == NULL)
		return (0);
	return (1);
}
