/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:10:21 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/23 17:10:34 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib/minilibx-linux/mlx.h"
# include <X11/X.h>
# include "lib/libft/libft.h"
# include "lib/GNL/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stddef.h>
# include <math.h>
# include <fcntl.h>
# include <limits.h>

// Custom headers
# include "includes/structs.h"
# include "includes/window.h"
# include "includes/map.h"
# include "includes/draw.h"
# include "includes/view.h"
# include "includes/input.h"

void	ft_free_data_struct(t_data *data);
int		close_x(t_data *data);
void	free_char_arr(char **arr);

#endif 
