/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:45:39 by nsimonov          #+#    #+#             */
/*   Updated: 2017/03/11 13:44:13 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	char	*str;

	str = (char *)big;
	i = 0;
	if (*little == '\0')
		return (str);
	while (str[i])
	{
		if (!(ft_strncmp(&str[i], little, ft_strlen(little))))
			return (&str[i]);
		i++;
	}
	return (NULL);
}
