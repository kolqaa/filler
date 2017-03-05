#include "filler.h"


void	take_diagonal(t_map *map, t_pla *player, t_check *test)
{ /* take two diagonal where we should to move. Based on the position of my enemy.
 * We split map on the four square and check coordint of enemy and compare it whith center coordinate*/
	if (player->opx < map->cenx && player->opy < map->ceny)
	{

		map->Adiagx = 0;
		map->Adiagy = map->ceny + SHIFTY;
		map->Bdiagx = map->cenx + SHIFTX;
		map->Bdiagy = 0;
	}
	if (player->opx < map->cenx && player->opy > map->ceny)
	{

		map->Adiagx = 0;
		map->Adiagy = map->ceny - SHIFTY;
		map->Bdiagx = map->cenx + SHIFTX;
		map->Bdiagy = map->row;
	}
	if (player->opx > map->cenx && player->opy < map->ceny)
	{

		map->Bdiagx = map->cenx - SHIFTX;
		map->Bdiagy = 0;
		map->Adiagx = map->col;
		map->Adiagy = map->ceny + SHIFTY;
	}
	if (player->opx > map->cenx && player->opy > map->ceny)
	{

		map->Bdiagx = map->cenx - SHIFTX;
		map->Bdiagy = map->row;
		map->Adiagx = map->col;
		map->Adiagy = map->ceny - SHIFTY;
	}
}
int close_diagB(t_map *map, t_pla *player, t_check *test)
{
	ft_putstr_fd("Close diag B\n", test->fd);
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] == player->my_player)
			flag = 1;
		i++;
		if (i == map->col)
			break ;
	}
	if (flag == 1)
		return (1);
	return (0);
}

int close_diagA(t_map *map, t_pla *player, t_check *test)
{
	ft_putstr_fd("Close diagA\n", test->fd);
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] == player->my_player)
			flag = 1;
		j++;
	}
	j = 0;

	while (map->map[map->col - 1][j])
	{
		if (map->map[i][j] == player->my_player)
			flag = 1;
		j++;
	}
	if (flag)
		return (1);
	ft_putstr_fd("SEGAMEGA DRIVE3\n", test->fd);
	return (0);
}


int move_to_diag(t_map *map, t_pla *player, t_check *test, t_fig *fig)
{
	ft_putstr_fd("in move to diag\n", test->fd);
	if (map->ver > map->hor)
	{
		/*ft_putstr_fd("VER > HOR\n", test->fd);
		if (close_diagA(map, player, test))
			short_way_to_diagB(&(map->lst), map, player, test);
		else*/
			short_way_to_diagA(&(map->lst), map, player, test);
		return (1);
	}
	else
	{
		/*ft_putstr_fd("ELSE OT HOR\n", test->fd);
		if (close_diagB(map, player, test))
			short_way_to_diagA(&(map->lst), map, player, test);
		else*/
			short_way_to_diagB(&(map->lst), map, player, test);
	}
	return (1);
}

int in_center(t_map *map, t_check *test, t_pla *player) //check when i in centr square/
{
	int i;
	int j;

	i = map->cenx - DELTAX;
	while (i < map->cenx + DELTAX)
	{
		j = map->ceny - DELTAY;
		while (j < map->ceny + DELTAY)
		{
			if (map->map[i][j] == player->my_player)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	put_my_fig(t_fig *fig, t_pla *player, t_map *map, t_check *test)
{

	ft_putstr_fd("in put my fig\n", test->fd);
	if (take_cor_where_to_put(fig, map, player, test) == 1)
	{
		if (in_center(map, test, player)) // if i in center start move to diagonal to cut a biggest part of the map
		{
			ft_putstr_fd("CHECK WHERE I\n",test->fd);
			take_diagonal(map, player, test);
			move_to_diag(map, player, test, fig);
			ft_memdel((void **) &(map->lst));
		}
		else // go to center
		{
			ft_putstr_fd("end if\n", test->fd);
			select_short_way_tocenr(&(map->lst), map, player, test);
			ft_memdel((void **) &(map->lst));
		}
		ft_putnbr_fd(player->myx, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(player->myy, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		ft_putstr_fd("FIGURA TVAR\n", test->fd);
		ft_putstr_fd("0 0\n", 1);
		return ;
	}
}