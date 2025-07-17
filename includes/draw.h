#ifndef DRAW_H
# define DRAW_H

void	ft_render_map(t_data *data);
void	draw_line(t_data *data, t_line *line);
void	draw_lineH();
void	draw_lineV();
int		ft_abs(int value);
int		ft_max(int a, int b);
void	line_update_right(t_line *line, t_data *data, int x , int y);
void	line_update_down(t_line *line, t_data *data, int x, int y);
void	ft_put_pixel(t_data *data, int x, int y, int color);

#endif
