#include "../../fdf.h"

void	set_background(t_data *data)
{
	int	color;

	color = 0x363445;
	draw_background(data, color);
}

void	draw_background(t_data *data, int color)
{
	int	i;
	int	pixel_res;
	int	*addr;

	i = 0;
	pixel_res = data->win_height * data->win_width;
	addr = (int *)data->addr;
	while (i < pixel_res)
		addr[i++] = color;
}
