
#include "filler.h"

int check_put(t_fig *fig, t_map *map, int i, int j, t_pla *player, t_check *test)
{
	/*Here we check all possible way to put my figure, and check one crosses with my player or last put figure
	 * if we find that coordinate we write it in my chained list
	 * than we take closest coordin to center from that list and go to it, if we already in center we start put my figure to
	 * diagonal.*/
	int x;
	int y;
	int count;
	int newi;
	int newj;

	newi = i;
	newj = j;
	count = 0;
	x = 0;
	while (fig->figmap[x] && map->map[newi])
	{
		y = 0;
		newj = j;
		while (fig->figmap[x][y] && map->map[newi][newj])
		{
			if (map->map[newi][newj] == fig->figmap[x][y])
				count++;
			if(map->map[newi][newj] == player->op_player &&
					fig->figmap[x][y] == player->my_player)
				return (0);
			y++;
			newj++;
		}
		x++;
		newi++;
	}
	if (count == 1)
	{
		ft_putstr_fd("in count == 1\n", test->fd);
		write_coor_in_lst(&(map->lst), i, j, test);
		count = 0;
	}
	return (0);
}