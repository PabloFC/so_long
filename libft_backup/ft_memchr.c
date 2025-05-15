/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:45:22 by pafuente          #+#    #+#             */
/*   Updated: 2024/12/17 13:10:52 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*puntero;
	unsigned char	character;

	puntero = (unsigned char *)s;
	character = (unsigned char)c;
	while (n--)
	{
		if (*puntero == character)
		{
			return (puntero);
		}
		puntero++;
	}
	return ((NULL));
}
