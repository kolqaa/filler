#include "filler.h"

void short_way_to_diagA(t_flist **lst, t_data *data) //find way to centr
{
	/*check my lst of all possible coordinate and choose best one which close to the center*/
	t_flist *tmp;

	int tmpx;
	int tmpy;
	int tmpdst;

	tmpdst = 214721389;
	tmp = *lst;

	while (tmp)
	{
		if (ft_sqrt(
				ft_pow(tmp->x - data->Adiagx, 2) + ft_pow(tmp->y - data->Adiagy, 2)) <
			tmpdst)
		{
			tmpdst = ft_sqrt(ft_pow(tmp->x - data->Adiagx, 2) +
							 ft_pow(tmp->y - data->Adiagy, 2));
			tmpx = tmp->x;
			tmpy = tmp->y;
		}
		tmp = tmp->next;
	}
	data->myx = tmpx;
	data->myy = tmpy;
}

void short_way_to_diagB(t_flist **lst, t_data *data) //find way to centr
{
	/*check my lst of all possible coordinate and choose best one which close to the center*/
	t_flist *tmp;

	int tmpx;
	int tmpy;
	int tmpdst;

	tmpdst = 214721389;
	tmp = *lst;
	while (tmp)
	{
		if (ft_sqrt(ft_pow(tmp->x - data->Bdiagx, 2) + ft_pow(tmp->y - data->Bdiagy, 2)) < tmpdst)
		{

			tmpdst = ft_sqrt(ft_pow(tmp->x - data->Bdiagx, 2) + ft_pow(tmp->y - data->Bdiagy, 2));
			tmpx = tmp->x;
			tmpy = tmp->y;
		}
		tmp = tmp->next;
	}
	data->myx = tmpx;
	data->myy = tmpy;

}

void select_short_way_tocenr(t_flist **lst, t_data *data) //find way to centr
{
	/*check my lst of all possible coordinate and choose best one which close to the center*/
	t_flist *tmp;

	int tmpx;
	int tmpy;
	int tmpdst;

	tmpdst = 214721389;
	tmp = *lst;
	while (tmp)
	{
		if (ft_sqrt(ft_pow(tmp->x - data->cenx, 2) +
					ft_pow(tmp->y - data->ceny , 2)) < tmpdst)
		{
			tmpdst = ft_sqrt(ft_pow(tmp->x - data->cenx, 2) +
							 ft_pow(tmp->y - data->ceny, 2));
			tmpx = tmp->x;
			tmpy = tmp->y;
		}

		tmp = tmp->next;
	}
	data->myx = tmpx;
	data->myy = tmpy;
}

void select_short_way_enemy(t_flist **lst, t_data *data) //find way to centr
{
	/*check my lst of all possible coordinate and choose best one which close to the center*/
	t_flist *tmp;

	int tmpx;
	int tmpy;
	int tmpdst;

	tmpdst = 214721389;
	tmp = *lst;
	while (tmp)
	{
		if (ft_sqrt(ft_pow(tmp->x - (data->col - data->col), 2) +
					ft_pow(tmp->y - (data->row - data->row), 2)) < tmpdst)
		{
			tmpdst = ft_sqrt(ft_pow(tmp->x - (data->col - data->col), 2) +
							 ft_pow(tmp->y - (data->row - data->row), 2));
			tmpx = tmp->x;
			tmpy = tmp->y;
		}
		tmp = tmp->next;
	}
	data->myx = tmpx;
	data->myy = tmpy;
}