#include "filler.h"


void	take_diagonal(t_map *map, t_pla *player, t_check *test)
{ /* take two diagonal where we should to move. Based on the position of my enemy.
 * We split map on the four square and check coordint of enemy and compare it whith center coordinate*/
	ft_putstr_fd("TAKE DIAG\n", test->fd);
	if (player->opx < map->cenx && player->opy < map->ceny)
	{
		ft_putstr_fd("TAKE DIAG 1\n", test->fd);
		map->Adiagx = 0;
		map->Adiagy = map->ceny;
		map->Bdiagx = map->cenx;
		map->Bdiagy = 0;
	}
	if (player->opx < map->cenx && player->opy > map->ceny)
	{
		ft_putstr_fd("TAKE DIAG 2\n", test->fd);
		map->Adiagx = 0;
		map->Adiagy = map->ceny;
		map->Bdiagx = map->cenx;
		map->Bdiagy = map->row;
	}
	if (player->opx > map->cenx && player->opy < map->ceny)
	{
		ft_putstr_fd("TAKE DIAG 3 \n", test->fd);
		map->Bdiagx = map->cenx;
		map->Bdiagy = 0;
		map->Adiagx = map->col;
		map->Adiagy = map->ceny;
	}
	if (player->opx > map->cenx && player->opy > map->ceny)
	{
		ft_putstr_fd("TAKE DIAG 4\n", test->fd);
		map->Bdiagx = map->cenx;
		map->Bdiagy = map->row;
		map->Adiagx = map->col;
		map->Adiagy = map->ceny;
	}
/*	ft_putstr_fd("Bdiagx -->>> ", test->fd);
	ft_putnbr_fd(map->Bdiagx, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("Bdiagy -->>> ", test->fd);
	ft_putnbr_fd(map->Bdiagy, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("Adiagx -->>> ", test->fd);
	ft_putnbr_fd(map->Adiagx, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("Adiagy -->>> ", test->fd);
	ft_putnbr_fd(map->Adiagy, test->fd);
	ft_putchar_fd('\n', test->fd);*/
}


int move_to_diag(t_map *map, t_pla *player, t_check *test, t_fig *fig)
{
	ft_putstr_fd("MOVE TO DIAG\n", test->fd);
	if (map->ver > map->hor)
	{
		short_way_to_diagA(&(map->lst), map, player, test);
		return (1);
	}
	else
	{
		short_way_to_diagB(&(map->lst), map, player, test);
		return (1);
	}
}

int if_it_center(t_map *map, t_check *test, t_pla *player) //check when i in centr square/
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
		if (if_it_center(map, test, player)) // if i in center start move to diagonal to cut a biggest part of the map
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