/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:09:38 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/23 16:10:04 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

//	drawing
int		ft_render_iso(t_data *data);
int		ft_render_orto(t_data *data);
void	draw_line(t_data *data, t_line *line);
void	draw_lineh(t_data *data, t_line *line, int dx, int dy);
void	draw_linev(t_data *data, t_line *line, int dx, int dy);
void	ft_put_pixel(t_data *data, int x, int y, int color);
int		ft_render_loop(t_data *data);

//	utils
int		ft_abs(int value);
int		ft_max(int a, int b);
void	iso_helper(t_data *data, t_point *map_pts, t_line line, int z);
void	orto_helper(t_data *data, t_point *map_pts, t_line line, int z);
void	ft_swap_line(t_line *line, int *dx, int *dy);
void	ft_percent_line(float *percent, t_line *line, int val, int id);
void	step_val(int dir, int *val, int *step, int dval);
void	xy_init_line(int *x, int *y, t_line *line);

//	color+refresh
void	set_background(t_data *data);
void	draw_background(t_data *data, int color);
int		interpolate_color(int begin, int end, float percent);
void	get_color(t_data *data, t_line *line, int z0, int z1);
float	ft_get_percent(int z, int z_min, int z_max);

#endif
