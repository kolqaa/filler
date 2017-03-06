

#include "filler.h"

void	take_figure_size(char *line, t_data *data)
{
	data->fcol = ft_atoi(&line[6]);
	data->frow = ft_atoi(ft_strchr(&line[6], ' ') + 1);
	data->figmap = (char **) malloc(sizeof(char *) * (data->fcol + 1));
	if (data->figmap == NULL)
		return ;
	data->figmap[data->fcol] = 0;
}