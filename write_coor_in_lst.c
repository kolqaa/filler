#include "filler.h"


void	write_coor_in_lst(t_flist **lst, int i, int j, t_check *test) // create and write cor in lst
{
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("in write cor\n", test->fd);
	t_flist *tmp;
	t_flist *tmp2;

	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("my i in cor\n", test->fd);
	ft_putnbr_fd(i, test->fd);
	ft_putchar_fd('\n', test->fd);
	ft_putstr_fd("my j in cor\n", test->fd);
	ft_putnbr_fd(j, test->fd);
	ft_putchar_fd('\n', test->fd);

	tmp = (t_flist *)malloc(sizeof(*tmp));
	tmp->x = i;
	tmp->y = j;
	tmp->next = NULL;

	if (*lst == NULL)
		*lst = tmp;
	else
	{
		tmp2 = *lst;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
}