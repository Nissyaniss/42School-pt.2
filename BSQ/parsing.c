/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:04:04 by yalasbor          #+#    #+#             */
/*   Updated: 2023/08/02 20:02:46 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_obstacle_pos_struct(t_coordinates *result, int obstacle_number, \
char *path, t_map_info info)
{
	int				file;
	int				read_state;
	char			current_char;
	int				x;
	int				y;
	int				i;

	file = 0;
	read_state = 1;
	current_char = 0;
	x = 0;
	y = 0;
	i = 0;
	ft_openfile(&file, path);
	while (current_char != '\n' && read_state != 0)
		read_state = read(file, &current_char, 1);
	while (read_state != 0 && i < obstacle_number)
	{
		read_state = read(file, &current_char, 1);
		if (current_char == '\n')
		{
			x = 0;
			y++;
		}
		if (current_char == info.obstacle)
		{
			result[i].x = x;
			result[i].y = y;
			i++;
		}
		x++;
	}
	result[i].x = -1;
	result[i].y = -1;
}

int	ft_obstacle_counter(char *path, t_map_info info)
{
	int				file;
	int				read_state;
	char			current_char;
	int				i;

	file = 0;
	read_state = 1;
	current_char = 0;
	i = 0;
	ft_openfile(&file, path);
	while (current_char != '\n' && read_state != 0)
		read_state = read(file, &current_char, 1);
	read_state = read(file, &current_char, 1);
	while (read_state != 0)
	{
		read_state = read(file, &current_char, 1);
		if (current_char == info.obstacle)
			i++;
	}
	return (i);
}

t_map_info	ft_get_info_tab(char *path)
{
	int				file;
	char			current_char;
	char			*number_of_line;
	t_map_info		result;

	result.empty = 0;
	result.obstacle = 0;
	result.full = 0;
	result.col_number = 0;
	result.line_number = 0;
	number_of_line = malloc(5 * sizeof(char));
	number_of_line[0] = 0;
	current_char = 0;
	file = 0;
	ft_openfile(&file, path);
	read(file, &current_char, 1);
	if (!(current_char >= '0' && current_char <= '9'))
	{
		ft_putstr("Map Error : First char is not a number");
		exit(0);
	}
	while (current_char >= '0' && current_char <= '9')
	{
		ft_str_char_cat(number_of_line, current_char);
		read(file, &current_char, 1);
	}
	result.line_number = ft_atoi(number_of_line);
	result.empty = current_char;
	read(file, &current_char, 1);
	result.obstacle = current_char;
	read(file, &current_char, 1);
	result.full = current_char;
	free(number_of_line);
	close(file);
	return (result);
}

t_coordinates	*ft_parsing(char *path)
{
	int				obstacle_number;
	t_coordinates	*result;
	t_map_info		info;

	info = ft_get_info_tab(path);
	obstacle_number = ft_obstacle_counter(path, info);
	result = malloc(sizeof(t_coordinates) * (obstacle_number + 1));
	ft_obstacle_pos_struct(result, obstacle_number, path, info);
	return (result);
}
