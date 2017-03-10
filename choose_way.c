/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:22:35 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/10 11:32:00 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	short_way_to_diaga(t_flist **lst, t_data *data)
{
	t_flist *tmp;
	int		tmpx;
	int		tmpy;
	int		tmpdst;

	tmpdst = 214721389;
	tmp = *lst;
	while (tmp)
	{
		if (ft_sqrt(ft_pow(tmp->x - data->adiagx, 2) +
					ft_pow(tmp->y - data->adiagy, 2)) < tmpdst)
		{
			tmpdst = ft_sqrt(ft_pow(tmp->x - data->adiagx, 2) +
					ft_pow(tmp->y - data->adiagy, 2));
			tmpx = tmp->x;
			tmpy = tmp->y;
		}
		tmp = tmp->next;
	}
	data->myx = tmpx;
	data->myy = tmpy;
}

void	short_way_to_diagb(t_flist **lst, t_data *data)
{
	t_flist *tmp;
	int		tmpx;
	int		tmpy;
	int		tmpdst;

	tmpdst = 214721389;
	tmp = *lst;
	while (tmp)
	{
		if (ft_sqrt(ft_pow(tmp->x - data->bdiagx, 2) +
					ft_pow(tmp->y - data->bdiagy, 2)) < tmpdst)
		{
			tmpdst = ft_sqrt(ft_pow(tmp->x - data->bdiagx, 2) +
					ft_pow(tmp->y - data->bdiagy, 2));
			tmpx = tmp->x;
			tmpy = tmp->y;
		}
		tmp = tmp->next;
	}
	data->myx = tmpx;
	data->myy = tmpy;
}

void	select_short_way_tocenr(t_flist **lst, t_data *data)
{
	t_flist *tmp;
	int		tmpx;
	int		tmpy;
	int		tmpdst;

	tmpdst = 214721389;
	tmp = *lst;
	while (tmp)
	{
		if (ft_sqrt(ft_pow(tmp->x - data->cenx, 2) +
			ft_pow(tmp->y - data->ceny, 2)) < tmpdst)
		{
			tmpdst = ft_sqrt(ft_pow(tmp->x - data->cenx, 2) +
					ft_pow(tmp->y - data->ceny, 2));
			tmpx = tmp->x;
			tmpy = tmp->y;
		}
		tmp = tmp->next;
	}
	data->myx = tmpx;
	data->myy = tmpy;
}

void	select_short_way_enemy(t_flist **lst, t_data *data)
{
	t_flist	*tmp;
	int		tmpx;
	int		tmpy;
	int		tmpdst;

	tmpdst = 214721389;
	tmp = *lst;
	while (tmp)
	{
		if (ft_sqrt(ft_pow(tmp->x - (data->col - data->col), 2) +
					ft_pow(tmp->y - (data->row - data->row), 2)) < tmpdst)
		{
			tmpdst = ft_sqrt(ft_pow(tmp->x - (data->col - data->col), 2) +
					ft_pow(tmp->y - (data->row - data->row), 2));
			tmpx = tmp->x;
			tmpy = tmp->y;
		}
		tmp = tmp->next;
	}
	data->myx = tmpx;
	data->myy = tmpy;
}
