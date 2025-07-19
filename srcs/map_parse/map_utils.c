#include "../../fdf.h"

void	ft_map_size(t_data *data, int file)
{
	char	*map_line;
	char	**map_points;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map_line = get_next_line(file);
	data->map->map_x = 0;
	while (map_line)
	{
		map_points = ft_split(map_line, ' ');
		while (map_points[x])
			x++;
		if (data->map->map_x < x)
			data->map->map_x = x;
		x = 0;
		free(map_line);
		map_line = get_next_line(file);
		y++;
	}
	data->map->map_y = y;
	free(map_line);
}

t_point **ft_map_create(int width, int height)
{
	t_point **points;
	int		y;
	
	y = 0;
	points = malloc(sizeof(t_point *) * height);
	if (!points)
		return (NULL);
	while (y < height)
	{
		points[y] = malloc(sizeof(t_point) * width);
		if (!points[y])
		{
			while (y >= 0)
				free(points[y--]);
			free(points);
			return (NULL);
		}
		y++;
	}
	return (points);
}

void	ft_map_get_points(t_data *data, int fd)
{
	char	*map_line;
	char	**map_points;
	int		x;
	int		y;

	x = 0;
	y = -1;
	map_line = get_next_line(fd);
	while (map_line)
	{
		map_points = ft_split(map_line, ' ');
		if (!map_points)
			ft_free_data_struct(data);
		y++;
		x = 0;
		while (map_points[x] && x < data->map->map_x)
		{
			data->map->map_points[y][x].x = x;
			data->map->map_points[y][x].y = y;
			data->map->map_points[y][x].z = ft_atoi(map_points[x]);
			x++;
		}
		free_char_arr(map_points);
		free(map_line);
		map_line = get_next_line(fd);
	}
}
