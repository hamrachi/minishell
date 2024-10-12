/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expanding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:12:57 by hamrachi          #+#    #+#             */
/*   Updated: 2024/10/12 18:54:46 by hamrachi         ###   ########.fr       */
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
    //printf("wc = %d\n",wc);
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
        if (s[i] == c && s[i + 1] != c)
            return(i);
        i++;
    }
    return(0);
}

int ft_check_next_charachter(char *s, size_t start, size_t len)
{
    if (s[len] == '\0')
        return(0);
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
    if(s1[i] == '\0')
        return(0);
    //printf("i strlencmp %zu\n",i);
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
char    *ft_bring_key(char *s1, t_env *env)
{
    size_t end;
    t_env *tmp;
 
    tmp = env;
    if (s1[0] == '$' && !s1[1])
        return (f_strdup("$"));
    while(tmp)
    {
        if (ft_str_lencmp(s1, tmp->key, 0)+1 == ft_strlen(tmp->key))
        {    
            end = ft_strlen(tmp->key);
            if (ft_check_next_charachter(s1, 0, end) == 0)
            {
                if (ft_strlen(s1) > ft_strlen(tmp->key))
                    return(f_strjoin(tmp ->value, f_substr(s1, ft_strlen(tmp -> key) +1, ft_strlen(s1))));
                else
                    return (tmp->value);
            }
            else
                
                return(NULL);
        }
        tmp = tmp -> next;
    }
    return(NULL);
}

size_t ft_word_counter_by_dollar(char *str)
{
    size_t wrd;
    size_t i;

    i = 0;
    wrd = 0;
    if (str[0] != '$')
        wrd++;
    while (str[i])
    {
        if (str[i] == '$' && str[i + 1])
            wrd++;
        i++;
    }
    return(wrd);
}

char    **ft_split_by_dollar(char *s)
{
    char **result;
    size_t  wc;
    size_t start;
    size_t i;
    size_t j;

    wc = ft_word_counter_by_dollar(s);
    result = (char **)f_calloc(wc + 1, sizeof(char *));
    if (!result)
        return(NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        if (s[i] == '$')
        {
            if (s[i] == '$' && s[i + 1] == '$')
                {
                    i++;
                    start = i;
                }
            else
                start = i;
            i++;
            while (s[i] && s[i] != '$' )
                i++;
            if (s[i] == '$' && s[i + 1] == '\0')
                i++;
            result[j++] = f_substr(s, start, i - start);
        }
        else
        {
            start = i;
            while (s[i] && s[i] != '$')
                i++;
            if (s[i] == '$' && s[i + 1] == '\0')
                i++;
            result[j++] = f_substr(s, start, i - start);
        }
    }
    result[j] = NULL;
    return(result);
}

char    *ft_expend_just_dollar(char *s , t_env *env)
{
    char **array;
    char *new;

    (void)env;
    new = NULL;
    array = ft_split_by_dollar(s);
    int i = 0;
    i = 0;
    while (array[i])
    {
        printf("array = %s\n", array[i]);
        i++;
    }
    i = 0;
    while(array[i])
    {
        if (ft_check_exist_charracter(array[i]) == 0)
           { 
            new = f_strjoin(new,array[i]);
                //printf("new1--> %s\n",new);
           }
        else
        {
                new = f_strjoin(new, ft_bring_key(array[i], env));
        }
        i++;
    }
    //printf("new2--> %s\n",new);
    return(new);
}

char    *f_expanding_quotes(void *content)
{
    char *s = (char *)content;  // Cast content to char as it's passed as void *
    int i = 0;
    int j = 0;
    int single_q = 0;
    int double_q = 0;

    while (s[i])
    {
        if (s[i] == '\'' && !double_q)
            single_q = !single_q;
        else if (s[i] == '"' && !single_q)
            double_q = !double_q;
        else
            s[j++] = s[i];  // Copy valid characters to the current position
        i++;
    }
    s[j] = '\0';  // Null-terminate at position j // hna
    return (s);
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
    while(array[i])
    {
        printf("first parsing ;%s;\n",array[i]);
        i++;
    }
    i  =0;
    while (array[i])
    {
        if (ft_check_exist_charracter(array[i]) == 1)
        {
            result = f_strjoin(result, ft_expend_just_dollar(array[i], envi));
        }
        else if (ft_check_exist_charracter(array[i]) == 2)
            result = f_strjoin(result, array[i]);
        else if (ft_check_exist_charracter(array[i]) == 3)
            result = f_strjoin(result, ft_expend_just_dollar(array[i], envi));
        else
            result = f_strjoin(result, array[i]);
        i++;
    }
    printf("result = %s\n",result);
}
/*

char *s = "amine$userAamine-$use$sdfjk$sdf$fs$sf$sdf$sdf$sd$"
char *value;
char *r = NULL;
int i = 0;
while(s[i])
{
    if (s[i] == '$')
    {
        value = get_key(s + i);
        i + =ft_strlen(value);
        r = join(r , expnd(value)); 
    }else
    {
        start = i;
        while(s[i] && s[i] != '$')
            i++;
        if (s[i] == '$')
            i--;
        value = ft_rang(s, start, i);
        r = join(r ,value);
    }
    i++;
}
*/