#ifndef DRAW_H
# define DRAW_H

//	drawing
int		ft_render_iso(t_data *data);
int		ft_render_orto(t_data *data);
void	draw_line(t_data *data, t_line *line);
void	draw_lineH(t_data *data, t_line *line, int dx, int dy);
void	draw_lineV(t_data *data, t_line *line, int dx, int dy);
void	ft_put_pixel(t_data *data, int x, int y, int color);
int		ft_render_loop(t_data *data);

//	utils
int		ft_abs(int value);
int		ft_max(int a, int b);

//	color+refresh
void	set_background(t_data *data);
void	draw_background(t_data *data, int color);
int		interpolate_color(int begin, int end, float percent);
void	get_color(t_data *data, t_line *line, int z0, int z1);
float	ft_get_percent(int z, int z_min, int z_max);

#endif
