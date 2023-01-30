#include "../libft.h"
#include <stdbool.h>

bool	input_parsing(int argc, char **argv)
{
	int overflow;

	(void)argv;
	if (argc != 3)
		return (false);
	if (!(ft_strncmp(argv[1], "mandelbrot", 11) == 0) &&
			!(ft_strncmp(argv[1], "julia", 6) == 0))
		return (false);
	if (!ft_atoi_with_overflow(argv[2], &overflow))
		return (false);
	if ((ft_atoi(argv[2]) < 1) || (ft_atoi(argv[2]) > 6))
		return (false);
	return (true);
}
