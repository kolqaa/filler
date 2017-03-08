#include "filler.h"

void	analyze_horizontal(t_data *data)
{
	int i;
	int j;
	int countj;

	i = 0;
	while (data->figmap[i])
	{
		j = 0;
		countj = 0;
		while (data->figmap[i][j])
		{
			if (data->figmap[i][j] == '*')
				countj++;
			j++;
		}
		if (countj > data->hor)
			data->hor = countj;
		i++;
	}
}

void	analyze_vertical(t_data *data)
{
	int i;
	int j;
	int counti;

	i = 0;
	j = 0;
	while (data->figmap[i][j])
	{

		counti = 0;
		while (data->figmap[i]) {
			if (data->figmap[i][j] == '*')
				counti++;
			i++;
			if (i == data->fcol)
				break;
		}
		if (counti > data->ver)
			data->ver = counti;
		i = 0;
		j++;
	}
}

void analyze_fig(t_data *data)
{
	analyze_horizontal(data);
	analyze_vertical(data);
	rebuild_myfig(data);
}