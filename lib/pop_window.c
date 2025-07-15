#include "minilibx-linux/mlx.h"
#include <stdlib.h>

#define WIDTH	1920
#define	HEIGHT	1080

int main()
{
	void	*mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
		return (1);
	
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "My window");
	if (NULL == mlx_window)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return (1);
	}
	
	mlx_loop(mlx_connection);

	mlx_destroy_window(mlx_connection, mlx_window);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
}
