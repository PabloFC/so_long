/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:45:53 by pafuente          #+#    #+#             */
/*   Updated: 2024/12/22 11:12:37 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	first;
	size_t	last;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1);
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	while (last > first && ft_strchr(set, s1[last - 1]))
		last--;
	trimmed = ft_substr(s1, first, last - first);
	return (trimmed);
}

// int main()
// {
//     char *s1 = "  Hello, World!  ";
//     char *set = " ";
//     char *result;

//     result = ft_strtrim(s1, set);
//     if (result)
//     {
//         printf("Original string: '%s'\n", s1);
//         printf("Trimmed string: '%s'\n", result);
//         free(result);
//     }
//     else
//     {
//         printf("ft_strtrim returned NULL\n");
//     }

//     s1 = "";
//     result = ft_strtrim(s1, set);
//     if (result)
//     {
//         printf("Original string: '%s'\n", s1);
//         printf("Trimmed string: '%s'\n", result);
//         free(result);
//     }
//     else
//     {
//         printf("ft_strtrim returned NULL\n");
//     }

//     s1 = "...Hello, World!...";
//     set = ".!";
//     result = ft_strtrim(s1, set);
//     if (result)
//     {
//         printf("Original string: '%s'\n", s1);
//         printf("Trimmed string: '%s'\n", result);
//         free(result);
//     }
//     else
//     {
//         printf("ft_strtrim returned NULL\n");
//     }

//     return 0;
// }