#include "../../fdf.h"

void	ft_free_data_struct(t_data *data)
{
	int i;

	i = 0;
	if (data->map->map_points)
	{
		while (data->map->map_points[i])
			free(data->map->map_points[i++])
		free(data->map->map_points);
	}
	if (data->map)
		free(data->map);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	if(data->mlx)
		free(data->mlx);
	exit(1);
}

void	free_char_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
	}
	free(arr);
	return ;
}
