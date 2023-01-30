#include "../fractol.h"

void zoom(t_fract *fract, double zoom_fac)
{
	fract->zoom += zoom_fac;
	fract->min_x /= fract->zoom;
	fract->max_x /= fract->zoom;
	fract->min_y /= fract->zoom;
	fract->max_y /= fract->zoom;
}
