#include "../../fdf.h"

void	ft_window_init(t_data *data)
{
	data->win_height = 1080;
	data->win_width = 1920;
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->mlx_win = mlx_new_window(data->mlx, data->win_width, data->win_height, "mipinhei - FDF");
	if (!data->mlx_win)
		ft_free_data_struct(data);
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_lenght,
									&data->endian);
}
