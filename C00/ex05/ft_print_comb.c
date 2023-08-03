/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:32:49 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/15 18:43:25 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	c2 = '1';
	c3 = '2';
	while (c1 <= '7')
	{
		c2 = '1';
		while (c2 <= '8')
		{
			c3 = '2';
			while (c3 <= '9')
			{
				if ((c1 != c2 && c1 != c3 && c2 != c3) && (c1 < c2 && c2 < c3))
					ft_print(c1, c2, c3);
				c3++;
			}
			c2++;
		}
		c1++;
	}
}
