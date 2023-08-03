/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:53:01 by yalasbor          #+#    #+#             */
/*   Updated: 2023/08/01 22:28:26 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_openfile(int *file, char *path)
{
	*file = open(path, O_RDONLY);
	if (*file < 0)
	{
		ft_putstr("[Error] - Can't open ");
		ft_putstr(path);
		ft_putstr(" !");
		exit(0);
	}
}
