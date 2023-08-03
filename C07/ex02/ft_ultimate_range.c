/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:36:07 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/31 20:02:54 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*number;
	int	len;
	int	i;

	i = 0;
	if (min >= max)
	{
		number = malloc(sizeof(int));
		number = NULL;
		return (0);
	}
	len = max - min;
	number = (int *) malloc(sizeof(int) * len);
	if (number == NULL)
		return (-1);
	while (i < len)
	{
		number[i] = min + i;
		i++;
	}
	*range = number;
	return (len);
}
