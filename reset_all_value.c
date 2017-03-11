/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_all_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:54:11 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/10 10:54:42 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	reset_all_value(t_data *data)
{
	data->col = 0;
	data->row = 0;
	data->cenx = 0;
	data->ceny = 0;
	data->fcol = 0;
	data->frow = 0;
	data->flag_for_fig = 2016;
	data->f = 0;
	data->m = 0;
	data->cenx = 0;
	data->ceny = 0;
	data->ver = 0;
	data->hor = 0;
	data->opstartdown = 0;
	free(data->figmap);
	free(data->map);
}
