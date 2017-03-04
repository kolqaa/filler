#include "filler.h"

void	get_map_size(char **line, t_map *map)
{
	while (**line)
	{
		if (**line >= '0' && **line <= '9')
		{
			if (map->col == 0)
				map->col = ft_atoi(*line);
			else
				map->row = ft_atoi(*line);
			while (**line >= '0' && **line <= '9')
				(*line)++;
		}
		(*line)++;
	}
	map->map = (char **)malloc(sizeof(char *) * (map->col + 1));
	if (map->map == NULL)
		return ;
	map->map[map->col] = 0;
}