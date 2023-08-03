/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:26:53 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/25 14:28:30 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_put_base(int nbr, int base_len, char *base)
{
	int	i;

	i = 0;
	if (nbr < base_len)
		write(1, &base[nbr], 1);
	else
	{
		ft_put_base(nbr / base_len, base_len, base);
		write(1, &base[nbr % base_len], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	int	i;
	int	y;

	i = 0;
	y = i + 1;
	base_len = ft_strlen(base);
	if (base_len <= 1)
		return ;
	while (base[i])
	{
		while (base[y])
		{
			if (base[i] == base[y] || base[y] == '-' || base[y] == '+')
				return ;
			y++;
		}
		i++;
		y = i + 1;
	}
	ft_put_base(nbr, base_len, base);
}
