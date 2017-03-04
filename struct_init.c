//
// Created by Nick Simonov on 3/4/17.
//

#include "filler.h"

void	struct_init(t_map *map, t_pla *player, t_fig *fig)
{
	player->my_player = 0;
	player->op_player = 0;
	player->myx = 0;
	player->myy = 0;
	player->opx = 0;
	player->opy = 0;
	map->col = 0;
	map->row = 0;
	fig->fcol = 0;
	fig->frow = 0;
	fig->flag_for_fig = 0;
	fig->f = 0;
	fig->first_fig_done = 0;
	map->m = 0;

}