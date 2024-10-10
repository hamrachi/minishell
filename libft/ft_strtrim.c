/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:36:16 by hamrachi          #+#    #+#             */
/*   Updated: 2024/10/10 16:09:56 by hamrachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char  *s1, char  *set)
{
	char	*end;
	char	*result;
	size_t	s;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	end = (char *)s1 + ft_strlen(s1) - 1;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (end >= s1 && ft_strchr(set, *end))
		end--;
	end += 1;
	s = ft_strlen(s1) - ft_strlen(end);
	result = (char *)malloc(s + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < s)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
