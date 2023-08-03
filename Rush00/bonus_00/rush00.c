/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:40:17 by lbouet            #+#    #+#             */
/*   Updated: 2023/07/16 18:58:53 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);

void	ft_fl_ll(int x)
{
	int	i;

	i = 0;
	ft_putchar('o');
	if (x >= 2)
	{
		if (x > 2)
			while (i++ < x - 2)
				ft_putchar('-');
		ft_putchar('o');
	}
}

void	ft_middle(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < y - 2)
	{
		if (j < x)
		{
			ft_putchar('\n');
			ft_putchar('|');
			while (j < x - 2)
			{
				ft_putchar(' ');
				j++;
			}
			ft_putchar('|');
		}
		i++;
		j = 0;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		ft_putstr("Error : No negative, null or more than \
INT_MAX numbers are accepted !\n");
		return ;
	}
	ft_fl_ll(x);
	ft_middle(x, y);
	ft_putchar('\n');
	if (y != 1)
	{
		ft_fl_ll(x);
		ft_putchar('\n');
	}
}
