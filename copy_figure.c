#include "filler.h"

void copy_figure(char *line, t_data *data)
{
	data->figmap[data->f] = line;
	data->f++;
	data->flag_for_fig = 3;
}