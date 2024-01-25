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

int	main	(int argc, char **argv)
{
	 void	*mlx;
	 void	*win;
	t_map	map;
	t_point *coord_array;
	//t_input input = {30, -30, 30};

	if (argc == 2)
	{
		 mlx = mlx_init();
		 win = mlx_new_window(mlx, WIDTH, LEN, "FDF");
		coord_array = NULL;
		init_map(&map,argv[1]);
		parse_map(&map, &coord_array);
		draw_map(mlx, win, &map);
		mlx_loop(mlx);
	}
	else
		perror("Usage: ./fdf map.fdf");
	return (0);
}
