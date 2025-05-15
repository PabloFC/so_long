/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:21:40 by pafuente          #+#    #+#             */
/*   Updated: 2024/12/17 13:18:15 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	if (s_len - start > len)
		s_len = len;
	else
		s_len -= start;
	len = s_len;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

// int main()
// {
//     char *result;

//     // Test 1: Normal case
//     result = ft_substr("Hello, World!", 7, 5);
//     printf("Test 1: %s (Expected: World)\n", result);
//     free(result);

//     // Test 2: Start beyond string length
//     result = ft_substr("Short", 10, 5);
//     printf("Test 2: \"%s\" (Expected: \"\")\n", result);
//     free(result);

//     // Test 3: Length greater than remaining string
//     result = ft_substr("Testing", 2, 10);
//     printf("Test 3: %s (Expected: sting)\n", result);
//     free(result);

//     // Test 4: NULL string
//     result = ft_substr(NULL, 0, 5);
//     printf("Test 4: %s (Expected: (null))\n", result);
//     return 0;
// }