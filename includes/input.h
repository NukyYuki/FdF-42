#ifndef INPUT_H
# define INPUT_H

# define ESC	65307
# define I		105
# define O		111
# define UP		65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363
# define MINUS	45
# define PLUS	65451
# define R		114
# define S		115
# define D		100

int	ft_key_press(int keycode, t_data *data);
int	ft_close(t_data *data, int keycode);
int	ft_rendering_type(t_data *data, int keycode);
int	ft_move(t_data *data, int keycode);
int	ft_zoom(t_data *data, int keycode);
int	ft_reset(t_data *data, int keycode);
int	ft_scaling(t_data *data, int keycode);

#endif
