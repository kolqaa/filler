/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:18:09 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/10 13:18:40 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
	{
		nb = 1;
		return (nb);
	}
	else
	{
		return (nb * ft_pow(nb, power - 1));
	}
}

int		ft_sqrt(int nb)
{
	int i;
	int b;

	i = 1;
	while (i <= nb / 2)
	{
		b = i * i;
		if (b >= nb)
			return (i);
		i++;
	}
	return (0);
}
