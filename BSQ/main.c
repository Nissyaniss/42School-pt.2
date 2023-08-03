/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:29:22 by yalasbor          #+#    #+#             */
/*   Updated: 2023/08/02 20:38:56 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_map_info		size_real;
	t_square		result;

	if (argc == 1)
	{
		ft_putstr("We do not handle stdin sadly.\n");
		exit(0);
	}
	size_real = ft_map_size(argv[1]);
	result = ft_square_solving(size_real, argv[1]);
	(void) result;
	return (0);
}
