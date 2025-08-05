/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:14:44 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/23 16:51:52 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	set_background(t_data *data)
{
	int	color;

	color = 0x1b1a26;
	draw_background(data, color);
}

void	draw_background(t_data *data, int color)
{
	int	i;
	int	pixel_res;
	int	*addr;

	i = 0;
	pixel_res = data->win_height * data->win_width;
	addr = (int *)data->addr;
	while (i < pixel_res)
		addr[i++] = color;
}

int	interpolate_color(int begin, int end, float percent)
{
	int	r;
	int	g;
	int	b;

	r = ((begin >> 16) & 0xFF) + percent
		* (((end >> 16) & 0xFF) - ((begin >> 16) & 0xFF));
	g = ((begin >> 8) & 0xFF) + percent
		* (((end >> 8) & 0xFF) - ((begin >> 8) & 0xFF));
	b = (begin & 0xFF) + percent
		* ((end & 0xFF) - (begin & 0xFF));
	return ((r << 16) | (g << 8) | b);
}

float	ft_get_percent(int z, int z_min, int z_max)
{
	if (z_max == z_min)
		return (0.0);
	return ((float)(z - z_min) / (float)(z_max - z_min));
}

void	get_color(t_data *data, t_line *line, int z0, int z1)
{
	int	low_color;
	int	high_color;

	low_color = 0x06d6a0;
	high_color = 0x301ba8;
	line->color_start = interpolate_color(low_color, high_color,
			ft_get_percent(z0, data->map->min_z, data->map->max_z));
	line->color_end = interpolate_color(low_color, high_color,
			ft_get_percent(z1, data->map->min_z, data->map->max_z));
}
