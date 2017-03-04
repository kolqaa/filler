//
// Created by Nick Simonov on 3/4/17.
//

#include "filler.h"


void take_cordin_myplayer(t_map *map, t_pla *player, t_check *test)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == player->my_player)
			{
				player->myx = i;
				player->myy = j;
			}
			if (map->map[i][j] == player->op_player)
			{
				player->opx = i;
				player->opy = j;
			}
			j++;
		}
		i++;
	}
}