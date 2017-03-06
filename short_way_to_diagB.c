#include "filler.h"

#include "filler.h"

void short_way_to_diagB(t_flist **lst, t_data *data) //find way to centr
{
	/*check my lst of all possible coordinate and choose best one which close to the center*/
	t_flist *tmp;

	ft_putstr_fd("SHORT WAY TO B\n", data->fd);
	int tmpx;
	int tmpy;
	int tmpdst;

	tmpdst = 214721389;
	tmp = *lst;
	while (tmp)
	{
		if (ft_sqrt(
				ft_pow(tmp->x - data->Bdiagx, 2) + ft_pow(tmp->y - data->Bdiagy, 2)) <
			tmpdst)
		{

			tmpdst = ft_sqrt(ft_pow(tmp->x - data->Bdiagx, 2) +
							 ft_pow(tmp->y - data->Bdiagy, 2));
			tmpx = tmp->x;
			tmpy = tmp->y;
		}
		tmp = tmp->next;
	}
	data->myx = tmpx;
	data->myy = tmpy;
	ft_putchar_fd('\n', data->fd);
	ft_putstr_fd("Bmy coord to put x -->>> ", data->fd);
	ft_putnbr_fd(tmpx, data->fd);
	ft_putchar_fd('\n', data->fd);
	ft_putstr_fd("Bmycoord to put y-->>> ", data->fd);
	ft_putnbr_fd(tmpy, data->fd);
	ft_putchar_fd('\n', data->fd);
}

