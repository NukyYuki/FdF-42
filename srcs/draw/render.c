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
			isometric_projection(data, &data->map->map_points[y][x], &line.x0, &line.y0);
			if (x + 1 < data->map->map_x)
			{
				get_color(data, &line, data->map->map_points[y][x].z, data->map->map_points[y][x + 1].z);
				isometric_projection(data, &data->map->map_points[y][x + 1], &line.x1, &line.y1);
				draw_line(data, &line);
			}
			if (y + 1 < data->map->map_y)
			{
				get_color(data, &line, data->map->map_points[y][x].z, data->map->map_points[y + 1][x].z);
				isometric_projection(data, &data->map->map_points[y + 1][x], &line.x1, &line.y1);
				draw_line(data, &line);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int	ft_render_orto(t_data *data)
{
	t_line			line;
	int				y;
	int				x;

	y = 0;
	x = 0;
	line.color = 0xFF0000;
	set_background(data);
	while (y < data->map->map_y)
	{
		while (x < data->map->map_x)
		{
			ortographic_projection(data, &data->map->map_points[y][x], &line.x0, &line.y0);
			if (x + 1 < data->map->map_x)
			{
				get_color(data, &line, data->map->map_points[y][x].z, data->map->map_points[y][x + 1].z);
				ortographic_projection(data, &data->map->map_points[y][x + 1], &line.x1, &line.y1);
				draw_line(data, &line);
			}
			if (y + 1 < data->map->map_y)
			{
				get_color(data, &line, data->map->map_points[y][x].z, data->map->map_points[y + 1][x].z);
				ortographic_projection(data, &data->map->map_points[y + 1][x], &line.x1, &line.y1);
				draw_line(data, &line);
			}
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}
