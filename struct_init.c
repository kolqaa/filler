/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:05:46 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/10 10:13:44 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	struct_init(t_data *data)
{
	data->my_player = 0;
	data->op_player = 0;
	data->myx = 0;
	data->myy = 0;
	data->opx = 0;
	data->opy = 0;
	data->col = 0;
	data->row = 0;
	data->fcol = 0;
	data->frow = 0;
	data->flag_for_fig = 2016;
	data->f = 0;
	data->first_fig_done = 0;
	data->m = 0;
	data->lst = NULL;
	data->adiagx = 0;
	data->adiagy = 0;
	data->bdiagx = 0;
	data->bdiagy = 0;
	data->hor = 0;
	data->ver = 0;
	data->opstartdown = 0;
	data->count = 0;
}
