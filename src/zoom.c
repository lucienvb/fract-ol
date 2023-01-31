#include "../fractol.h"

void zoom_in(t_fract *fract)
{
	if (fract->zoom_out != 1)
		fract->zoom_out = 1;
	fract->zoom_in -= fract->zoom_fac;
	fract->min_x /= fract->zoom_in;
	fract->max_x /= fract->zoom_in;
	fract->min_y /= fract->zoom_in;
	fract->max_y /= fract->zoom_in;
}

void zoom_out(t_fract *fract)
{
	if (fract->zoom_in != 1)
		fract->zoom_in = 1;
	fract->zoom_out += fract->zoom_fac;
	fract->min_x /= fract->zoom_out;
	fract->max_x /= fract->zoom_out;
	fract->min_y /= fract->zoom_out;
	fract->max_y /= fract->zoom_out;
}
