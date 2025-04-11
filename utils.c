include "so_long.h"

int	get_array_size(const char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}
