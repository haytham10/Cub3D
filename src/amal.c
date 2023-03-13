#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

int map[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int block_size = 40; // size of each block in pixels
float degToRad(int a) { return a*M_PI/180.0;}
int FixAng(int a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}

typedef struct s_game {
    float	x;
    float	y;
    float	direction;
	float	pdx;
	float	pdy;
	void	*mlx_ptr;
	void	*win_ptr;
} t_game;

void draw_map(void *mlx_ptr, void *win_ptr, t_game *player) {
    int x, y;
    int width = 10 * block_size;
    int height = 10 * block_size;

    // Create a new image to draw on
    void *img_ptr = mlx_new_image(mlx_ptr, width, height);
    int *img_data = (int *)mlx_get_data_addr(img_ptr, &(int){0}, &(int){0}, &(int){0});

    // Iterate over the map and draw each block
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int block_type = map[i][j];

            // Set the color based on the block type
            int color = block_type == 1 ? 0xFFFFFF : 0x000000;

            // Calculate the position of the block on the screen
            x = j * block_size;
            y = i * block_size;

            // Draw the block
            for (int k = 0; k < block_size; k++) {
                for (int l = 0; l < block_size; l++) {
                    int index = (y + k) * width + (x + l);
                    img_data[index] = color;
                }
            }
        }
    }

    // Draw the player
    int player_size = block_size / 2;
    x = player->x * block_size + player_size / 2;
    y = player->y * block_size + player_size / 2;
    float dir_x = cos(player->direction);
    float dir_y = sin(player->direction);

    // Draw a line to indicate the direction the player is looking
    for (int i = 0; i < player_size * 2; i++) {
        int index = (y + i * dir_y) * width + (x + i * dir_x);
        img_data[index] = 0xFF0000;
    }

    // Draw a rectangle to represent the player
    for (int i = 0; i < player_size; i++) {
        for (int j = 0; j < player_size; j++) {
            int index = (y + i - player_size / 2) * width + (x + j - player_size / 2);
            img_data[index] = 0x00FF00;
        }
    }

    // Display the image on the window
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);

    // Free the image data
    mlx_destroy_image(mlx_ptr, img_ptr);
}


int	key_press(int key, t_game *player)
{
	if (key == 0) // left
	{
		player->direction += 5;
		player->direction=FixAng(player->direction);
		player->pdx=cos(degToRad(player->direction)); // player direction x
		player->pdy=-sin(degToRad(player->direction)); // player direction y
		draw_map(player->mlx_ptr, player->win_ptr, player);
	} 
	if (key == 2) // right
	{
		player->direction -= 5;
		player->direction=FixAng(player->direction);
		player->pdx=cos(degToRad(player->direction)); // player direction x
		player->pdy=-sin(degToRad(player->direction)); // player direction y
		draw_map(player->mlx_ptr, player->win_ptr, player);
	}
	if (key == 13) // up
	{
		player->x += cos(player->direction) * 0.1;
		player->y += sin(player->direction) * 0.1;
		draw_map(player->mlx_ptr, player->win_ptr, player);
	}
	if (key == 1) // down
	{
		player->x -= cos(player->direction) * 0.1;
		player->y -= sin(player->direction) * 0.1;
		draw_map(player->mlx_ptr, player->win_ptr, player);
	}
	if (key == 53)
		exit(0);
	return (0);
}

int main()
{
	t_game game;
	
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 400, 400, "Raycasting");

	game.x = 1.5;
	game.y = 1.5;
	game.direction = 0;
	game.pdx = cos(degToRad(game.direction));
	game.pdy = -sin(degToRad(game.direction));

	draw_map(game.mlx_ptr, game.win_ptr, &game);
	
	mlx_hook(game.win_ptr, 2, 0, key_press, &game);

	mlx_loop(game.mlx_ptr);
	return 0;
}
