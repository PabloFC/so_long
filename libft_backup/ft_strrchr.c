/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:03:59 by pafuente          #+#    #+#             */
/*   Updated: 2024/12/22 13:06:26 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			last = s;
		}
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}

// int main()
// {
//     char str[] = "Holahola";
//     char *result = strrchr(str, 'l');
//     if (result != NULL)
//     {
//         printf("Última posición de 'l': %ld\n", result - str);
//     }
//     else
//     {
//         printf("No se encontró 'l'\n");
//     }
//     return 0;
// }