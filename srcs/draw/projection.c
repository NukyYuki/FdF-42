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
	*line_y = (pt_y * data->view.zoom - map_pts->z * data->view.height_scale + data->view.y_offset);
}
