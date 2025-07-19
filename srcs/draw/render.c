#include "../../fdf.h"

int	ft_render_map(t_data *data)
{
	t_line			line;
	int				y;
	int				x;

	y = 0;
	x = 0;
	line.color = 0xFF0000;
	while (y < data->map->map_y)
	{
		while (x < data->map->map_x)
		{
			isometric_projection(data, &data->map->map_points[y][x], &line.x0, &line.y0);
//			line_update_right(&line, data, x, y);
			if (x + 1 < data->map->map_x)
			{
				isometric_projection(data, &data->map->map_points[y][x + 1], &line.x1, &line.y1);
				//line.color = choose_color();
				draw_line(data, &line);
			}
//			line_update_down(&line, data, x, y);
			if (y + 1 < data->map->map_y)
			{
				isometric_projection(data, &data->map->map_points[y + 1][x], &line.x1, &line.y1);
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


/*void	ft_screen_position(t_data *data, int x, int y, int *screen_x, int *screen_y)
{
	int	z = data->map->map_points[y][x].z;
}*/
