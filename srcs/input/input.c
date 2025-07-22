#include "../../fdf.h"
#include <stdio.h>

int	ft_key_press(int keycode, t_data *data)
{
	ft_close(data, keycode);
	ft_rendering_type(data, keycode);
	ft_move(data, keycode);
	ft_zoom(data, keycode);
	ft_reset(data, keycode);
	ft_scaling(data, keycode);
	return (0);
}

int	ft_close(t_data *data, int keycode)
{
	if (keycode == ESC)
	{
		ft_free_data_struct(data);
		exit(0);
	}
	return (0);
}

int	ft_rendering_type(t_data *data, int keycode)
{
	if (keycode == I)
	{
		data->projection = ISO;
		return (1);
	}
	if (keycode == O)
	{
		data->projection = ORTO;
		return (1);
	}
	return (0);
}

int	ft_move(t_data *data, int keycode)
{
	if (keycode == UP)
	{
		data->view.y_offset -= 10;
		return (1);
	}
	if (keycode == DOWN)
	{
		data->view.y_offset += 10;
		return (1);
	}
	if (keycode == LEFT)
	{
		data->view.x_offset -= 10;
		return (1);
	}
	if (keycode == RIGHT)
	{
		data->view.x_offset += 10;
		return (1);
	}
	return (0);
}

int	ft_zoom(t_data *data, int keycode)
{
	if (keycode == PLUS)
	{
		data->view.zoom += 2;
		ft_center_map(data);
		return (1);
	}
	if (keycode == MINUS && data->view.zoom > 2)
	{
		ft_center_map(data);
		data->view.zoom -= 2;
		return (1);
	}
	return (0);
}
