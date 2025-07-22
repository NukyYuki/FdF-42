#include "../../fdf.h"

int	ft_reset(t_data *data, int keycode)
{
	if (keycode == R)
	{
		ft_view_init(data);
		ft_center_map(data);
		return (1);
	}
	return (0);
}

int	ft_scaling(t_data *data, int keycode)
{
	if (keycode == S)
	{
		data->view.height_scale += 0.2;
		return (1);
	}
	if (keycode == D && data->view.height_scale > 0.2)
	{
		data->view.height_scale -= 0.2;
		return (1);
	}
	return (0);
}
