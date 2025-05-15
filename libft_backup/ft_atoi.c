/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:23:02 by pafuente          #+#    #+#             */
/*   Updated: 2024/12/22 11:22:35 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// '\v'----> vertical tabulation
// '\f'----> salto de pagina

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}

// int main() {
//     const char *test_strings[] = {
//         "123",
//         "-456",
//         "  789",
//         "+42",
//         "   -1000",
//         "3.14",  
//         "42abc", 
//         "abc123" 
//     };
//     int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);
//     for (int i = 0; i < num_tests; i++) {
//         int result = ft_atoi(test_strings[i]);
//         printf("String: \"%s\" -> Integer: %d\n", test_strings[i], result);
//     }
//     return 0;
// }