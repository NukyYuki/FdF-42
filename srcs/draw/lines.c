#include "../../fdf.h"

void	draw_line(int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;

	dx = x1 - x0;
	dy = y1 - y0;
	if (ft_abs(x1-x0) > abs(y1-y0)
		draw_lineH(x0, y0, x1, y1, dx, dy);
	else
		draw_lineV(x0, y0m x1, y1, dx, dy);
}

void	draw_lineH(int x0, int y0, int x1, int y1, int dx, int dy)
{
	int	dir;
	int	step;
	int y;

	dir = 1;
	if (x0 > x1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if (dy < 0)
		dir = -1;
	dy *= dir;
	if (dx != 0)
	{
		y = y0;
		step = (2 * dy) - dx;
		while ()
		{
			mlx_pixel_put()
			if (step >= 0)
			{
				y += dir;
				p = p - (2 * dx)
			}
			p = p + (2 * dy);
		}
	}
}

void	draw_lineV(int x0, int y0, int x1, int y1, int dx, int dy)
{
	int	dir;
	int	step;
	int x;

	dir = 1;
	if (y0 > y1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	if (dx < 0)
		dir = -1;
	dx *= dir;
	if (dy != 0)
	{
		x = x0;
		step = (2 * dx) - dy;
		while ()
		{
			mlx_pixel_put()
			if (step >= 0)
			{
				x += dir;
				p = p - (2 * dy)
			}
			p = p + (2 * dx);
		}
	}
}
