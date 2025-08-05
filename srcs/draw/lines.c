/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:15:10 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/23 16:05:28 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	draw_line(t_data *data, t_line *line)
{
	int	dx;
	int	dy;

	dx = line->x1 - line->x0;
	dy = line->y1 - line->y0;
	if (ft_abs(line->x1 - line->x0) > abs(line->y1 - line->y0))
		draw_lineh(data, line, dx, dy);
	else
		draw_linev(data, line, dx, dy);
}

void	ft_swap_line(t_line *line, int *dx, int *dy)
{
	ft_swap(&line->x0, &line->x1);
	ft_swap(&line->y0, &line->y1);
	*dx = line->x1 - line->x0;
	*dy = line->y1 - line->y0;
}

void	draw_lineh(t_data *data, t_line *line, int dx, int dy)
{
	int		dir;
	int		step;
	int		y;
	int		x;
	float	percent;

	dir = 1;
	if (line->x0 > line->x1)
		ft_swap_line(line, &dx, &dy);
	if (dy < 0)
		dir = -1;
	dy *= dir;
	if (dx != 0)
	{
		xy_init_line(&x, &y, line);
		step = (2 * dy) - dx;
		while (x++ <= line->x1)
		{
			ft_percent_line(&percent, line, x, 1);
			ft_put_pixel(data, x, y, line->color);
			step_val(dir, &y, &step, dx);
			step += (2 * dy);
		}
	}
}

void	draw_linev(t_data *data, t_line *line, int dx, int dy)
{
	int		dir;
	int		step;
	int		x;
	int		y;
	float	percent;

	dir = 1;
	if (line->y0 > line->y1)
		ft_swap_line(line, &dx, &dy);
	if (dx < 0)
		dir = -1;
	dx *= dir;
	if (dy != 0)
	{
		xy_init_line(&x, &y, line);
		step = (2 * dx) - dy;
		while (y++ <= line->y1)
		{
			ft_percent_line(&percent, line, y, 0);
			ft_put_pixel(data, x, y, line->color);
			step_val(dir, &x, &step, dy);
			step += (2 * dx);
		}
	}
}
