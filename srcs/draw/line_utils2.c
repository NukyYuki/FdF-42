/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:32:19 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/23 15:52:15 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	step_val(int dir, int *val, int *step, int dval)
{
	if (*step >= 0)
	{
		*val += dir;
		*step -= (2 * dval);
	}
}

void	xy_init_line(int *x, int *y, t_line *line)
{
	*x = line->x0;
	*y = line->y0;
}
