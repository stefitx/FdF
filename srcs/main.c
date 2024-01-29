/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:18:31 by atudor            #+#    #+#             */
/*   Updated: 2024/01/14 16:18:34 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/gnl/get_next_line.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>

int	esc_hook(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_hook(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_map	map;

	if (argc == 2)
	{
		mlx = mlx_init();
		win = mlx_new_window(mlx, WIDTH, LEN, "FDF");
		init_map(&map, argv[1], mlx, win);
		parse_map(&map, &map.coord_array);
		draw_map(mlx, win, &map);
		mlx_key_hook(win, esc_hook, &map);
		mlx_hook(map.win, 17, 0, esc_hook, (&mlx));
		mlx_hook(win, 17, 0, (void *)close_hook, &map);
		mlx_loop(mlx);
	}
	else
		write(2, "Usage: ./fdf map.fdf\n", 22);
	return (0);
}
