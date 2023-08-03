/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:14:02 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/18 17:51:35 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	is_printable;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] < ' '))
			is_printable = 1;
		else if (str[i] < 33)
			return (0);
	}
	return (1);
}
