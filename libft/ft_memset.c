/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:11:56 by pafuente          #+#    #+#             */
/*   Updated: 2024/12/23 13:03:54 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pointer;

	pointer = s;
	while (n > 0)
	{
		*pointer = c;
		pointer++;
		n--;
	}
	return (s);
}

// int main()
// {
//     char *str;

//     str = strdup("hello");
//     ft_memset(str, 'a', 3);
//     printf("%s\n", str);
// }