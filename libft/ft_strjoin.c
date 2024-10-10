/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:03:10 by hamrachi          #+#    #+#             */
/*   Updated: 2024/10/10 13:56:34 by hamrachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strjoin(char *s1, char *s2)
	{
	char		*r;
	size_t		ls1;
	size_t		ls2;
	size_t		t;
	size_t		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!s1 && s2)
		return(ft_strdup(s2));
	i = 0;
	ls1 = ft_strlen(s1) + 1;
	ls2 = ft_strlen(s2);
	if (ls1 == 0 && ls2 == 0)
	{
		return (ft_strdup(""));
	}
	r = malloc((ls1 + ls2) * sizeof(char));
	if (!r)
	{
		return (NULL);
	}
	t = ft_strlcpy(r, s1, (ls1));
	t = ft_strlcat(r, s2, (ls1 + ls2));
	return (r);
}
