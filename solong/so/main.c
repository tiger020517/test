#include "./so_long.h"

int main(int argc, char **argv)
{
	void	*mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, 800, 600, WND_NAME);
	for (int i = 0; i < 100; i++)
		mlx_pixel_put(mlx_connection, mlx_window, 350 + i, 300, 0xFFFFFF); // Example pixel put
	mlx_loop(mlx_connection);
}