#include "filler.h"

void	copy_map(char *line, t_data *data)
{
	data->map[data->m] = &line[4];
	data->m++;
}
