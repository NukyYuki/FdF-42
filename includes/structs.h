#ifndef	STRUCTS_H
# define STRUCTS_H

typedef struct	s_coordinate
{
	int	x;
	int	y;
}		t_coordinate;

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
}			t_map;

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	int		win_height;
	int		win_width;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	t_map	map;
}			t_data;

#endif
