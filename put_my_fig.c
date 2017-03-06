#include "filler.h"


void	take_diagonal(t_data *data)
{ /* take two diagonal where we should to move. Based on the position of my enemy.
 * We split map on the four square and check coordint of enemy and compare it whith center coordinate*/
	if (data->opx < data->cenx && data->opy < data->ceny)
	{

		data->Adiagx = 0;
		data->Adiagy = data->ceny + SHIFTY;
		data->Bdiagx = data->cenx + SHIFTX;
		data->Bdiagy = 0;
	}
	if (data->opx < data->cenx && data->opy > data->ceny)
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
	}
	if (data->opx > data->cenx && data->opy > data->ceny)
	{

		data->Bdiagx = data->cenx - SHIFTX;
		data->Bdiagy = data->row;
		data->Adiagx = data->col;
		data->Adiagy = data->ceny - SHIFTY;
	}
}

int close_diagB(t_data *data)
{
	ft_putstr_fd("Close diag B\n", data->fd);
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] == data->my_player)
			flag++;
		i++;
		if (i == data->col)
			break ;
	}
	if (flag)
		return (1);
	return (0);
}


int close_diagA(t_data *data)
{
	ft_putstr_fd("Close diagA\n", data->fd);
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] == data->my_player)
			flag++;
		j++;
	}
	j = 0;
	while (data->map[data->col - 1][j])
	{
		if (data->map[i][j] == data->my_player)
			flag++;
		j++;
	}
	if (flag)
		return (1);
	return (0);
}

int move_to_diag(t_data *data)
{
	ft_putstr_fd("in move to diag\n", data->fd);
	if (data->ver > data->hor)
	{
		/*ft_putstr_fd("VER > HOR\n", data->fd);
		if (close_diagA(data) == 1)
			short_way_to_diagB(&(data->lst), data);
		else*/
			short_way_to_diagA(&(data->lst), data);
		return (1);
	}
	else
	{
		/*ft_putstr_fd("ELSE OT HOR\n", data->fd);
		if (close_diagB(data) == 1)
			short_way_to_diagA(&(data->lst), data);
		else
*/            short_way_to_diagB(&(data->lst), data);
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
			if (data->map[i][j] == data->my_player)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void put_my_fig(t_data *data)
{

	ft_putstr_fd("in put my fig\n", data->fd);
	if (take_cor_where_to_put(data) == 1)
	{
		if (in_center(data)) // if i in center start move to diagonal to cut a biggest part of the map
		{
			ft_putstr_fd("CHECK WHERE I\n",data->fd);
			take_diagonal(data);
			move_to_diag(data);
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