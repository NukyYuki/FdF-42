#ifndef	STRUCTS_H
# define STRUCTS_H

typedef struct	s_screen_coordinate
{
	int	x;
	int	y;
}		t_coordinate;

typedef enum	e_projection
{
	ISO,
	ORTO
}		t_projection;

typedef struct s_line
{
	int	x0;
	int y0;
	int x1;
	int y1;
	int	color_start;
	int	color_end;
	int color;
}		t_line;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct	s_map
{
	t_point	**map_points;
	int		map_x;
	int		map_y;
	int		max_x;
	int		min_x;
	int		max_y;
	int		min_y;
	int		max_z;
	int		min_z;
	int		map_center_x;
	int		map_center_y;
}			t_map;

typedef struct s_view
{
	int		x_offset;
	int		y_offset;
	int		zoom;
	float 	angle_x;
	float	angle_y;
	float	angle_z;
	float	height_scale;
}			t_view;

typedef struct	s_data
{
	void			*mlx;
	void			*mlx_win;
	int				win_height;
	int				win_width;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
	t_map			*map;
	t_view			view;
	t_projection	projection;
}			t_data;

#endif
