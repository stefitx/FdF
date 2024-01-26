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

int	get_iso_x(float x, float y)
{
	int	iso_x;
	double angle = 30 * M_PI / 180;

	iso_x = (- x - y) * cos(angle);
	return(iso_x);
}

int	get_iso_y(float x, float y, float z)
{
	int	iso_y;
	double angle = 30 * M_PI / 180;

	iso_y = ( -x + y) * sin(angle) - z;
	return(iso_y);
}
