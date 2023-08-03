/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:48:06 by hsolet            #+#    #+#             */
/*   Updated: 2023/08/02 20:37:45 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_verif_obstacle(int *coord_square, t_map_info size_square, \
t_coordinates *result)
{
	int				i;
	int				nb_obstacle;

	i = 0;
	nb_obstacle = 0;
	while (result[i].x != -1 && result[i].y != -1)
	{
		if (coord_square[2] + 1 > size_square.col_number || \
			coord_square[3] + 1 > size_square.line_number)
			return (1);
		if ((result[i].x > coord_square[0] \
		&& result[i].x < coord_square[2] + 1) \
		&& (result[i].y > coord_square[1] && result[i].y < coord_square[3] + 1))
		{
			i++;
			nb_obstacle++;
		}
		i++;
	}
	return (nb_obstacle);
}

t_square	ft_create_square(int *coord_square, t_map_info size_square, \
int *size_up, t_coordinates *result)
{
	t_square	square;

	if (ft_verif_obstacle(coord_square, size_square, result) == 0)
	{
		*size_up = *size_up + 1;
		coord_square[2] = coord_square[0] + *size_up;
		coord_square[3] = coord_square[1] + *size_up;
		square.x = coord_square[0];
		square.x2 = coord_square[2];
		square.y = coord_square[1];
		square.y2 = coord_square[3];
	}
	if (ft_verif_obstacle(coord_square, size_square, result) != 0)
	{
		coord_square[0]++;
	}
	return (square);
}
//coord_square[0] = x
//coord_square[1] = y
//coord_square[2] = x2
//coord_square[3] = y2

t_square	ft_square_solving(t_map_info size_square, char *path)
{
	int				size_up;
	int				coord_square[4];
	t_square		square;
	t_coordinates	*result;

	result = ft_parsing(path);
	size_up = 0;
	coord_square[0] = 0;
	coord_square[2] = coord_square[0] + size_up;
	coord_square[1] = 0;
	coord_square[3] = coord_square[1] + size_up;
	while (coord_square[3] < size_square.line_number - 1)
	{
		while (coord_square[2] < size_square.col_number - 1)
		{
			square = ft_create_square(coord_square, \
			size_square, &size_up, result);
		}
		coord_square[1]++;
		coord_square[2] = 0;
	}
	(void) size_square;
	return (square);
}
