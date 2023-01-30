#include "../fractol.h"
#include <stdio.h>

mlx_image_t	*create_new_window(void *ptr, int width, int height)
{
	return (mlx_new_image(ptr, width, height));
}