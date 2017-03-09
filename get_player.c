#include "filler.h"

char get_player(char *str, t_data *data)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'p' && str[i + 1] == '1')
		{
			data->op_player = P2;
			return (P1);
		}

		if (str[i] == 'p' && str[i + 1] == '2')
		{
			data->op_player = P1;
			return (P2);
		}
		i++;
	}
	return (0);
}