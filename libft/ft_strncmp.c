/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:51:52 by pafuente          #+#    #+#             */
/*   Updated: 2024/12/20 13:52:00 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n && (s1[count] != '\0' || s2[count] != '\0'))
	{
		if (s1[count] != s2[count])
		{
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		}
		count++;
	}
	return (0);
}

// int main() {
// char s1[]="HolA";
// char s2[]="Hola";
// int resultado=ft_strncmp(s1,s2,5);
// printf("S1 es: %s\n", s1);
// printf("S2 es: %s\n", s2);
//  printf("Resultado es: %d\n", resultado);
//     return 0;
// }