/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:39:30 by yalasbor          #+#    #+#             */
/*   Updated: 2023/08/02 20:24:21 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
//size_square[0] == x
//size_square[1] == y

t_map_info	ft_map_size(char *path)
{
	int				file;
	t_map_info		info;
	int				read_state;
	char			curr_char;
	t_map_info		real_info;
	int				save_col_number;

	real_info.col_number = 1;
	real_info.line_number = 1;
	info = ft_get_info_tab(path);
	if (info.empty == info.full || info.empty == info.obstacle || \
info.obstacle == info.full)
	{
		ft_putstr("Map Error : Same characters given\n");
		exit(0);
	}
	ft_openfile(&file, path);
	info = ft_get_info_tab(path);
	read_state = 1;
	while (curr_char != '\n')
		read_state = read(file, &curr_char, 1);
	read_state = read(file, &curr_char, 1);
	while (curr_char != '\n' && read_state != 0)
	{
		save_col_number++;
		read_state = read(file, &curr_char, 1);
	}
	real_info.line_number++;
	if (info.empty < 32 || info.full < 32 || info.obstacle < 32)
	{
		ft_putstr("Map Error : Not a correct character\n");
		exit(0);
	}
	read_state = read(file, &curr_char, 1);
	while (read_state != 0)
	{
		read_state = read(file, &curr_char, 1);
		if (curr_char == '\n')
		{
			real_info.line_number++;
			if (save_col_number != real_info.col_number && \
			read(file, &curr_char, 1) != 0)
			{
				ft_putstr("Map Error : Different line size\n");
				exit(0);
			}
			save_col_number = real_info.col_number;
			real_info.col_number = -1;
		}
		if (curr_char != info.empty && curr_char != info.obstacle && \
curr_char != '\n')
		{
			ft_putstr("Map Error : Not a correct character\n");
			exit(0);
		}
		real_info.col_number++;
	}
	if (real_info.line_number != info.line_number)
	{
		ft_putstr("Map Error : Line number given is not the correct one\n");
		exit(0);
	}
	return (real_info);
}
