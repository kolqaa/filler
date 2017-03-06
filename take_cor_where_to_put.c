#include "filler.h"

int take_cor_where_to_put(t_data *data)
{
	ft_putstr_fd("in to put\n", data->fd);
	int i;
	int j;

	i = 0;
	/*if (fig->fcol > map->col || fig->frow > map->row)
		return (0);*/
	ft_putstr_fd("map->col ", data->fd);
	ft_putnbr_fd(data->col, data->fd);
	ft_putchar_fd('\n', data->fd);
	ft_putstr_fd("fig->fcol ", data->fd);
	ft_putnbr_fd(data->fcol, data->fd);
	ft_putchar_fd('\n', data->fd);
	while (i < (data->col - data->fcol + 1))
	{
		j = 0;
		while (j < (data->row - data->frow + 1))
		{
			check_put(data, i, j); //possible to put? and choose best coordin
			j++;
		}
		i++;
	}
	if (data->lst == NULL)
		return (0);
	return (1);
}
