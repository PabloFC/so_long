/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:06:54 by pafuente          #+#    #+#             */
/*   Updated: 2025/03/25 10:48:29 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function prints a number in hexadecimal format.
// It takes a ptr argument of type unsigned long long
// and returns the length of the printed string.

int	ft_printpointer_hex(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
	{
		len += ft_printpointer_hex(ptr / 16);
		len += ft_printpointer_hex(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			len += ft_putchar(ptr + 48);
		else
			len += ft_putchar(ptr - 10 + 'a');
	}
	return (len);
}

// This function prints a pointer in hexadecimal format
//, including the "0x" prefix.

int	ft_putpointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len = write (1, "0x", 2);
	len += ft_printpointer_hex(ptr);
	return (len);
}
