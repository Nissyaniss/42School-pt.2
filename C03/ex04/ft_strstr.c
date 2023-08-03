/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:58:21 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/19 13:17:26 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		while (str[i + y] == to_find[y])
		{
			if (to_find[y + 1] == '\0')
				return (&str[i]);
			y++;
		}
		y = 0;
		i++;
	}
	return (0);
}
