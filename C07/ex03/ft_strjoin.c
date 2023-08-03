/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:01:26 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/31 20:12:08 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

int	ft_check(int size, char **strs, char *sep)
{
	int	i;

	i = 0;
	if (size == 0)
		return (0);
	if (strs == NULL)
		return (0);
	while (i < size)
	{
		if (strs[i] == NULL)
			return (0);
		i++;
	}
	if (sep == NULL)
		return (0);
	return (1);
}

int	ft_len_calc(char **strs, char *sep, int size)
{
	int	result;
	int	i;

	result = 0;
	result = ft_strlen(sep) * size - 1;
	i = 0;
	while (i < size)
	{
		result += ft_strlen(strs[i]);
		i++;
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;
	int		result_len;

	if (!(ft_check(size, strs, sep)))
	{
		result = malloc(sizeof(char));
		return (result);
	}
	result_len = ft_len_calc(strs, sep, size);
	result = (char *) malloc(sizeof(char) * (result_len - 2) + 1);
	result[0] = '\0';
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i + 1 != size)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
