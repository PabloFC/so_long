/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:47:51 by pafuente          #+#    #+#             */
/*   Updated: 2024/12/22 11:57:46 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src_len < size - 1 && src[src_len] != '\0')
	{
		dst[src_len] = src[src_len];
		src_len++;
	}
	if (size > 0)
		dst[src_len] = '\0';
	while (src[src_len] != '\0')
		src_len++;
	return (src_len);
}
