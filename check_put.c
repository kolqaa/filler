
#include "filler.h"

int check_put(t_data *data, int i, int j)
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
	while (data->figmap[x] && data->map[newi])
	{
		y = 0;
		newj = j;
		while (data->figmap[x][y] && data->map[newi][newj])
		{
			if (data->map[newi][newj] == data->figmap[x][y])
				count++;
			if(data->map[newi][newj] == data->op_player &&
					data->figmap[x][y] == data->my_player)
				return (0);
			y++;
			newj++;
		}
		x++;
		newi++;
	}
	if (count == 1)
	{
		write_coor_in_lst(&(data->lst), i, j, data);
		count = 0;
	}
	return (0);
}