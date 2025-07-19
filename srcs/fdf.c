#include "../fdf.h"

void	fdf_hook(t_data *data)
{
	mlx_loop_hook(data->mlx, ft_render_map, data);
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
	ft_render_map(&data);
	fdf_hook(&data);
}
