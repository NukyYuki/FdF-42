#ifndef MAP_H
# define MAP_H

void	ft_map_size(t_data *data, int file);
t_point	**ft_map_create(int width, int height);
void	ft_map_get_points(t_data *data, int fd);

#endif
