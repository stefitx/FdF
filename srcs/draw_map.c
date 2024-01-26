/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:12:20 by atudor            #+#    #+#             */
/*   Updated: 2024/01/14 20:12:23 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/gnl/get_next_line.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_line(t_data *img, int x0, int y0, int x1, int y1, int color)
{
    int dx;
    int sx;
    int dy;
    int sy;
    int e2;
    int err;

    dx = abs(x1 - x0);
    dy = -abs(y1 - y0);
    if (x0 < x1)
        sx = 1;
    else
        sx = -1;
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
    err = dx + dy;
    while (1)
    {
        my_mlx_pixel_put(img, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void fill_image(t_data *img, t_point *coord, int i, t_map *map)
{   
    int iso_x;
    int iso_y;

    iso_x = (int)(map->offset_x + map->iso_array[i].x);
    iso_y = (int)(map->offset_y + map->iso_array[i].y);
    
    if (iso_x >= 0 && iso_x < WIDTH && iso_y >= 0 && iso_y < LEN)
    {
        my_mlx_pixel_put(img, iso_x, iso_y, coord[i].color);
    }
}

void draw_map(void *mlx, void *win, t_map *map)
{
    t_data img;
    int	i;

    change_to_iso(map, map->coord_array);
    scale_iso(map);

    img.img = mlx_new_image(mlx, WIDTH, LEN);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    i = 0;
    while (i < map->size)
    {
    	fill_image(&img, map->coord_array, i, map);
    	i++;
    }
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);
}

// void draw_map(void *mlx, void *win, t_map *map)
// {
//     t_data img;
//     int i;

//     change_to_iso(map, map->coord_array);
//     scale_iso(map);

//     img.img = mlx_new_image(mlx, WIDTH, LEN);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//     i = 0;
//     while (i < map->size)
//     {
//         int iso_x0 = (int)(map->offset_x + map->iso_array[i].x);
//         int iso_y0 = (int)(map->offset_y + map->iso_array[i].y);
//         int iso_x1 = (int)(map->offset_x + map->iso_array[i + 1].x);
//         int iso_y1 = (int)(map->offset_y + map->iso_array[i + 1].y);
//        // draw_line(&img, iso_x0, iso_y0, iso_x1, iso_y1, map->coord_array[i].color);
//     i++;
//     }

//     mlx_put_image_to_window(mlx, win, img.img, 0, 0);
// }
