#include "../../fdf.h"

int	ft_abs(int value)
{
	if (value >= 0)
		return (value);
	else
		return (value * -1);
}

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_height)
		*(int *)(data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8))) = color;
}
