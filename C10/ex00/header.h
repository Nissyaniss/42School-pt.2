/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:04:38 by yalasbor          #+#    #+#             */
/*   Updated: 2023/07/31 18:15:22 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <fcntl.h>

# define NO_FILE "File name missing.\n"
# define TOO_MANY_ARGS "Too many arguments.\n"
# define ERROR_READ "Cannot read the file.\n"

void	ft_putstr(char *str);
void	ft_putchar(char c);

#endif