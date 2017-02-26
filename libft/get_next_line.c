/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:29:48 by nsimonov          #+#    #+#             */
/*   Updated: 2017/01/29 16:58:39 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin1(char *s1, char *s2)
{
	int		j;
	int		k;
	int		lens1;
	size_t	len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	k = 0;
	while (s1[k])
		str[j++] = s1[k++];
	k = 0;
	while (s2[k])
		str[lens1++] = s2[k++];
	str[lens1] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

int		check_buff(char *buff, char **line)
{
	int i;
	int j;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
	{
		buff[i] = '\0';
		*line = ft_strjoin1(*line, buff);
		i++;
		j = 0;
		while (buff[i] != '\0')
			buff[j++] = buff[i++];
		buff[j] = '\0';
		return (1);
	}
	*line = ft_strjoin1(*line, buff);
	return (0);
}

int		ft_read(int const fd, char *temp, char **line, char *buff)
{
	int	i;
	int	rd;
	int	j;

	while ((rd = read(fd, temp, BUFF_SIZE)) > 0)
	{
		i = 0;
		while (temp[i] != '\n' && i < rd)
			i++;
		if (temp[i] == '\n')
		{
			temp[i++] = '\0';
			j = 0;
			while (i < rd)
				buff[j++] = temp[i++];
			buff[j] = '\0';
			*line = ft_strjoin1(*line, temp);
			free(temp);
			temp = NULL;
			return (1);
		}
		temp[i] = '\0';
		*line = ft_strjoin1(*line, temp);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char			*temp;
	static t_mylist	head[OPEN_MAX];

	if ((BUFF_SIZE <= 0 || (read(fd, NULL, 0) == -1) || line == NULL))
		return (-1);
	if ((*line = ft_strnew(1)) == NULL)
		return (0);
	if (head[fd].buff != NULL)
		if ((check_buff(head[fd].buff, line)) == 1)
			return (1);
	temp = ft_strnew(BUFF_SIZE);
	if (temp == NULL)
		return (0);
	head[fd].buff = ft_strnew(BUFF_SIZE);
	if (head[fd].buff == NULL)
		return (0);
	if ((ft_read(fd, temp, line, head[fd].buff)) == 1)
		return (1);
	if (*line[0] == 0)
		return (0);
	return (1);
}
