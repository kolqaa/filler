#include "filler.h"

void analyze_fig(t_data *data)
{
	ft_putstr_fd("ANALYZE FIG\n", data->fd);
	int i;
	int j;
	int countj;
	int counti;

	i = 0;
	while (data->figmap[i])
	{
		j = 0;
		countj = 0;
		while (data->figmap[i][j])
		{
			if (data->figmap[i][j] == '*')
				countj++;
			j++;
		}
		if (countj > data->hor)
			data->hor = countj;
		i++;
	}
	i = 0;
	j = 0;
	while (data->figmap[i][j])
	{

		counti = 0;
		while (data->figmap[i])
		{
			if (data->figmap[i][j] == '*')
				counti++;
			i++;
			if (i == data->fcol)
				break;
		}
		if (counti > data->ver)
			data->ver = counti;
		i = 0;
		j++;
	}
	ft_putchar_fd('\n', data->fd);
	ft_putstr_fd("vertical ", data->fd);
	ft_putnbr_fd(data->ver, data->fd);
	ft_putchar_fd('\n', data->fd);
	ft_putstr_fd("horizont ", data->fd);
	ft_putnbr_fd(data->hor, data->fd);
	ft_putchar_fd('\n', data->fd);
	ft_putstr_fd("EXIT ANALYZ\n", data->fd);
}