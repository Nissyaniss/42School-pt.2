/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:28 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/25 19:27:54 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap(char **argv, int i, int y)
{
	char	*c;

	c = argv[y];
	argv[y] = argv[i];
	argv[i] = c;
}

int	main(int argc, char *argv[])
{
	int	i;
	int	y;

	i = 1;
	y = i + 1;
	while (i < argc)
	{
		while (y < argc)
		{
			if (ft_strcmp(argv[i], argv[y]) > 0)
				ft_swap(argv, i, y);
			y++;
		}
		y = i + 1;
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
