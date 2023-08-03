/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:24:57 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/31 20:07:15 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

char	*ft_charcat(char *dest, char src)
{
	int	dest_len;

	dest_len = ft_strlen(dest) - 1;
	dest[dest_len + 1] = src;
	dest[dest_len + 2] = '\0';
	return (dest);
}

int	ft_malloc_len(int nbr, char *base_to)
{
	int	depth;
	int	base_to_len;

	base_to_len = ft_strlen(base_to);
	depth = 1;
	if (nbr != 0)
		depth += ft_malloc_len(nbr / base_to_len, base_to);
	return (depth);
}

void	ft_nbr_to_base(int nbr, char *base, char *result)
{
	int				base_len;
	unsigned int	nbr_unsigned;

	nbr_unsigned = 0;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_charcat(result, '-');
		nbr_unsigned = -nbr;
		if (nbr_unsigned < (unsigned int) base_len)
			ft_charcat(result, base[nbr_unsigned]);
	}
	if (nbr < base_len && nbr >= 0)
		ft_charcat(result, base[nbr]);
	else if (nbr < 0)
	{
		ft_nbr_to_base(nbr_unsigned / base_len, base, result);
		ft_charcat(result, base[nbr_unsigned % base_len]);
	}
	else
	{
		ft_nbr_to_base(nbr / base_len, base, result);
		ft_charcat(result, base[nbr % base_len]);
	}
}

int	ft_check_base(char *base)
{
	int	base_len;
	int	i;
	int	y;

	i = 0;
	y = i + 1;
	base_len = ft_strlen(base);
	if (base_len <= 1)
		return (0);
	while (base[i])
	{
		while (base[y])
		{
			if (base[i] == base[y] || base[y] == '-' || base[y] == '+'
				|| (base[y] >= 9 && base[y] <= 13) || base[y] == ' ')
				return (0);
			y++;
		}
		i++;
		y = i + 1;
	}
	return (1);
}

int	ft_check_input(char *input, char *base)
{
	int	i;
	int	j;
	int	input_len;
	int	base_len;

	i = -1;
	j = 0;
	input_len = ft_strlen(input);
	base_len = ft_strlen(base);
	while (input[++i])
	{
		while ((input[i] >= 9 && input[i] <= 13) || input[i] == ' '
			|| input[i] == '+' || input[i] == '-')
			i++;
		while (base[j])
		{
			if (base[j] == input[i])
				break ;
			j++;
			if (j == base_len)
				return (0);
		}
		j = 0;
	}
	return (1);
}
