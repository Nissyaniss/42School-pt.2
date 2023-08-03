/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:48:09 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/17 17:43:11 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_capitalize_word(char *str, int pos)
{
	int	i;

	i = 1;
	if (str[pos] >= 'a' && str[pos] <= 'z')
		str[pos] -= 32;
	while (str[pos + i])
	{
		if ((str[pos + i] >= '0' && str[pos + i] <= '9') || \
		(str[pos + i] >= 'a' && str[pos + i] <= 'z'))
			i++;
		if (str[pos + i] >= 'A' && str[pos + i] <= 'Z')
			str[pos + i] += 32;
		if (!((str[pos + i] >= '0' && str[pos + i] <= '9') || \
		(str[pos + i] >= 'a' && str[pos + i] <= 'z')))
			return (pos + i - 1);
		i++;
	}
	return (pos + i - 1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || \
		(str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			i = ft_str_capitalize_word(str, i);
		i++;
	}
	return (str);
}
