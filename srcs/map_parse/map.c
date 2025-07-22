#include "../../fdf.h"


void	ft_map_init(t_data *data, char *file)
{
	int	fd;

	data->map = ft_calloc(1, sizeof(t_map));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_free_data_struct(data));
	ft_map_size(data, fd);
	close(fd);
	data->map->map_points = ft_map_create(data->map->map_x, data->map->map_y);
	if (!data->map->map_points)
		return (ft_free_data_struct(data));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_free_data_struct(data));
	ft_map_get_points(data, fd);
	ft_get_z(data);
	close(fd);
}
