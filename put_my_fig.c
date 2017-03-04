#include "filler.h"

void	put_my_fig(t_fig *fig, t_pla *player, t_map *map, t_check *test)
{
	ft_putstr_fd("in put my fig\n", test->fd);
	if (take_cor_where_to_put(fig, map, player, test) == 1)
	{
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