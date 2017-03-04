

#include "filler.h"

void	take_figure_size(char *line, t_fig *fig)
{
	fig->fcol = ft_atoi(&line[6]);
	fig->frow = ft_atoi(ft_strchr(&line[6], ' ') + 1);
	fig->figmap = (char **) malloc(sizeof(char *) * (fig->fcol + 1));
	if (fig->figmap == NULL)
		return ;
	fig->figmap[fig->fcol] = 0;
}