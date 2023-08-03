/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:00:55 by yalasbor          #+#    #+#             */
/*   Updated: 2023/08/01 13:43:31 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src, int pos1, int pos2)
{
	int		size;
	int		i;
	char	*result;

	i = 0;
	size = pos2 - pos1;
	result = malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	while (pos1 < pos2)
	{
		result[i] = src[pos1];
		i++;
		pos1++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_is_from_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_splits(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_is_from_charset(str[i], charset) && str[i])
			i++;
		if (str[i])
			count++;
		while (!(ft_is_from_charset(str[i], charset)) && str[i])
			i++;
	}
	return (count);
}

char	**ft_cut(char **result, char *charset, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (ft_is_from_charset(str[i], charset) && str[i])
			i++;
		k = i;
		while (!(ft_is_from_charset(str[i], charset)) && str[i])
			i++;
		if (str[i] || j != ft_count_splits(str, charset))
		{
			result[j] = ft_strdup(str, k, i);
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;

	i = 0;
	if (charset == NULL)
	{
		result = malloc(2 * sizeof(char));
		while (str[i])
			i++;
		result[0] = ft_strdup(str, 0, i);
		result[1] = NULL;
		return (result);
	}
	if (str == NULL)
	{
		result = malloc(1 * sizeof(char));
		result[0] = NULL;
		return (result);
	}
	result = malloc((ft_count_splits(str, charset) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = ft_cut(result, charset, str);
	return (result);
}
