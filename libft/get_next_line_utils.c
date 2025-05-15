/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:22:32 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/15 12:08:25 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_memcpy is designed to copy n bytes of data
// from a source memory location src to a destination memory location dest

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char *ptr_dest;
	char *ptr_src;
	size_t i;

	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}
