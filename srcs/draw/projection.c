#include "../../fdf.h"

void	isometric_projection(t_data *data, t_point *map_pts, int *line_x, int *line_y)
{
	float	iso_angle;
	float	pt_x;
	float	pt_y;
	float	pt_z;

	iso_angle = 0.523599;
	pt_x = (float)map_pts->x;
	pt_y = (float)map_pts->y;
	pt_z = (float)map_pts->z * data->view.height_scale;
	*line_x = (int)((pt_x - pt_y) * cos(iso_angle) * data->view.zoom + data->view.x_offset);
	*line_y = (int)((pt_x + pt_y) * sin(iso_angle) * data->view.zoom - pt_z + data->view.y_offset);
}

void	ortographic_projection(t_data *data, t_point *map_pts, int *line_x, int *line_y)
{
	int	pt_x;
	int	pt_y;

	pt_x = map_pts->x;
	pt_y = map_pts->y;
	*line_x = (pt_x * data->view.zoom + data->view.x_offset);
	*line_y = (pt_y * data->view.zoom + data->view.y_offset);
}

void	ft_center_map(t_data *data)
{
	t_coordinate	screen;
	int				y;
	int				x;

	center_map_init(data, &y, &x);
	while (y < data->map->map_y)
	{
		x = 0;
		while (x < data->map->map_x)
		{
			if (data->projection == ISO)
				isometric_projection(data, &data->map->map_points[y][x], &screen.x, &screen.y);
			else
				ortographic_projection(data, &data->map->map_points[y][x], &screen.x, &screen.y);
			if (screen.x < data->map->min_x)
				data->map->min_x = screen.x;
			if (screen.x > data->map->max_x)
				data->map->max_x = screen.x;
			if (screen.y < data->map->min_y)
				data->map->min_y = screen.y;
			if (screen.y > data->map->max_y)
				data->map->max_y = screen.y;
			x++;
		}
		y++;
	}
	data->map->map_center_x = data->map->min_x + (data->map->max_x - data->map->min_x) / 2;
	data->map->map_center_y = data->map->min_y + (data->map->max_y - data->map->min_y) / 2;
	data->view.x_offset += (data->win_width / 2) - data->map->map_center_x;
	data->view.y_offset += (data->win_height / 2) - data->map->map_center_y;
}

void	center_map_init(t_data *data, int *y, int *x)
{
	data->map->max_x = INT_MIN;
	data->map->min_x = INT_MAX;
	data->map->max_y = INT_MIN;
	data->map->min_y = INT_MAX;
	*y = 0;
	*x = 0;
}
