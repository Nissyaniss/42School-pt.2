/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamarinc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:50:20 by mamarinc          #+#    #+#             */
/*   Updated: 2023/07/15 13:52:03 by mamarinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_all(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
		{
			if ((i == 0 && j == 0) || (i == x - 1 && j == y - 1))
				ft_putchar('A');
			else if ((i == x - 1 && j == 0) || (i == 0 && j == y - 1))
				ft_putchar('C');
			else if ((i > 0 && i < x - 1) && (j == 0 || j == y - 1))
				ft_putchar('B');
			else if ((j > 0 && j < y - 1) && (i == 0 || i == x - 1))
				ft_putchar('B');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
		i = 0;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		write(1, "Nombres positifs et superieurs a 0 seulement !\n", 47);
	else
		ft_print_all(x, y);
}
