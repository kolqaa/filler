

#include "filler.h"


/*void	take_diagonal(t_map *map, t_pla *player, t_check *test)
{ *//* take two diagonal where we should to move. Based on the position of my enemy.
 * We split map on the four square and check coordint of enemy and compare it whith center coordinate*//*
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
	ft_putstr_fd("Bdiagx -->>> ", test->fd);
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
	ft_putchar_fd('\n', test->fd);
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
}*/

int check_put(t_fig *fig, t_map *map, int i, int j, t_pla *player, t_check *test)
{
	/*Here we check all possible way to put my figure, and check one crosses with my player or last put figure
	 * if we find that coordinate we write it in my chained list
	 * than we take closest coordin to center from that list and go to it, if we already in center we start put my figure to
	 * diagonal.*/
	//ft_putstr_fd("check_put\n", test->fd);
	int x;
	int y;
	int count;
	int newi;
	int newj;

	newi = i;
	newj = j;
	count = 0;
	x = 0;
	while (fig->figmap[x] && map->map[newi])
	{
		y = 0;
		newj = j;
		while (fig->figmap[x][y] && map->map[newi][newj])
		{
			if (map->map[newi][newj] == fig->figmap[x][y])
				count++;
			if(map->map[newi][newj] == player->op_player && fig->figmap[x][y] == player->my_player)
				return (0);
			y++;
			newj++;
		}
		x++;
		newi++;
	}
	if (count == 1)
	{
		ft_putstr_fd("in count == 1\n", test->fd);
		write_coor_in_lst(&(map->lst), i, j, test);
		/*ft_putstr_fd("coordinati dlya otpravki i -->>> ", test->fd);
		ft_putnbr_fd(i, test->fd);
		ft_putchar_fd('\n', test->fd);
		ft_putstr_fd("coodrdinati dlya otpravki j -->>> ", test->fd);
		ft_putnbr_fd(j, test->fd);
		ft_putchar_fd('\n', test->fd);
		ft_putstr_fd("perese4eniya i -->>> ", test->fd);
		ft_putnbr_fd(newi, test->fd);
		ft_putchar_fd('\n', test->fd);
		ft_putstr_fd("perese4eniya j -->>> ", test->fd);
		ft_putnbr_fd(newj, test->fd);
		ft_putchar_fd('\n', test->fd);*/
		count = 0;
	}
	/*ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("+++++i ", test->fd);
	ft_putnbr_fd(i, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("+++++j ", test->fd);
	ft_putnbr_fd(j, test->fd);
	ft_putchar_fd('\n', test->fd);*/
	return (0);
}