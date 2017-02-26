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
	}
}

void	get_map(char *str)
{
	while (ft_isdigit(str))
		*str++;

}

void	struct_init(t_map *map, t_player *player)
{
	t_player->my_player = 0;
	t_player->op_player = 0;
	t_map->col = 0;
	t_map->row = 0;
}

int main(void)
{
	char *line;
	t_map *map;
	t_fig *figmap;
	t_player *player;

	struct_init(map, player);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$") && ft_strstr(line, "filler"))
			player->my_player = get_player(line);
		if (ft_strstr(line, "Plateau"))
			get_map(line);
	}

}

