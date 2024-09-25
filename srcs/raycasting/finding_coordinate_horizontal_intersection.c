/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_coordinate_horizontal_intersection.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:25:17 by simarcha          #+#    #+#             */
/*   Updated: 2024/09/25 20:00:29 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//if the ray is facing up

typedef struct s_grid
{
	x;
	y;
}	t_grid;

//we need thee function to know if the ray is facing up or down
//this function returns 1 if is going up, 0 if it's going down
int	ray_facing_up(t_ray *ray)
{
	if (ray->ray_from_player_y <= ray->pos_y)
		return (1);
	else
		return (0);
}

//We want to convert the position of our character (=player) that we have in 
//pixel into cubs unit.
//Given that the cubs unit are bigger than pixels, this returns an approximation
t_grid	find_coordinate_first_grid(t_ray *ray)
{
	t_grid	first_grid;
	
	if (ray_facing_up(ray) == 1)
		first_grid.y = (rounded_down(ray->pos_y / 64) * 64 - 1) / 64;
	else
		first_grid.y = (rounded_down(ray->pos_y / 64) * 64 + 64) / 64;
	first_grid.x = ray->pos_x + (ray->pos_y - first_grid.y) / tan(ray->angle);
	return (first_grid);
}

double	find_x_a(t_ray *ray)
{
	return ((double)(64 / tan(ray->angle)));
}

double	find_y_a(t_ray *ray)
{
	if (ray_facing_up(ray) == 1)
		return ((double)-64);
	return ((double)64);
}