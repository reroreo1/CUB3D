#include "mlx.h"
#include <math.h>
#include <stdlib.h>
void *mlx_ptr;
void *mlx_win;

void dda_draw_line(float ax, float ay, float bx, float by)
{
	float dx;
	float dy, s;
	float i = -1;

	dx = bx - ax;
	dy = by - ay;

	if (fabs(dx) > fabs(dy))
		s = fabs(dx);
	else
		s = fabs(dy);
	while (++i < s)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, ax, ay, 0Xffffff);
		ax += dx / s;
		ay += dy / s;
	}
}
void swap(int *a, int *b)
{
	float swap = 0;

	swap = *a;
	*a = *b;
	*b = swap;
}
void bresenham_draw_line(int ax, int ay, int bx, int by)
{
	int dx;
	int dy;
	int DC;

	if (ax > bx)
	{
		swap(&ax,&bx);
		swap(&ay,&by);
	}
	dx = bx - ax;
	dy = by - ay;
	DC = 2 * dy - dx;
	// for (int i = 0; i < 100; i++)
	while (1)
	{
		printf("ax == %d ay == %d\n", ax, ay);
		if (DC < 0)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, ax, ay, 0xffffff);
			ax += 1;
			DC += 2 * dy;
			// continue;
		}
		else
		{
			mlx_pixel_put(mlx_ptr, mlx_win, ax, ay, 0xffffff);
			ax += 1;
			ay += 1;
			DC += 2 * dy - 2 * dx;
		}
		printf("ax ==%d ay ==%d\n", ax, ay);
		// if (ay == by && ax == bx)
		// 	break;
	}
	
}
// void drawline(int x0, int y0, int x1, int y1)
// {
// 	int dx, dy, p, x, y;
// 	dx = x1 - x0;
// 	dy = y1 - y0;
// 	x = x0;
// 	y = y0;
// 	p = 2 * dy - dx;
// 	while (x < x1)
// 	{
// 		if (p >= 0)
// 		{
// 			mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0xffffff);
// 			y = y + 1;
// 			p = p + 2 * dy - 2 * dx;
// 		}
// 		else
// 		{
// 			mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0xffffff);
// 			p = p + 2 * dy;
// 		}
// 		x = x + 1;
// 	}
// }

int main()
{
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1024, 1024, "hello");
	// dda_draw_line(505, 800,200,500);
	bresenham_draw_line(900, 900, 900, 241);
	// drawline(1024, 1024, 150, 241);
	mlx_loop(mlx_ptr);
}