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

	iso_x = (x - y) * cos(angle);
	return(iso_x);
}

int	get_iso_y(float x, float y, float z)
{
	int	iso_y;
	double angle = 30 * M_PI / 180;

	iso_y = (x + y) * sin(angle) - z;
	return(iso_y);
}


t_point rotateAroundPivot(t_point point, t_point pivot, t_point euler) {
    // Step 1: Translate the point
    t_point translatedPoint = { point.x - pivot.x, point.y - pivot.y, point.z - pivot.z };

    // Convert Euler angles from degrees to radians
    double yaw = euler.x * M_PI / 180.0;
    double pitch = euler.y * M_PI / 180.0;
    double roll = euler.z * M_PI / 180.0;

    // Step 2: Apply the rotation
    // Rotation around Z axis (Yaw)
    t_point rotatedPoint;
    rotatedPoint.x = translatedPoint.x * cos(yaw) - translatedPoint.y * sin(yaw);
    rotatedPoint.y = translatedPoint.x * sin(yaw) + translatedPoint.y * cos(yaw);
    rotatedPoint.z = translatedPoint.z;

    // Rotation around Y axis (Pitch)
    translatedPoint = rotatedPoint;
    rotatedPoint.x = translatedPoint.x * cos(pitch) + translatedPoint.z * sin(pitch);
    rotatedPoint.z = -translatedPoint.x * sin(pitch) + translatedPoint.z * cos(pitch);

    // Rotation around X axis (Roll)
    translatedPoint = rotatedPoint;
    rotatedPoint.y = translatedPoint.y * cos(roll) - translatedPoint.z * sin(roll);
    rotatedPoint.z = translatedPoint.y * sin(roll) + translatedPoint.z * cos(roll);

    rotatedPoint.x += pivot.x;
	rotatedPoint.y += pivot.y;
	rotatedPoint.z += pivot.z;
	
	return rotatedPoint;
}