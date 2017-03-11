#include "filler.h"

void rebuild_myfig(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->figmap[i])
	{
		j = 0;
		while (data->figmap[i][j])
		{
			if (data->figmap[i][j] == '*')
				data->figmap[i][j] = data->my_player;
			if (data->figmap[i][j] == '.')
				data->figmap[i][j] = ',';
			j++;
		}
		i++;
	}
}