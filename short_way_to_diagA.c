#include "filler.h"

void short_way_to_diagA(t_flist **lst, t_data *data) //find way to centr
{
	/*check my lst of all possible coordinate and choose best one which close to the center*/
	t_flist *tmp;

	ft_putstr_fd("SHORT WAY TO A\n", data->fd);
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
	/*ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("Amy coord to put x -->>> ", test->fd);
	ft_putnbr_fd(tmpx, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("Amycoord to put y-->>> ", test->fd);
	ft_putnbr_fd(tmpy, test->fd);
	ft_putchar_fd('\n', test->fd);*/
}