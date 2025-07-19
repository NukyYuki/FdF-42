#include "../../fdf.h"

void	ft_view_init(t_data *data)
{
	data->view.x_offset = data->win_width / 2;
	data->view.y_offset = data->win_height / 2;
	data->view.zoom = 20;
	data->view.height_scale = 1.0;
	data->view.angle_x = 0.0;
	data->view.angle_y = 0.0;
	data->view.angle_z = 0.0;
}
