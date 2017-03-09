#include "filler.h"


void write_coor_in_lst(t_flist **lst, int i, int j) // create and write cor in lst
{

	t_flist *tmp;
	t_flist *tmp2;

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