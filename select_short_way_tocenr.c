//
// Created by Nick Simonov on 3/4/17.
//

#include "filler.h"

void select_short_way_tocenr(t_flist **lst, t_data *data) //find way to centr
{
	/*check my lst of all possible coordinate and choose best one which close to the center*/
	t_flist *tmp;

	ft_putstr_fd("select shortly\n", data->fd);
	int tmpx;
	int tmpy;
	int tmpdst;

	tmpdst = 214721389;
	tmp = *lst;
	/*ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("CENTR x -->>> ", test->fd);
	ft_putnbr_fd(map->cenx, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("CENTR y-->>> ", test->fd);
	ft_putnbr_fd(map->ceny, test->fd);
	ft_putchar_fd('\n', test->fd);*/
	while (tmp)
	{
		if (ft_sqrt(ft_pow(tmp->x - data->cenx, 2) + ft_pow(tmp->y - data->ceny , 2)) < tmpdst)
		{
			ft_putstr_fd("IN IFFFFFFFFFFF\n", data->fd);
			tmpdst = ft_sqrt(ft_pow(tmp->x - data->cenx, 2) + ft_pow(tmp->y - data->ceny, 2));
			tmpx = tmp->x;
			tmpy = tmp->y;
		}
/*			ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("in while dst ", test->fd);
	ft_putnbr_fd(tmpdst, test->fd);
		ft_putchar_fd('\n', test->fd);
		ft_putstr_fd("in while sqrt ", test->fd);
	ft_putnbr_fd(ft_sqrt(ft_pow(tmp->x - map->cenx, 2) + ft_pow(tmp->y - map->ceny, 2)), test->fd);
		ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("in while tmp->x ", test->fd);
	ft_putnbr_fd(tmp->x, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("in while tmp->y ", test->fd);
	ft_putnbr_fd(tmp->y, test->fd);
	ft_putchar_fd('\n', test->fd);*/
		tmp = tmp->next;
	}
	data->myx = tmpx;
	data->myy = tmpy;
	ft_putchar_fd('\n', data->fd);
	ft_putstr_fd("my coord to put x -->>> ", data->fd);
	ft_putnbr_fd(tmpx, data->fd);
	ft_putchar_fd('\n', data->fd);
	ft_putstr_fd("mycoord to put y-->>> ", data->fd);
	ft_putnbr_fd(tmpy, data->fd);
	ft_putchar_fd('\n', data->fd);
}