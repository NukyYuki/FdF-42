/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:21:52 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/23 12:22:26 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	ft_reset(t_data *data, int keycode)
{
	if (keycode == R)
	{
		ft_view_init(data);
		ft_center_map(data);
		return (1);
	}
	return (0);
}

int	ft_scaling(t_data *data, int keycode)
{
	if (keycode == S)
	{
		data->view.height_scale += 0.2;
		return (1);
	}
	if (keycode == D && data->view.height_scale > 0.2)
	{
		data->view.height_scale -= 0.2;
		return (1);
	}
	return (0);
}

int	ft_recenter(t_data *data, int keycode)
{
	if (keycode == C)
	{
		ft_center_map(data);
		return (1);
	}
	return (0);
}
