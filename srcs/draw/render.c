#include "../../fdf.h"

void	ft_render_map(t_data *data)
{
	t_line	line;
	int		y;
	int		x;

	y = -1;
	x = -1;
	line.color = 0xFFFFFF;
	while (y++ < data->map->map_y)
	{
		while (x++ < data->map->map_x)
		{
			line_update_right(&line, data, x, y);
			if (x + 1 < data->map->map_x)
			{
				//line.color = choose_color();
				draw_line(data, &line);
			}
			line_update_down(&line, data, x, y);
			if (y + 1 < data->map->map_y)
			{
				draw_line(data, &line);
			}
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}


/*void	ft_screen_position(t_data *data, int x, int y, int *screen_x, int *screen_y)
{
	int	z = data->map->map_points[y][x].z;
}*/
