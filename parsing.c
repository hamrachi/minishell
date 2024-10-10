/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 03:49:39 by yojablao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/05 15:41:49 by hamrachi         ###   ########.fr       */
=======
/*   Updated: 2024/10/05 13:36:23 by yojablao         ###   ########.fr       */
>>>>>>> b7ccea5b59f66c470b577b18563440636c556427
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int pipe_check(char *s)
{
    int i = 0;
    int k = 0;
    if(!s)
        return(0);
    while(s[i])
    {
        if(s[i] == '|')
            k++;
        i++;
    }
    return(k);
}


int pars(t_shell **cmd,char *input)
{
    if (!syntax(input,cmd))
		return (printf("syntax error\n"), -1);
    ft_printf_a((*cmd)->a);
	// (*cmd)->cmd = aloc_comond((*cmd)->env->env,NULL);
	if(!(*cmd)->cmd)
		return -1;
	(*cmd)->head = (*cmd)->cmd;
	(*cmd)->n_pipe = pipe_check(input);
	if((*cmd)->n_pipe > 0)
	{
        init_pipe_line(cmd);
		(*cmd)->cmd = (*cmd)->head;
		return(2);
	}
    else
    {
        comond_init(cmd);
        return(1);
    }
}

bool    handel_onecomond(char **words,t_exec_cmd **comond,char **env)
{
    char **args;  
    args = master(sizeof(char *) * (count_words(words) + 1),1);
    char *temp;
    int i = 0;
    int j = 0;

    if(!args)
        return(false);
    while(words[i] != NULL)
    {
        if(words[i][0] == '$')
        {
            if(i > 0 && pasabel(words[i-1] ))
            {
                temp = words[i];
                words[i] =  expand(words[i],env);
            }
        }
        if(!handel_redirect(&i,words,comond))
            return (false);
        else if(words[i])
        {
            if(((i >= 1 && pasabel(words[i - 1]) == true) || i == 0 ))
            {
                args[j] = words[i];
                j++;
            }
            i++;
        }
    }
    args [j]= NULL;
    (*comond)->args = args;
    (*comond)->cmd = words[0];
    return(args);
}
