#include <mlx.h>
#include <math.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main()
{
	double	posX = 22, posY = 12;  //x and y start position
	double dirX = -1, dirY = 0; //initial direction vector
  	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

  	double time = 0; //time of current frame
  	double oldTime = 0; //time of previous frame

	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		color;

	mlx = mlx_init();
	win = mlx_new_window(mlx, screenWidth, screenHeight, "mlx 42");
	x = 0;
	while (x < screenWidth)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
		double rayPosX = posX;
		double rayPosY = posY;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		//which box of the map we're in
		int mapX = (int)rayPosX;
		int mapY = (int)rayPosY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (rayPosX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (rayPosY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0) hit = 1;
			{
				//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
				if (side == 0) perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
				else           perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;

				//Calculate height of line to draw on screen
				int lineHeight = (int)(screenHeight / perpWallDist);

				//calculate lowest and highest pixel to fill in current stripe
				int drawStart = -lineHeight / 2 + screenHeight / 2;
				if(drawStart < 0)drawStart = 0;
				int drawEnd = lineHeight / 2 + screenHeight / 2;
				if(drawEnd >= screenHeight)drawEnd = screenHeight - 1;

				//choose wall color
				switch(worldMap[mapX][mapY])
				{
					case 1:  color = 0xFF0000; break; //red
					case 2:  color = 0x00FF00; break; //green
					case 3:  color = 0x0000FF; break; //blue
					case 4:  color = 0xFFFF00; break; //yellow
					case 5:  color = 0x00FFFF; break; //cyan
					default: color = 0xFFFFFF; break; //white
				}

				//give x and y sides different brightness
				if (side == 1) {color = color / 2;}

				//draw the pixels of the stripe as a vertical line
				y = drawStart;
				while (y < drawEnd)
				{
					mlx_pixel_put(mlx, win, x, y, color);
					y++;
				}
			}
		}
		x++;
	}
}