#include "filler.h"

void	take_diagonal(t_data *data)
{ /* take two diagonal where we should to move. Based on the position of my enemy.
 * We split map on the four square and check coordint of enemy and compare it whith center coordinate*/
	ft_putstr_fd("TAKE DIAG I\n",data->fd);
	if (data->opx < data->cenx && data->opy < data->ceny)
	{
		data->Adiagx = 0;
		data->Adiagy = data->ceny + SHIFTY - data->frow;
		data->Bdiagx = data->cenx + SHIFTX;
		data->Bdiagy = 0;
	}
	if (data->opx > data->cenx && data->opy > data->ceny)
	{
		data->Bdiagx = data->cenx - SHIFTX - data->fcol;
		data->Bdiagy = data->row;
		data->Adiagx = data->col;
		data->Adiagy = data->ceny - SHIFTY - data->frow;
		data->opstartdown = 1;
	}
}

int right_side_closed(t_data *data)
{
	int i;

	i = 0;
	while (data->map[i][data->row - 1])
	{
		if (data->map[i][data->row - 1] == data->my_player)
			return (1);
		if (i == data->col - 1)
			break ;
		i++;
	}
	return (0);
}

int down_side_closed(t_data *data)
{
	int j;

	j = 0;
	while (data->map[data->col - 1][j])
	{
		if (data->map[data->col - 1][j] == data->my_player)
			return (1);
		j++;
	}
	return (0);
}


int in_center(t_data *data) //check when i in centr square/
{
	int i;
	int j;

	i = data->cenx - DELTAX;
	while (i < data->cenx + DELTAX)
	{
		j = data->ceny - DELTAY;
		while (j < data->ceny + DELTAY)
		{
			if (data->map[i][j] == data->my_player || data->map[i][j] == data->op_player)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int left_side_closed(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] == data->my_player)
			return (1);
		if (i == data->col - 1)
			break ;
		i++;
	}
	return (0);
}

int up_side_closed(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] == data->my_player)
			return (1);
		j++;
	}
	return (0);
}

int move_to_leftup(t_data *data)
{
	if (left_side_closed(data) && up_side_closed(data) )
		select_short_way_enemy(&(data->lst), data);
	else if (data->ver > data->hor)
	{
		if (up_side_closed(data))
		{
			short_way_to_diagB(&(data->lst), data);
			return (1);
		}
		else
			short_way_to_diagA(&(data->lst), data);
		return (1);
	}
	else
	{
		if (left_side_closed(data))
		{
			short_way_to_diagA(&(data->lst), data);
			return (1);
		}
		else
			short_way_to_diagB(&(data->lst), data);
	}
	return (1);
}

int move_to_rigtdown(t_data *data)
{
	if (right_side_closed(data) && down_side_closed(data))
		select_short_way_tocenr(&(data->lst), data);
	else if (data->ver > data->hor)
	{
		if (down_side_closed(data))
		{
			short_way_to_diagB(&(data->lst), data);
			return (1);
		}
		else
			short_way_to_diagA(&(data->lst), data);
		return (1);
	}
	else
	{
		if (right_side_closed(data))
		{
			short_way_to_diagA(&(data->lst), data);
			return (1);
		}
		else
			short_way_to_diagB(&(data->lst), data);
	}
	return (1);
}

void put_my_fig(t_data *data)
{
	if (take_cor_where_to_put(data) == 1)
	{
		if (in_center(data)) // if i in center start move to diagonal to cut a biggest part of the map
		{
			take_diagonal(data);
			data->opstartdown ? move_to_rigtdown(data) : move_to_leftup(data);
			ft_memdel((void **) &(data->lst));
		}
		else // go to center
		{
			select_short_way_tocenr(&(data->lst), data);
			ft_memdel((void **) &(data->lst));
		}
		ft_putnbr_fd(data->myx, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(data->myy, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		ft_putstr_fd("0 0\n", 1);
		return ;
	}
}