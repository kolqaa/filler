/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:47:39 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/24 16:47:39 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"


char	get_player(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'p' && str[i + 1] == '1')
			return (P1);
		if (str[i] == 'p' && str[i + 1] == '2')
			return (P2);
		i++;
	}
	return (0);
}

void	get_map_size(char *str, t_map *map)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			t_map->col = ft_atoi(&str);
			while (ft_isdigit(*str))
				str++;
		}
		if (*str >= '0' && <= *str '9')
			t_map->row = ft_atoi(&str);
		str++;
	}
}

void	struct_init(t_map *map, t_pla *player)
{
	player->my_player = 0;
	player->op_player = 0;
	map->col = 0;
	map->row = 0;
}


int main(void)
{
	char *line;
	t_map *map;
	t_fig *figmap;
	t_pla *player;
	t_check *test;


	test = (t_check *) malloc(sizeof(test));
	map = (t_map *) malloc(sizeof(map));
	figmap = (t_fig *) malloc(sizeof(figmap));
	player = (t_pla *) malloc(sizeof(player));
	struct_init(map, player);

	test->fd = open("debug1.txt", O_CREAT | O_RDWR);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$"))
		{
			player->my_player = get_player(line);
			ft_putchar_fd(player->my_player, test->fd);
		}
		if (ft_strstr(line, "Plateau"))
		{
			get_map_size(line, map);
		}

	}
	return (0);
}

