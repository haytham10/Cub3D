#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define TILE_SIZE 64
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define WIDTH (TILE_SIZE * MAP_WIDTH)
#define HEIGHT (TILE_SIZE * MAP_HEIGHT)

typedef struct s_map
{
    int tiles[MAP_HEIGHT][MAP_WIDTH];
} t_map;

void draw_map(t_map *map, void *mlx_ptr, void *win_ptr)
{
    int x, y, tile_color;
	t_data data;

    for (y = 0; y < MAP_HEIGHT; y++)
    {
        for (x = 0; x < MAP_WIDTH; x++)
        {
            if (map->tiles[y][x] == 1)
                tile_color = 0x00FF0000; // red
            else if (map->tiles[y][x] == 0)
                tile_color = 0x0000FF00; // green
            my_mlx_pixel_put(&data, x * TILE_SIZE, y * TILE_SIZE, tile_color);
        }
    }
}

int main()
{
	t_map map = {
   {{1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
   }
};

    void *mlx_ptr = mlx_init();
    void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Map Viewer");

    draw_map(&map, mlx_ptr, win_ptr);

    mlx_loop(mlx_ptr);
    return 0;
}
