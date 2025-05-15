/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_temp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:37:40 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/15 11:37:52 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_temp(char *s1, const char *s2)
{
    char	*res;
    size_t	len1;
    size_t	len2;

    if (!s1 && !s2)
        return (NULL);
    len1 = s1 ? ft_strlen(s1) : 0;
    len2 = s2 ? ft_strlen(s2) : 0;
    res = malloc(len1 + len2 + 1);
    if (!res)
        return (NULL);
    if (s1)
        ft_memcpy(res, s1, len1);
    if (s2)
        ft_memcpy(res + len1, s2, len2);
    res[len1 + len2] = '\0';
    free(s1);
    return (res);
}
