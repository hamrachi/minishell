/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:55:36 by hamrachi          #+#    #+#             */
/*   Updated: 2024/10/20 21:14:32 by hamrachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_my_malloc(size_t len)
{
    char	*new;
	size_t i;

	new = master(len,1);
	if(!new)
	{
		free(new);
		exit(1);
	}
	i = 0;
	//ft_memset(new,0,len);
	while (i < len)
	{
		new[i] = '\0';
		i++;
	}
	return(new);
}

void	ft_free(t_list *a, char *s1, char *s2)
{
	ft_free_stack(a);
	free(s1);
	free(s2);
}
void	ft_free_array(char **s1)
{
	int i;

	i = 0;
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
}

void free_all(void **arr)
{
    int i = 0;

    while (arr[i])
    {
        free(arr[i]);
        arr[i] = NULL;
        i++;
    }
}

void    *master(size_t size, int flag)
{
    static void *arr[100042];
    static int i;
    void            *ptr;

    if (flag == 1)
    {
        ptr = malloc(size);
        if (!ptr)
            exit(1);
        arr[i++] = ptr;
        arr[i] = NULL;
        return (ptr);
    }
    else
    {
        i = 0;
        free_all(arr);
        return NULL;
    }
}
void	*f_calloc(size_t count, size_t size)
{
	void	*str;

	if (size > sizeof(size))
		return (NULL);
	str = master(count * size,1);
	if (!str)
		return (NULL);
	 ft_bzero (str, (count * size));
	return (str);
}
t_list	*f_lstnew(void *content)
{
	t_list	*head;
	enum status;

	head = (t_list *)master(sizeof(t_list),1);
	if (!head)
		return (NULL);
	head -> content = content;
	if (ft_strcmp(head -> content, "|") == 0)
		head -> stat = PIPE;
	else if (ft_strcmp(head -> content, "<") == 0)
		head -> stat = INP;
	else if (ft_strcmp(head -> content, ">") == 0)
		head -> stat = OUT;
	else if (ft_strcmp(head -> content, "<<") == 0)
		head -> stat = HER;
	else if (ft_strcmp(head -> content, ">>") == 0)
		head -> stat = APP;
	else
		head -> stat = TEXT;
	head -> next = NULL;
	return (head);
}