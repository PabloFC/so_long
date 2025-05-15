/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:14:28 by pafuente          #+#    #+#             */
/*   Updated: 2024/12/17 13:13:00 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_pointer;
	const unsigned char	*s2_pointer;

	s1_pointer = (const unsigned char *)s1;
	s2_pointer = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*s1_pointer != *s2_pointer)
		{
			return (*s1_pointer - *s2_pointer);
		}
		s1_pointer++;
		s2_pointer++;
		n--;
	}
	return (0);
}

// int main()
// {
//     char str1[] = "Hello";
//     char str2[] = "Hella";
//     int arr1[] = {1, 2, 3};
//     int arr2[] = {1, 2, 4};

//     printf("Strings iguales: %d\n", ft_memcmp(str1, str1, 5));
//     printf("Primer string mayor: %d\n", ft_memcmp(str1, str2, 5));
//     printf("Segundo string mayor: %d\n", ft_memcmp(str2, str1, 5));
//     printf("Arrays de int: %d\n", ft_memcmp(arr1, arr2, 3 * sizeof(int)));
//     printf("0 bytes: %d\n", ft_memcmp(str1, str2, 0));

//     return 0;
// }