#include "../../fdf.h"

void	draw_line(t_data *data, t_line *line)
{
	int	dx;
	int	dy;

	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	if (ft_abs(line->x1-line->x0) > abs(line->y1-line->y0))
		draw_lineH(data, line, dx, dy);
	else
		draw_lineV(data, line, dx, dy);
}

void	draw_lineH(t_data *data, t_line *line, int dx, int dy)
{
	int		dir;
	int		step;
	int 	y;
	int 	x;
	float	percent;

	dir = 1;
	if (line->x0 > line->x1)
	{
		ft_swap(&line->x0, &line->x1);
		ft_swap(&line->y0, &line->y1);
	}
	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	if (dy < 0)
		dir = -1;
	dy *= dir;
	if (dx != 0)
	{
		y = line->y0;
		step = (2 * dy) - dx;
		x = line->x0;
		while (x++ <= line->x1)
		{
			percent = 0.0f;
			if (line->x1 != line->x0)
				percent = (float)(x - line->x0) /  (float)(line->x1 - line->x0);
			line->color = interpolate_color(line->color_start, line->color_end, percent);
			ft_put_pixel(data, x, y, line->color);
			if (step >= 0)
			{
				y += dir;
				step -= (2 * dx);
			}
			step += (2 * dy);
		}
	}
}

void	draw_lineV(t_data *data, t_line *line, int dx, int dy)
{
	int		dir;
	int		step;
	int 	x;
	int 	y;
	float	percent;

	dir = 1;
	if (line->y0 > line->y1)
	{
		ft_swap(&line->x0, &line->x1);
		ft_swap(&line->y0, &line->y1);
	}
	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	if (dx < 0)
		dir = -1;
	dx *= dir;
	if (dy != 0)
	{
		x = line->x0;
		step = (2 * dx) - dy;
		y = line->y0;
		while (y++ <= line->y1)
		{
			percent = 0.0f;
			if (line->y1 != line->y0)
				percent = (float)(y - line->y0) /  (float)(line->y1 - line->y0);
			line->color = interpolate_color(line->color_start, line->color_end, percent);
			ft_put_pixel(data, x, y, line->color);
			if (step >= 0)
			{
				x += dir;
				step -= (2 * dy);
			}
			step += (2 * dx);
		}
	}
}
