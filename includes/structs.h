#ifndef	STRUCTS_H
# define STRUCTS_H

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
}			t_data;

#endif
