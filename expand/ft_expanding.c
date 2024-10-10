/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expanding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:12:57 by hamrachi          #+#    #+#             */
/*   Updated: 2024/10/10 17:20:18 by hamrachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    skip_value(char *str, size_t *i)
{
    while(str[*i])
    {
        if (str[*i] == 34 || str[*i] == 39)
            break;
        (*i)++;
    }
    (*i)--;
}
size_t  skip_value2(char *str, size_t *i)
{
    size_t  len;
    len = 0;
    while(str[*i])
    {
        if (str[*i] == 34 || str[*i] == 39)
            break;
        len++;
        (*i)++;
    }
    (*i)--;
    //len--;
    return(len);
}

int ft_word_counter(char    *str)
{
    size_t i;
    size_t w;

    i = 0;
    w = 0;
    while (str[i])
    {
        if (str[i] == 34 || str[i] == 39)
        {
            skip_betw_quotes(str, &i);
            w++;
        }
        else
        {
            skip_value(str,&i);
            w++;
        }
        i++;
    }
    return (w);
}
char	*f_substr(char *s, size_t start, size_t len)
{
	char		*new;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	new = master(len + 1,1);
	if (!new)
		return (NULL);
	while (i < len)
		new[i++] = s[start++];
	new[i] = '\0';
    //printf("subster == %s\n",new);
	return (new);
}

char    *ft_range(char *str, size_t *i, size_t start, size_t flag)
{
    size_t len;
    
    len = 0;
    if (flag == 0)
        len = skip_betw_quotes3(str, i);
    else
        len = skip_value2(str, i);
    return(f_substr(str, start, len));
}

char    **ft_expanding_split(char *str)
{
    char **result;
    int wc = ft_word_counter(str);
    printf("wc = %d\n",wc);
    size_t i;
    size_t start;
    size_t j;

    result = (char **)f_calloc(wc + 1, sizeof(char *));
    i = 0;
    start = 0;
    j = 0;
    while(str[i])
    {
        if (str[i] == 34 || str[i] == 39)
        {
            start = i;
            result[j]= ft_range(str, &i, start, 0);
        }
        else
        {
            start = i;
            result[j] = ft_range(str, &i, start, 1);
        }
        i++;
        j++;
    }
    result[j] = NULL;
    return(result);
}

int     ft_check_exist_charracter(char *s)
{
    int i = 0;
    int v = 0;
    int c = 0;

    while (s[i])
    {
        if (s[i] == 34 || s[i] == 39)
            v = 1;
        if (s[i] == '$')
            c = 1;
        if (v == 1 && c == 1) // $ and quotes exist
            return (3);
        i++;
    }
    if (v == 0 && c == 1) //just $
        return (1);
    else if(v == 1 && c == 0) //just quotes
        return (2);
    else // no $ no quotes
        return (0);
    
}

size_t ft_bring_index(char *s, char c)
{
    size_t i;

    i = 0;
    while(s[i])
    {
        if (s[i] == c)
            return(i);
        i++;
    }
    return(0);
}

int ft_check_next_charachter(char *s, size_t start, size_t len)
{
    while (s[start])
    {
        if (start > len)
            {
                if(ft_isalnum(s[start]) == 1)
                    return(1);
                else
                    return (0);
            }
        start++;
    }
    return(0);
}
size_t	ft_str_lencmp(char *s1, char *s2, size_t i)
{
    size_t j;
    j = 0;
    i++;
    printf("i strlencmp %zu\n",i);
	while (s1[i] && s2[j])
	{
        
        if (s1[i] - s2[j] == 0 && s2[j + 1] == '\0')
        {
            return(j);
        }
        i++;
        j++;
    }
    return(0);
}
bool	special_letter(char l)
{
	char	*s;
	int		i;

	i = 0;
	s = "$=/*-+\"\'@!#%^.*:";
	if (l == ' ' || (l >= 9 && l <= 13))
		return (true);
	while (s[i])
	{
		if (s[i] == l)
			return (true);
		i++;
	}
	return (false);
}
char	*ft_strrange(char *s, int start, int end)
{
	int		i;
	char	*str;

	str = f_calloc(1,end - start + 1);
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	return (str);
}
char	*get_key(char *s)
{
    int start;
    int end;
	int			i;
	char		*str;

	i = 0;
    start = 0;
    end = 0;
	while (s[i])
	{
		if (s[i] == '$')
		{
			start = i++;
			while (s[i] && !special_letter(s[i]))
				i++;
			end = i;
			break ;
		}
		i++;
	}
	str = ft_strrange(s, start, end);
	return (str);
}
char    *ft_bring_key(char *s1, t_env *env)
{
    //char    *new;
    size_t start;
    size_t end;
    //size_t v;
    t_env *tmp;

    tmp = env;
    //printf("tmp - > key is %s\n",s2);
    start = ft_bring_index(s1, '$');
    printf("start == %zu\n",start);
    //char *key = get_key(s1);
    while(tmp)
    {
        if (ft_str_lencmp(s1, tmp->key, start)+1 == ft_strlen(tmp->key))
        {
            end = ft_strlen(tmp->key);
            if (ft_check_next_charachter(s1, start, end) == 0)
                return (tmp->value);
        }
        // if (ft_strcmp(key + 1, tmp->key) == 0)
        // {
        //     end = ft_strlen(tmp->key);
        //     printf("key{%s}\n",tmp->key);
        //     printf("value{%s}\n",tmp->value);
        //     if (ft_check_next_charachter(s1, start, end) == 0)
        //         return (tmp->value);
        // }
        tmp = tmp -> next;
    }
    return(NULL);
}

char    *ft_expend_just_dollar(char *s , t_env *env)
{
    char **array;

    array = ft_expanding_split()
    char *new;
        new = ft_bring_key(s,env);
        printf("new--> %s\n",new);
    return(new);
}

void    ft_expanding(char *str,char **env)
{
    char **array;
    char *result;
    t_env *envi;
    
    result = NULL;
    envi = env_set(env);
    array = ft_expanding_split(str);
    int i = 0;
    //printf("%d\n",ft_check_exist_charracter(array[i]));
    while (array[i])
    {
        if (ft_check_exist_charracter(array[i]) == 1)
        {
            result = ft_expend_just_dollar(array[i], envi);
            //TODO KHASSNI NSPLITI 3La 7ssab ila3andi multi variables $USER$USER;
        }
        else if (ft_check_exist_charracter(array[i]) == 2)
            printf("here1\n");
        else if (ft_check_exist_charracter(array[i]) == 3)
            printf("here2\n");
        else
            result = f_strjoin(result, array[i]);
        i++;
    }
    printf("result = %s\n",result);
}
