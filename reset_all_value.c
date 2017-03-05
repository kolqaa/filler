#include "filler.h"

void	reset_all_value(t_map *map, t_fig *fig)
{
	map->col = 0;
	map->row = 0;
	map->cenx = 0;
	map->ceny = 0;
	fig->fcol = 0;
	fig->frow = 0;
	fig->flag_for_fig = 0;
	fig->f = 0;
	map->m = 0;
	map->cenx = 0;
	map->ceny = 0;
	map->ver = 0;
	map->hor = 0;
	free(fig->figmap);
	free(map->map);
}