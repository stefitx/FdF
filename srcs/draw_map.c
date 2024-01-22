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

// int	rendering(t_data img)

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void fill_image_with_color(t_data *img, float x, float y, float z)
{
	int iso_y;
	int iso_x;

	iso_y = get_iso_y(x, y, z);
	iso_x = get_iso_x(x, y);
	if (400 + iso_x < 800 && 300 + iso_y < 600)
		my_mlx_pixel_put(img, 400 + iso_x, 300 + iso_y, 0xF8C8DC);
}

void draw_map(void *mlx, void *win, t_map *map)
{
    t_data img;
    int	i;

    img.img = mlx_new_image(mlx, 800, 600);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    i = 0;
    while (i < map->size)
    {
    	fill_image_with_color(&img, map->coord_array[i].x, map->coord_array[i].y, map->coord_array[i].z);
    	i++;
    }
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);
}

// void	draw_map(void	*mlx, void	*win, t_map *map)
// {
// 		t_data	img;
// 		int	i;

// 		img.img = mlx_new_image(mlx, 800, 600);

// 		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 		i = 0;
// 		while (i < map->size)
// 		{
// 			if (400+ (get_iso_x((float)newcoord.x, (float)newcoord.z) < 800) && 300 +(get_iso_y((float)newcoord.x, (float)newcoord.y, (float)newcoord.z)) < 600)
// 				my_mlx_pixel_put(&img, get_iso_x((float)newcoord.x, (float)newcoord.z), get_iso_y((float)newcoord.x, (float)newcoord.y, (float)newcoord.z), 0xffffff);
// 			i++;
// 		}
// 		mlx_put_image_to_window(mlx, win, img.img, 0, 0);
// }
