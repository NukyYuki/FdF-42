#include "../fdf.h"

void	fdf_events(t_data *data)
{
	mlx_loop_hook(data->mlx, ft_render_loop, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_key_press, data);
	mlx_loop(data->mlx);
}

int main (int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (-1);
	ft_bzero(&data, sizeof(t_data));
	ft_window_init(&data);
	ft_view_init(&data);
	ft_map_init(&data, av[1]);
	ft_center_map(&data);
	fdf_events(&data);
}
