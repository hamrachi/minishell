/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:26:56 by yojablao          #+#    #+#             */
/*   Updated: 2024/10/31 14:26:58 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd_builting(t_env *l)
{
	char	buffer[1024];
	char	*path;

	path = getcwd(buffer, sizeof(buffer));
	if (path == NULL)
		path = extract_value(l, "PWD");
	get_exit(0, 0);
	printf("%s\n", path);
}
