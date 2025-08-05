/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:11:00 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/23 16:11:20 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

//		map parsing
void	ft_map_size(t_data *data, int file);
t_point	**ft_map_create(int width, int height);
void	ft_map_get_points(t_data *data, int fd);
void	ft_map_init(t_data *data, char *file);
//		centering
void	ft_center_map(t_data *data);
void	center_map_init(t_data *data, int *y, int *x);
void	center_util(t_data *data, t_coordinate *screen, t_point *map_pts);
//		utils
void	ft_free_gnl(char *map_line, char **map_points);
void	ft_get_z(t_data *data);

#endif
