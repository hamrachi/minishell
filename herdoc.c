/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 03:49:33 by yojablao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/05 15:52:37 by hamrachi         ###   ########.fr       */
=======
/*   Updated: 2024/10/05 13:32:50 by yojablao         ###   ########.fr       */
>>>>>>> b7ccea5b59f66c470b577b18563440636c556427
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void free2d(char **s)
{
    int i = -1;
    while(s[++i] != NULL)
        free(s[i]);
}
char *check_expand(char *line,char **env)
{
    char *expanded;
    char *fullline;

    int flage = 0;
    int i = 0;
    fullline = NULL;
    char **words = f_split(line,' ');
    while (words[i])
    {
        if(words[i][0] == '$')
        {
            flage = 1;
            expanded = expand(words[i],env);
            if(!expanded)
                exit(11);
            fullline =  f_strjoin(fullline,expanded);
        }
        else
            fullline =  f_strjoin(fullline,words[i]);
        fullline =  f_strjoin(fullline," ");
        i++;
    }
    if(flage == 1 && fullline)
        return(fullline);
    else
        return(fullline);
}
static char *read_it(const char *del,int *f,char **env,bool flage)
{
    (void)env;
    (void)flage;
    char    *fullline;
    char    *tmp;
    char    *line;
    int     fd;
    (void)flage;
    (void)env;

    fullline = NULL;
    fd = open("/tmp/lo.txt",O_CREAT | O_RDWR | O_TRUNC  ,0644);
    *f =fd;
    while(1)
    {
        line = readline("\033[95m heredoc> \033[0m");
        if(!line)
            break;
        if(ft_strcmp(line ,(char *)del) == 0)
        {
            free (line);
            break;
<<<<<<< HEAD
        // if(flage == true)
        //     line = check_expand(line,env);
        tmp = line;
        tmp =  f_strjoin(line,"\n");
        free(line);
        // tmp = fullline;/
=======
        }
        if(flage == true)
            line = check_expand(line,env);
        tmp = line;
        tmp =  f_strjoin(line,"\n");
        free(line);
>>>>>>> b7ccea5b59f66c470b577b18563440636c556427
        fullline =  f_strjoin(fullline,tmp);
    }
   
    return(fullline);
}
int    ft_herdoc(char *del,char **env)
{
    (void)env;
    char *fullline;
    int fd;
    int flage;
    int i;

    if(del[0] == '\"')
    {
        flage = false;
        del++;
        i = ft_strlen(del) ;
        del[i- 1] = '\0';
    }
    else if(del[0] == '\'')
    {
        flage = false;
        del++;
        i = ft_strlen(del) ;
        del[i- 1] = '\0';
    }
    else
        flage = true;
    fullline = read_it(del,&fd,env,flage);
    if (fullline)
    {
        if(fullline == NULL)
            exit(1);
        if (write(fd, fullline, ft_strlen(fullline)) == -1)
            return(perror("Error writing to file"),close(fd), -1);
<<<<<<< HEAD
        // free(fullline);
=======
>>>>>>> b7ccea5b59f66c470b577b18563440636c556427
    }
    else
        return (close(fd),-1);
    close(fd);
    fd = open("/tmp/lo.txt", O_RDONLY);
    if (fd == -1)
        return (perror("Error reopening heredoc file for reading"),-1);
    return fd; 
}
