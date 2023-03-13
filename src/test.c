#include <mlx.h>
#include <math.h>

#define WIN_WIDTH 640
#define WIN_HEIGHT 480

#define FOV_ANGLE 60 * (M_PI / 180)
#define RAY_ANGLE_INC FOV_ANGLE / WIN_WIDTH
#define DIST_PROJ_PLANE (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2)

typedef struct s_ray
{
    float angle;
    float distance;
}              t_ray;

void cast_rays(t_ray *rays, float player_angle, int num_rays, int wall_height)
{
    float ray_angle = player_angle - (FOV_ANGLE / 2);
    int i;

    for (i = 0; i < num_rays; i++)
    {
        rays[i].angle = ray_angle;
        ray_angle += RAY_ANGLE_INC;

        // perform raycasting logic here, calculating distance to walls

        rays[i].distance = 50 + (i * 5);
    }
}

void render_walls(t_ray *rays, int num_rays, void *mlx, void *win)
{
    int i;
    int wall_strip_height;
    float dist_to_proj_plane;
    int wall_top, wall_bottom;

    for (i = 0; i < num_rays; i++)
    {
        dist_to_proj_plane = (DIST_PROJ_PLANE / rays[i].distance);
        wall_strip_height = (WIN_HEIGHT * dist_to_proj_plane);
        wall_top = (WIN_HEIGHT / 2) - (wall_strip_height / 2);
        wall_bottom = wall_top + wall_strip_height;

        // render wall strip to screen
        mlx_string_put(mlx, win, i, wall_top, 0xFFFFFF, "X");
    }
}

int main()
{
    void *mlx;
    void *win;
    int num_rays = WIN_WIDTH;
    t_ray rays[num_rays];
    float player_angle = 0;
    int wall_height = WIN_HEIGHT;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Raycasting");

    while (1)
    {
        // perform raycasting
        cast_rays(rays, player_angle, num_rays, wall_height);

        // render walls
        render_walls(rays, num_rays, mlx, win);

        mlx_do_sync(mlx);
    }

    mlx_loop(mlx);
    return 0;
}
