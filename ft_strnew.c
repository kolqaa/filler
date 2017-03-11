/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:15:36 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/11 13:43:56 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(size * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	if (str)
		ft_memset(str, '\0', size + 1);
	return (str);
}
