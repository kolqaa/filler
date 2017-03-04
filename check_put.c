

#include "filler.h"

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
		ft_putstr_fd("count == 1\n", test->fd);
		write_coor_in_lst(&(map->lst), i, j);
		/*player->myx = i;
		player->myy = j;*/
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
		ft_putstr_fd("end if\n", test->fd);
		select_short_way_tocenr(&(map->lst), map, player, test);
		return (1);
	}
	return (0);
}