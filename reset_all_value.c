#include "filler.h"

void reset_all_value(t_data *data)
{
	data->col = 0;
	data->row = 0;
	data->cenx = 0;
	data->ceny = 0;
	data->fcol = 0;
	data->frow = 0;
	data->flag_for_fig = 0;
	data->f = 0;
	data->m = 0;
	data->cenx = 0;
	data->ceny = 0;
	data->ver = 0;
	data->hor = 0;
	free(data->figmap);
	free(data->map);
}