//
// Created by Nick Simonov on 3/4/17.
//

#include "filler.h"

void struct_init(t_data *data)
{
	data->my_player = 0;
	data->op_player = 0;
	data->myx = 0;
	data->myy = 0;
	data->opx = 0;
	data->opy = 0;
	data->col = 0;
	data->row = 0;
	data->fcol = 0;
	data->frow = 0;
	data->flag_for_fig = 2016;
	data->f = 0;
	data->first_fig_done = 0;
	data->m = 0;
	data->lst = NULL;
	data->Adiagx = 0;
	data->Adiagy = 0;
	data->Bdiagx = 0;
	data->Bdiagy = 0;
	data->hor = 0;
	data->ver = 0;
	data->opstartdown = 0;
}