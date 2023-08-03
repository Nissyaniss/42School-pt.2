/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:22:02 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/31 19:24:51 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int		file;
	int		read_state;
	char	buff;

	if (argc < 1)
	{
		ft_putstr(NO_FILE);
		return (0);
	}
	else if (argc > 2)
	{
		ft_putstr(TOO_MANY_ARGS);
		return (0);
	}
	file = open(argv[1], O_RDONLY);
	if (file < 0)
	{
		ft_putstr(ERROR_READ);
		return (0);
	}
	read_state = 1;
	read_state = read(file, &buff, 1);
	while (read_state != 0)
	{
		ft_putchar(buff);
		read_state = read(file, &buff, 1);
	}
}