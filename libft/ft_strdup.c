/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:55:23 by hamrachi          #+#    #+#             */
/*   Updated: 2024/10/10 16:07:56 by hamrachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strdup(char *s1)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof (char) * ft_strlen(s1) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
