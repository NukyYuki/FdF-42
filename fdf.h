#ifndef FDF_H
# define FDF_H

# include "lib/minilibx-linux/mlx.h"
# include "lib/libft/libft.h"
# include "lib/GNL/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stddef.h>
# include <math.h>
# include <fcntl.h>

// Custom headers
# include "includes/structs.h"
# include "includes/window.h"
# include "includes/map.h"
# include "includes/draw.h"

void	ft_free_data_struct(t_data *data);
void	free_char_arr(char **arr);

#endif 
