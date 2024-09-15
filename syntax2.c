/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:15:24 by hamrachi          #+#    #+#             */
/*   Updated: 2024/09/15 21:26:05 by hamrachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	ft_full_list(t_list **a, char *s)
{
	char	**array;
	t_list	*tmp;
	int		i;

	array = ft_split(s, ' ');
	if (!array)
		exit(1);
	i = 0;
	while (array[i])
	{
		tmp = ft_lstnew(array[i]);
		printf("==> %s\n", tmp->content);
		printf("stat ==> %d\n", tmp->stat);
		if (!tmp)
			exit(1);
		ft_lstadd_back(a, tmp);
		i++;
	}
	i = 0;
	while (i < ft_counter(s, ' '))
		free(array[i++]);
	free(array);
}

void	ft_print_stack(t_list *a)
{
    t_list *tmp;

    tmp = a;
    while (tmp)
    {
       printf("content ==> %s\n", tmp->content);
       printf("stat ==> %d\n", tmp->stat);

        tmp = tmp->next;
    }
}

void	ft_free_stack(t_list *a)
{
	t_list	*tmp;
	t_list	*to_free;

	tmp = a;
	while (tmp)
	{
		to_free = tmp -> next;
		free(tmp);
		tmp = to_free;
	}
	a = NULL;
}

int	ft_check_grammer(t_list *a)
{
	t_list *tmp;

	tmp = a;
	if (tmp -> stat == PIPE || !tmp)
			return(0);
	while(tmp)
	{
		if (tmp && tmp -> stat != TEXT && !tmp -> next)
			return(0);
		if(tmp -> stat != TEXT && tmp -> stat != PIPE)
		{
			if (tmp -> next && tmp -> next -> stat != TEXT)
				return (0);
		}
		if (tmp -> stat == PIPE)
		{
			if (tmp -> next && tmp -> next -> stat == PIPE)
				return (0);
		}
		tmp = tmp -> next;
	}
	return(1);
}
