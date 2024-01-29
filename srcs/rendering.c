/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:05:29 by atudor            #+#    #+#             */
/*   Updated: 2024/01/15 19:05:32 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/gnl/get_next_line.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

float	get_iso_x(float x, float y, float z)
{
	float	angx;
	float	angy;
	float	angz;
	float	temp;

	angx = (30) * M_PI / 180;
	angy = (-30) * M_PI / 180;
	angz = (30) * M_PI / 180;
	temp = y;
	y = y * cos(angx) - sin (angx) * z;
	z = temp * sin(angx) + cos(angx) * z;
	temp = x;
	x = x * cos(angy) + sin(angy) * z;
	z = -temp * sin(angy) + z * cos(angy);
	temp = x;
	x = x * cos(angz) - y * sin(angz);
	y = temp * sin(angz) + cos(angz) * y;
	return (-x);
}

float	get_iso_y(float x, float y, float z)
{
	float	angx;
	float	angy;
	float	angz;
	float	temp;

	angx = (30) * M_PI / 180;
	angy = (-30) * M_PI / 180;
	angz = (30) * M_PI / 180;
	temp = y;
	y = y * cos(angx) - sin (angx) * z;
	z = temp * sin(angx) + cos(angx) * z;
	temp = x;
	x = x * cos(angy) + sin(angy) * z;
	z = -temp * sin(angy) + z * cos(angy);
	temp = x;
	x = x * cos(angz) - y * sin(angz);
	y = temp * sin(angz) + cos(angz) * y;
	return (y);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bits / 8));
	*(unsigned int *)dst = color;
}

void	draw_map(void *mlx, void *win, t_map *map)
{
	t_data	img;

	change_to_iso(map, map->coord_array);
	scale_iso(map);
	img.img = mlx_new_image(mlx, WIDTH, LEN);
	img.addr = mlx_get_data_addr(img.img, &img.bits, &img.len, &img.endian);
	map->img = &img;
	draw_map_cont(map, &img);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
}
