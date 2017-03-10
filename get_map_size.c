/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:17:16 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/10 13:17:24 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_map_size(char **line, t_data *data)
{
	while (**line)
	{
		if (**line >= '0' && **line <= '9')
		{
			if (data->col == 0)
				data->col = ft_atoi(*line);
			else
				data->row = ft_atoi(*line);
			while (**line >= '0' && **line <= '9')
				(*line)++;
		}
		(*line)++;
	}
	data->map = (char **)malloc(sizeof(char *) * (data->col + 1));
	if (data->map == NULL)
		return ;
	data->map[data->col] = 0;
	data->cenx = data->col / 2;
	data->ceny = data->row / 2;
}
