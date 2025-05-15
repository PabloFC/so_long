/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:49:34 by pafuente          #+#    #+#             */
/*   Updated: 2024/12/17 13:17:29 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*pointer;

	total_size = nmemb * size;
	pointer = malloc(total_size);
	if (pointer != NULL)
	{
		ft_memset(pointer, 0, total_size);
	}
	return (pointer);
}
