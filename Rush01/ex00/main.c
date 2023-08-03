/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:00:28 by thogalla          #+#    #+#             */
/*   Updated: 2023/07/23 14:15:43 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_check(int *input, int **tab, int depth);

int	condition_error(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2)
		return (0);
	while (av[1][i])
	{
		if (!(av[1][i] >= '1' && av[1][i] <= '4') && i % 2 == 0)
			return (0);
		if (i % 2 == 1 && !(av[1][i] == 32))
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

void	ft_display(int **tab)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i <= 3)
	{
		write(1, &(char){tab[i][y] + 48}, 1);
		y++;
		if (y == 4)
		{
			write(1, "\n", 1);
			y = 0;
			i++;
		}
		else
			write(1, " ", 1);
	}
}

int	ft_tree(int *input, int **tab, int depth)
{
	int	i;
	int	solution;

	solution = 0;
	i = 0;
	if (depth == 16)
	{
		ft_display(tab);
		return (1);
	}
	while (i <= 3)
	{
		tab[depth / 4][depth % 4] = i + 1;
		if (ft_check(input, tab, depth))
		{
			solution = ft_tree(input, tab, depth + 1);
			if (solution == 1)
				return (1);
		}
		i++;
	}
	tab[depth / 4][depth % 4] = 0;
	return (0);
}

int	*ft_parse_to_tab(char *input)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * 16);
	i = 0;
	while (input[i])
	{
		if ((input[i] >= '1' && input[i] <= '4') && i % 2 == 0)
			tab[i / 2] = input[i] - 48;
		else if (i % 2 == 0)
			return (0);
		else if (input[i] != ' ')
			return (0);
		i++;
	}
	return (tab);
}

int	main(int ac, char **av)
{
	int	**tab;
	int	i;
	int	*input;

	i = -1;
	tab = malloc(sizeof(int *) * 4);
	if (tab == NULL)
		return (0);
	while (++i <= 3)
	{
		tab[i] = malloc(sizeof(int) * 4);
		if (tab[i] == NULL)
			return (0);
	}
	input = ft_parse_to_tab(av[1]);
	if (!(condition_error(ac, av) == 1
			&& ft_tree(input, tab, 0)))
		write(1, "Error\n", 6);
	i = -1;
	while (++i <= 3)
		free(tab[i]);
	free(tab);
	free(input);
}
