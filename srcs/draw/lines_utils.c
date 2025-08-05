/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:15:30 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/23 14:41:09 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	ft_abs(int value)
{
	if (value >= 0)
		return (value);
	else
		return (value * -1);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	if (x >= 0 && x < data->win_width
		&& y >= 0 && y < data->win_height)
		*(int *)(data->addr + (y * data->line_lenght + x
					* (data->bits_per_pixel / 8))) = color;
}

void	ft_percent_line(float *percent, t_line *line, int val, int id)
{
	*percent = 0.0f;
	if (id == 1)
	{
		if (line->x1 != line->x0)
			*percent = (float)(val - line->x0) / (float)(line->x1 - line->x0);
	}
	else if (id == 0)
		if (line->y1 != line->y0)
			*percent = (float)(val - line->y0) / (float)(line->y1 - line->y0);
	line->color = interpolate_color(line->color_start,
			line->color_end, *percent);
}
