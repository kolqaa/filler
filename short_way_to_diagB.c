#include "filler.h"

#include "filler.h"

void short_way_to_diagB(t_flist **lst, t_map *map, t_pla *player, t_check *test) //find way to centr
{
	/*check my lst of all possible coordinate and choose best one which close to the center*/
	t_flist *tmp;

	ft_putstr_fd("SHORT WAY TO B\n", test->fd);
	int tmpx;
	int tmpy;
	int tmpdst;

	tmpdst = 214721389;
	tmp = *lst;
	while (tmp)
	{
		if (ft_sqrt(
				ft_pow(tmp->x - map->Bdiagx, 2) + ft_pow(tmp->y - map->Bdiagy, 2)) <
			tmpdst)
		{

			tmpdst = ft_sqrt(ft_pow(tmp->x - map->Bdiagx, 2) +
							 ft_pow(tmp->y - map->Bdiagy, 2));
			tmpx = tmp->x;
			tmpy = tmp->y;
		}
		tmp = tmp->next;
	}
	player->myx = tmpx;
	player->myy = tmpy;
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("Bmy coord to put x -->>> ", test->fd);
	ft_putnbr_fd(tmpx, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("Bmycoord to put y-->>> ", test->fd);
	ft_putnbr_fd(tmpy, test->fd);
	ft_putchar_fd('\n', test->fd);
}

