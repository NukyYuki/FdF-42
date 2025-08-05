/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:15:24 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/23 16:16:10 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

void	ft_view_init(t_data *data);
void	isometric_projection(t_data *data, t_point *map_pts,
			int *line_x, int *line_y);
void	ortographic_projection(t_data *data, t_point *map_pts,
			int *line_x, int *line_y);

#endif
