#ifndef VIEW_H
# define VIEW_H

void	ft_view_init(t_data *data);
void	isometric_projection(t_data *data, t_point *map_pts, int *line_x, int *line_y);
void	ortographic_projection(t_data *data, t_point *map_pts, int *line_x, int *line_y);

#endif
