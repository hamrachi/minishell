/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:17:28 by hamrachi          #+#    #+#             */
/*   Updated: 2024/10/10 16:08:14 by hamrachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	lens;
	size_t	lend;

	if ((!dst && !src) || !dstsize)
		return (ft_strlen(src));
	lens = ft_strlen(src);
	lend = ft_strlen(dst);
	if (dstsize <= lend)
		return (dstsize + lens);
	i = 0;
	while (src[i] && i < (dstsize - lend - 1))
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	return (lend + lens);
}
