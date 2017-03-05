#include "filler.h"

void	rebuild_myfig(t_fig *fig, t_check *test, t_pla *player)
{
	int i;
	int j;

	i = 0;
	while (fig->figmap[i])
	{
		j = 0;
		while (fig->figmap[i][j])
		{
			if (fig->figmap[i][j] == '*')
				fig->figmap[i][j] = player->my_player;
			if (fig->figmap[i][j] == '.')
				fig->figmap[i][j] = ',';
			j++;
		}
		i++;
	}
}