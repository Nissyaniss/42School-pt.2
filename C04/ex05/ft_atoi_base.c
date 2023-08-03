/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:29:03 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/31 12:12:23 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_index_of(char current, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (current == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base, int base_len)
{
	int	i;
	int	result;
	int	negative;

	i = 0;
	result = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (ft_index_of(str[i], base) != -1)
	{
		result = result * base_len + ft_index_of(str[i], base);
		i++;
	}
	return (result * negative);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	i;
	int	y;

	base_len = ft_strlen(base);
	i = 0;
	y = 1;
	if (base_len <= 1)
		return (0);
	while (base[i])
	{
		while (base[y])
		{
			if (base[i] == base[y] || base[y] == '-' || base[y] == '+')
				return (0);
			y++;
		}
		i++;
		y = i + 1;
	}
	return (ft_atoi(str, base, base_len));
}
