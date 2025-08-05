/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:22:44 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/23 13:13:38 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	ft_render_iso(t_data *data)
{
	t_line			line;
	int				y;
	int				x;

	y = 0;
	set_background(data);
	while (y < data->map->map_y)
	{
		x = 0;
		while (x < data->map->map_x)
		{
			isometric_projection(data, &data->map->map_points[y][x],
				&line.x0, &line.y0);
			if (x + 1 < data->map->map_x)
				iso_helper(data, &data->map->map_points[y][x + 1], line,
					data->map->map_points[y][x].z);
			if (y + 1 < data->map->map_y)
				iso_helper(data, &data->map->map_points[y + 1][x],
					line, data->map->map_points[y][x].z);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

void	iso_helper(t_data *data, t_point *map_pts, t_line line, int z)
{
	get_color(data, &line, z, map_pts->z);
	isometric_projection(data, map_pts, &line.x1, &line.y1);
	draw_line(data, &line);
}

int	ft_render_orto(t_data *data)
{
	t_line			line;
	int				y;
	int				x;

	y = 0;
	set_background(data);
	while (y < data->map->map_y)
	{
		x = 0;
		while (x < data->map->map_x)
		{
			ortographic_projection(data, &data->map->map_points[y][x],
				&line.x0, &line.y0);
			if (x + 1 < data->map->map_x)
				orto_helper(data, &data->map->map_points[y][x + 1],
					line, data->map->map_points[y][x].z);
			if (y + 1 < data->map->map_y)
				orto_helper(data, &data->map->map_points[y + 1][x],
					line, data->map->map_points[y][x].z);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

void	orto_helper(t_data *data, t_point *map_pts, t_line line, int z)
{
	get_color(data, &line, z, map_pts->z);
	ortographic_projection(data, map_pts, &line.x1, &line.y1);
	draw_line(data, &line);
}
