/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:17:46 by atudor            #+#    #+#             */
/*   Updated: 2024/01/14 16:18:21 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/gnl/get_next_line.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

// void	add_point(t_map *map, t_point **coord_array, char *line, int i)
// {
// 	char	**split_line;
// 	char	**split_color;
// 	int	y;
// 	int	j;

// 	(void)coord_array;
// 	split_line = ft_split(line, ' ');
// 	j = 0;
// 	y = 0;
// 	while (split_line[j] != NULL && j < map->width)
// 	{
// 		map->coord_array[i].x = j;
// 		map->coord_array[i].y = y;
// 		split_color = ft_split(split_line[j], ',');
// 		if (split_color[0] != NULL && split_color[1] != NULL)
// 		{
// 			map->coord_array[i].z = (float)ft_atoi(split_color[0]);
// 			map->coord_array[i].color = ft_atoi_base(split_color[1], 16);
// 		}
// 		else
// 			map->coord_array[i].color = 0xffffff;
// 		free_matrix(split_color, 2);
// 		if (y < map->width)
// 			y++;
// 		else
// 			y = 0;
// 		j++;
// 	}
// 	// printf("\n");
// 	free_matrix(split_line, map->width);
// }

void add_point(t_map *map, t_point *coord_array, char *line, int row) {
    char **split_line = ft_split(line, ' ');
    int col = 0;

    while (split_line[col] != NULL && col < map->width) {
        int index = row * map->width + col; // Correct index calculation

        coord_array[index].x = row;
        coord_array[index].y = col;

        char **split_color = ft_split(split_line[col], ',');
        if (split_color[0] != NULL) {
            coord_array[index].z = (float)ft_atoi(split_color[0]);
        }
        if (split_color[1] != NULL) {
            coord_array[index].color = ft_atoi_base(split_color[1], 16);
        } else {
            coord_array[index].color = 0xffffff;
        }

        free_matrix(split_color, 2);
        col++;
    }

    free_matrix(split_line, map->width);
}

void	get_map_dimensions(t_map *map)
{
	char	*line;
	int	fd;

	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
	{
		write (2, "Error opening map", 17);
		exit(0);
	}
	line = get_next_line(fd);
	if (line == NULL)
		return ;
	else
	{
		map->width = count_strings(line, ' ');
		map->length = 1;
		while (line != NULL)
		{
			free(line);
			line = get_next_line(fd);
			if (line != NULL)
				map->length++;
		}
		free(line);
	}
	close(fd);
	map->size = (map->length * map->width);
}

void	parse_map(t_map *map, t_point **coord_array)
{
	int	fd;
	int	i;
	char	*line;

	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
	{
		write (2, "Error opening map", 17);
		exit(0);
	}
	get_map_dimensions(map);
	*coord_array = (t_point *)malloc(sizeof(t_point) * map->size);
	if (*coord_array == NULL)
	{
		write (2, "Error allocating array", 22);
		exit(0);
	}
	line = get_next_line(fd);
	i = 0;
	while (i < map->length && line != NULL)
	{
		add_point(map, *coord_array, line, i);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	map->coord_array = *coord_array;
	free(line);
}
