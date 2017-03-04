

#include "filler.h"


void	take_diagonal(t_map *map, t_pla *player)
{
	if (player->opx < map->cenx && player->opy < map->ceny)
	{
		map->Adiagx = 0;
		map->Adiagy = map->ceny;
		map->Bdiagx = map->cenx;
		map->Bdiagx = 0;
	}
	if (player->opx < map->cenx && player->opy > map->ceny)
	{

	}
}

int algoritm_to_win_all(t_map *map, t_pla *player)
{

}

int check_where_i(t_map *map, t_check *test, t_pla *player) //check when i in centr square/
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

int check_put(t_fig *fig, t_map *map, int i, int j, t_pla *player, t_check *test)
{
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
	while (fig->figmap[x])
	{
		y = 0;
		newj = j;
		while (fig->figmap[x][y])
		{
			if (map->map[newi][newj] == fig->figmap[x][y])
				count++;
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
		ft_putstr_fd("coordinati dlya otpravki i -->>> ", test->fd);
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
		ft_putchar_fd('\n', test->fd);
		count = 0;
	}
	/*ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("+++++i ", test->fd);
	ft_putnbr_fd(i, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putnbr_fd(map->col - fig->fcol + 1, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("+++++j ", test->fd);
	ft_putnbr_fd(j, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putnbr_fd(map->row - fig->frow + 1, test->fd);
	ft_putchar_fd('\n', test->fd);*/
	if (i == (map->col - fig->fcol) && j == (map->row - fig->frow)) // esli fig nekuda stavit vse variacii end
	{
		if (check_where_i(map, test, player)) // if i already in centr strat put my fig in diag->x diag-y
		{
			take_diagonal(map, player);
			algoritm_to_win_all(map, palyer);
			return (1);
		}
		else
		{
			ft_putstr_fd("end if\n", test->fd);
			select_short_way_tocenr(&(map->lst), map, player, test);
			ft_memdel((void **) &(map->lst));
			return (1);
		}
	}
	return (0);
}