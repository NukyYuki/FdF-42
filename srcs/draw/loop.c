#include "../../fdf.h"

int	ft_render_loop(t_data *data)
{
	if (data->projection == ISO)
		ft_render_iso(data);
	else if (data->projection == ORTO)
		ft_render_orto(data);
	return (0);
}
