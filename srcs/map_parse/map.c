/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:52:02 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/23 12:21:15 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
