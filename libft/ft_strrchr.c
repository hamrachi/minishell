/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:04:19 by hamrachi          #+#    #+#             */
/*   Updated: 2024/10/10 16:09:38 by hamrachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	n;
	int		len;

	n = (char)c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == n)
		{
			return ((char *)(s + len));
		}
		len--;
	}
	return (NULL);
}
