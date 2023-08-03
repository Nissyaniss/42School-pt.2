/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 22:38:55 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/15 14:23:14 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *b;
	*b = *a;
	*a = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (i < size)
	{
		while (y < size)
		{
			if (tab[i] > tab[y])
				ft_swap(&tab[i], &tab[y]);
			y++;
		}
		y = i + 1;
		i++;
	}
}
