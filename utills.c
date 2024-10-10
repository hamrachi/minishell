/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:36:08 by yojablao          #+#    #+#             */
/*   Updated: 2024/10/05 11:50:20 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


bool init_pipe_line(t_shell **cmd)
{
    char ** comond;
    int i = 0;
    comond = init_mult_cmd((*cmd)->a,(*cmd)->n_pipe);
    i = -1;
	while(comond[++i])
	{
		if(handel_comond(comond[i],&(*cmd)->cmd,(*cmd)->env->env))
		    (*cmd)->cmd->cmd = find_comond((*cmd)->cmd->args[0],(*cmd)->env->env);
        if(comond[i + 1] != NULL)
		    (*cmd)->cmd->next = aloc_comond((*cmd)->env->env,(*cmd)->head);
        else
        {
            (*cmd)->cmd->next = NULL;
           break;
        }
		if(!(*cmd)->cmd->next)
			return false;
	    (*cmd)->cmd = (*cmd)->cmd->next;
	}
	return true;
}
