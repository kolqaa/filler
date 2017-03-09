#include "filler.h"

int take_cor_where_to_put(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i <= (data->col - data->fcol))
	{
		j = 0;
		while (j <= (data->row - data->frow))
		{
			check_put(data, i, j); //possible to put? and choose best coordin
			j++;
		}
		i++;
	}
	if (data->lst == NULL)
		return (0);
	return (1);
}
