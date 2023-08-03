/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:01:21 by yalasbor          #+#    #+#             */
/*   Updated: 2023/08/02 20:38:44 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_coordinates
{
	int		x;
	int		y;
}	t_coordinates;

typedef struct s_square
{
	int	x;
	int	y;
	int	x2;
	int	y2;
}	t_square;

typedef struct s_map_info
{
	int		line_number;
	int		col_number;
	char	empty;
	char	obstacle;
	char	full;
}	t_map_info;

//UTILS
void			ft_putstr(char *str);
char			*ft_str_char_cat(char *dest, char src);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
void			ft_openfile(int *file, char *path);

//PARSING
t_coordinates	*ft_parsing(char *path);
t_map_info		ft_get_info_tab(char *path);
t_map_info		ft_map_size(char *path);

//SOLVER
t_square	ft_square_solving(t_map_info size_square, char *path);

#endif
