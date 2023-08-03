/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:56:04 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/20 15:32:44 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_puthex(unsigned char c)
{
	write(1, &"\\", 1);
	write(1, &(unsigned char){"0123456789abcdef"[c / 16]}, 1);
	write(1, &(unsigned char){"0123456789abcdef"[c % 16]}, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 31)
			ft_putchar(str[i]);
		else
			ft_puthex(str[i]);
		i++;
	}
}
