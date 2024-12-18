/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:14:19 by yojablao          #+#    #+#             */
/*   Updated: 2024/11/03 12:02:49 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*env_cpy(t_env *env)
{
	t_env	*tmp;
	t_env	*new;
	t_env	*head;
	t_env	*node;

	tmp = env;
	new = NULL;
	head = NULL;
	while (tmp)
	{
		node = malloc(sizeof(t_env));
		node->key = ft_strdup(tmp->key);
		node->value = ft_strdup(tmp->value);
		node->valid = tmp->valid;
		node->flage = tmp->flage;
		node->next = NULL;
		if (!new)
			head = node;
		else
			new->next = node;
		new = node;
		tmp = tmp->next;
	}
	return (head);
}

t_env	*env_cpy_v2(t_env *env)
{
	t_env	*tmp;
	t_env	*new;
	t_env	*head;
	t_env	*node;

	tmp = env;
	new = NULL;
	head = NULL;
	while (tmp)
	{
		node = master(sizeof(t_env), 1);
		node->key = f_strdup(tmp->key);
		node->value = f_strdup(tmp->value);
		node->valid = tmp->valid;
		node->flage = tmp->flage;
		node->next = NULL;
		if (!new)
			head = node;
		else
			new->next = node;
		new = node;
		tmp = tmp->next;
	}
	return (head);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		free(env);
		env = tmp;
	}
}

void	save_env(t_environment **env)
{
	t_env	*lenv;

	lenv = env_cpy((*env)->lenv);
	master(0, 0);
	(*env)->lenv = env_cpy_v2(lenv);
	(*env)->env = join_to_env((*env)->lenv);
	free_env(lenv);
}

char	**creat_env(void)
{
	char	**env;
	char	buffer[1024];

	env = master(sizeof(char *) * 5, 1);
	env[0] = f_strdup("OLDPWD");
	env[1] = f_strdup(f_strjoin("PWD=", getcwd(buffer, sizeof(buffer))));
	env[2] = f_strdup("SHLVL=1");
	env[3] = NULL;
	return (env);
}
