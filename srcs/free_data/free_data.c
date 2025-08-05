/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:29:09 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/23 16:40:23 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	ft_free_data_struct(t_data *data)
{
	int	i;

	i = 0;
	if (data->map->map_points)
	{
		while (i < data->map->map_y)
			free(data->map->map_points[i++]);
		free(data->map->map_points);
	}
	if (data->map)
		free(data->map);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	exit(0);
}

int	close_x(t_data *data)
{
	ft_free_data_struct(data);
	return (0);
}

void	free_char_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i++]);
	}
	free(arr);
	return ;
}
