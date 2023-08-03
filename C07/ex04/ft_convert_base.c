/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:24:58 by yalasbor          #+#    #+#             */
/*   Updated: 2023/08/01 11:09:41 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_input(char *input, char *base);
int		ft_check_base(char *base);
char	*ft_nbr_to_base(int nbr, char *base, char *str);
int		ft_malloc_len(int nbr, char *base_to);

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

int	ft_atoi_to_base(char *str, char *base, int base_len)
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
	if (ft_index_of(str[i], base) != -1)
	{
		while (str[i])
		{
			result = (result * base_len) + ft_index_of(str[i], base);
			i++;
		}
	}
	return (result * negative);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	return (ft_atoi_to_base(str, base, base_len));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		nbr_int;

	if (!(ft_check_base(base_from) && ft_check_base(base_to)
			&& ft_check_input(nbr, base_from)))
		return (NULL);
	nbr_int = ft_atoi_base(nbr, base_from);
	result = malloc(ft_malloc_len(nbr_int, base_to));
	result[0] = '\0';
	ft_nbr_to_base(nbr_int, base_to, result);
	return (result);
}
