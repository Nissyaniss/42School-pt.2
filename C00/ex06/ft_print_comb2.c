/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:32:49 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/15 18:44:09 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = 1;
	while (nb1 != 99)
	{
		write(1, &(char){nb1 / 10 + 48}, 1);
		write(1, &(char){nb1 % 10 + 48}, 1);
		write(1, " ", 1);
		write(1, &(char){nb2 / 10 + 48}, 1);
		write(1, &(char){nb2 % 10 + 48}, 1);
		if (nb1 != 98)
			write(1, ", ", 2);
		if (nb2 == 99)
		{
			nb1++;
			nb2 = nb1 +1;
		}
		else
			nb2++;
	}
}
