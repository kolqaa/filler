#include "filler.h"

void	get_map_size(char **line, t_data *data)
{
	while (**line)
	{
		if (**line >= '0' && **line <= '9')
		{
			if (data->col == 0)
				data->col = ft_atoi(*line);
			else
				data->row = ft_atoi(*line);
			while (**line >= '0' && **line <= '9')
				(*line)++;
		}
		(*line)++;
	}
	data->map = (char **)malloc(sizeof(char *) * (data->col + 1));
	if (data->map == NULL)
		return ;
	data->map[data->col] = 0;
	data->cenx = data->col / 2;
	data->ceny = data->row / 2;
}