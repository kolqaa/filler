#include "filler.h"

void select_short_way_enemy(t_flist **lst, t_data *data) //find way to centr
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
		if (ft_sqrt(ft_pow(tmp->x - data->opx, 2) + ft_pow(tmp->y - data->opy, 2)) < tmpdst)
		{
			ft_putstr_fd("IN IFFFFFFFFFFF\n", data->fd);
			tmpdst = ft_sqrt(ft_pow(tmp->x - data->opx, 2) + ft_pow(tmp->y - data->opy, 2));
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
		data->opstartup = 1;
	}
	/*if (data->opx < data->cenx && data->opy > data->ceny)
	{

		data->Adiagx = 0;
		data->Adiagy = data->ceny - SHIFTY;
		data->Bdiagx = data->cenx + SHIFTX;
		data->Bdiagy = data->row;
	}
	if (data->opx > data->cenx && data->opy < data->ceny)
	{
		data->Bdiagx = data->cenx - SHIFTX;
		data->Bdiagy = 0;
		data->Adiagx = data->col;
		data->Adiagy = data->ceny + SHIFTY;
	}*/
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
	int j;
	int flag;

	flag = 0;
	i = 0;
	j = 0;
	i = 0;
	while (data->map[i][data->row - 1])
	{
		if (data->map[i][data->row - 1] == data->my_player)
			flag++;
		if (i == data->col - 1)
			break ;
		i++;
	}
	if (flag)
		return (1);
	return (0);
}

int down_side_closed(t_data *data)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (data->map[data->col - 1][j])
	{
		if (data->map[data->col - 1][j] == data->my_player)
			flag++;
		j++;
	}
	if (flag)
		return (1);
	else
		return (0);
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
	int flag;

	flag = 0;
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
		select_short_way_tocenr(&(data->lst), data);
	else if (data->ver > data->hor)
	{
		if (up_side_closed(data))
		{ ft_putstr_fd("A CLOSED I\n",data->fd);
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

void put_my_fig(t_data *data)
{
	ft_putstr_fd("in put my fig\n", data->fd);
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
			ft_putstr_fd("end if\n", data->fd);
			select_short_way_tocenr(&(data->lst), data);
			ft_memdel((void **) &(data->lst));
			ft_putstr_fd("AFTER MEMDELI\n",data->fd);
		}
		ft_putstr_fd("PUT COORD I\n",data->fd);
		ft_putstr_fd("player->myx = ", data->fd);
		ft_putnbr_fd(data->myx, data->fd);
		ft_putchar_fd('\n', data->fd);
		ft_putstr_fd("player->myy = ", data->fd);
		ft_putnbr_fd(data->myy, data->fd);
		ft_putchar_fd('\n', data->fd);
		ft_putnbr_fd(data->myx, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(data->myy, 1);
		ft_putchar_fd('\n', 1);
		ft_putstr_fd("PUT COORD END\n",data->fd);
	}
	else
	{
		ft_putstr_fd("FIGURA TVAR\n", data->fd);
		ft_putstr_fd("0 0\n", 1);
		return ;
	}
}