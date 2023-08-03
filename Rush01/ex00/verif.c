/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 06:26:07 by yroussea          #+#    #+#             */
/*   Updated: 2023/07/23 14:18:18 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_left_to_right(int *input, int **tab, int depth)
{
	int	correct_views;
	int	views;
	int	height_max;
	int	i;
	int	k;

	correct_views = input[depth / 4 + 8];
	views = 0;
	height_max = 0;
	i = -1;
	while (++i <= 3)
	{
		if (tab[depth / 4][i] > height_max)
		{
			height_max = tab[depth / 4][i];
			views++;
		}
		k = i;
		while (++k <= 3)
			if (tab[depth / 4][i] == tab[depth / 4][k]
					&& tab[depth / 4][k] != 0)
				return (0);
	}
	return (views == correct_views);
}

int	ft_check_right_to_left(int *input, int **tab, int depth)
{
	int	correct_views;
	int	views;
	int	height_max;
	int	i;
	int	k;

	correct_views = input[(depth / 4) + 12];
	views = 0;
	height_max = 0;
	i = 4;
	while (--i >= 0)
	{
		if (tab[depth / 4][i] > height_max)
		{
			height_max = tab[depth / 4][i];
			views++;
		}
		k = i;
		while (--k >= 0)
			if (tab[depth / 4][i] == tab[depth / 4][k]
					&& tab[depth / 4][k] != 0)
				return (0);
	}
	return (views == correct_views);
}

int	ft_check_up_to_down(int *input, int **tab, int depth)
{
	int	correct_views;
	int	views;
	int	height_max;
	int	i;
	int	k;

	correct_views = input[depth % 4];
	views = 0;
	height_max = 0;
	i = -1;
	while (++i <= 3)
	{
		if (tab[i][depth % 4] > height_max)
		{
			height_max = tab[i][depth % 4];
			views++;
		}
		k = i;
		while (++k <= 3)
			if (tab[i][depth % 4] == tab[k][depth % 4]
					&& tab[k][depth % 4] != 0)
				return (0);
	}
	return (views == correct_views);
}

int	ft_check_down_to_up(int *input, int **tab, int depth)
{
	int	correct_views;
	int	views;
	int	height_max;
	int	i;
	int	k;

	correct_views = input[(depth % 4) + 4];
	views = 0;
	height_max = 0;
	i = 4;
	while (--i >= 0)
	{
		if (tab[i][depth % 4] > height_max)
		{
			height_max = tab[i][depth % 4];
			views++;
		}
		k = i;
		while (--k >= 0)
			if (tab[i][depth % 4] == tab[k][depth % 4]
					&& tab[k][depth % 4] != 0)
				return (0);
	}
	return (views == correct_views);
}

int	ft_check(int *input, int **tab, int depth)
{
	if (depth >= 12 && (ft_check_down_to_up(input, tab, depth) == 0
			|| ft_check_up_to_down(input, tab, depth) == 0))
		return (0);
	if ((depth + 1) % 4 == 0
		&& (ft_check_right_to_left(input, tab, depth) == 0
			|| ft_check_left_to_right(input, tab, depth) == 0))
		return (0);
	return (1);
}
