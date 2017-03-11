/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:50:41 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/10 10:00:23 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	copy_figure(char *line, t_data *data)
{
	data->figmap[data->f] = line;
	data->f++;
	data->flag_for_fig = 3;
}
