#ifndef MAP_H
# define MAP_H

void	ft_map_size(t_data *data, int file);
t_point	**ft_map_create(int width, int height);
void	ft_map_get_points(t_data *data, int fd);
void	ft_map_init(t_data *data, char *file);
void	ft_get_z(t_data *data);

void	ft_center_map(t_data *data);
void	center_map_init(t_data *data, int *y, int *x);

#endif
