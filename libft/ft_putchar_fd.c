/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:58:26 by pafuente          #+#    #+#             */
/*   Updated: 2024/12/22 11:10:38 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main ()
// {
//     ft_putchar_fd('H', 1);
//     ft_putchar_fd('o', 1);
//     ft_putchar_fd('l', 1);
//     ft_putchar_fd('a', 1);
//     ft_putchar_fd('\n', 1);

// 	return 0;
// }