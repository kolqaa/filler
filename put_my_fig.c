/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_my_fig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:01:57 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/10 10:03:07 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	take_diagonal(t_data *data)
{
	if (data->opx < data->cenx && data->opy < data->ceny)
	{
		data->adiagx = 0;
		data->adiagy = data->ceny + SHIFTY - data->frow;
		data->bdiagx = data->cenx + SHIFTX;
		data->bdiagy = 0;
	}
	if (data->opx > data->cenx && data->opy > data->ceny)
	{
		data->bdiagx = data->cenx - SHIFTX - data->fcol;
		data->bdiagy = data->row;
		data->adiagx = data->col;
		data->adiagy = data->ceny - SHIFTY - data->frow;
		data->opstartdown = 1;
	}
}

int		move_to_leftup(t_data *data)
{
	if (left_side_closed(data) && up_side_closed(data))
		select_short_way_enemy(&(data->lst), data);
	else if (data->ver > data->hor)
	{
		if (up_side_closed(data))
		{
			short_way_to_diagb(&(data->lst), data);
			return (1);
		}
		else
			short_way_to_diaga(&(data->lst), data);
		return (1);
	}
	else
	{
		if (left_side_closed(data))
		{
			short_way_to_diaga(&(data->lst), data);
			return (1);
		}
		else
			short_way_to_diagb(&(data->lst), data);
	}
	return (1);
}

int		move_to_rightdown(t_data *data)
{
	if (right_side_closed(data) && down_side_closed(data))
		select_short_way_tocenr(&(data->lst), data);
	else if (data->ver > data->hor)
	{
		if (down_side_closed(data))
		{
			short_way_to_diagb(&(data->lst), data);
			return (1);
		}
		else
			short_way_to_diaga(&(data->lst), data);
		return (1);
	}
	else
	{
		if (right_side_closed(data))
		{
			short_way_to_diaga(&(data->lst), data);
			return (1);
		}
		else
			short_way_to_diagb(&(data->lst), data);
	}
	return (1);
}

void	put_my_fig(t_data *data)
{
	if (take_cor_where_to_put(data) == 1)
	{
		if (in_center(data))
		{
			take_diagonal(data);
			data->opstartdown ? move_to_rightdown(data) : move_to_leftup(data);
			ft_memdel((void **)&(data->lst));
		}
		else
		{
			select_short_way_tocenr(&(data->lst), data);
			ft_memdel((void **)&(data->lst));
		}
		ft_putnbr_fd(data->myx, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(data->myy, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		ft_putstr_fd("0 0\n", 1);
		return ;
	}
}
