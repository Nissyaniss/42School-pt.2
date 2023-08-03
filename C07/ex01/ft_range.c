/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:08:37 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/25 13:36:04 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	len;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	len = max - min;
	range = (int *) malloc(sizeof(int) * len);
	if (range == NULL)
		return (NULL);
	while (i < len)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
