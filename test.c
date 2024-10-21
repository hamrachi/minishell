// char *ft_bring_key(char *s1, t_env *env)
// {
//     size_t end;
//     t_env *tmp;
//     int r;

//     tmp = env;
//     if (s1[0] == '$' && !s1[1])
//         return (f_strdup("$"));
//     if (s1[0] == '$' && ft_isdigit(s1[1]) == 1)
//         return (f_substr(s1, 2, ft_strlen(s1)));

//         while (tmp)
//         {
//             r = ft_str_lencmp(s1, tmp->key, 0);
//             if (r == -1)
//             {
//                 end = ft_strlen(tmp->key);
//                 if (ft_check_next_charachter(s1, 0, end) == 0)
//                 {
//                     if (ft_strlen(s1) > ft_strlen(tmp->key))
//                         return (f_strjoin(tmp->value, f_substr(s1, ft_strlen(tmp->key) + 1, ft_strlen(s1))));
//                     return (f_strdup(tmp->value));
//                 }
//                 else
//                     return ("");
//             }
//             else if (r > 0)
//                 return (f_substr(s1, r, ft_strlen(s1)));
//             tmp = tmp->next;
//         }
//         return (f_strdup(""));
//     }


// int main(int argc, char **argv, char **env)
// {
//     t_env *envs = env_set(env);
//     char *res = ft_bring_key("echo \"$$1$1USER$\"",envs );
//     printf("res: |%s|\n", res);

// }


// // size_t	ft_strlen(char *str)
// // {
// // 	size_t	i;

// // 	i = 0;
// // 	while (str[i])
// // 		i++;
// // 	return (i);
// // }

// // size_t	ft_str_lencmp(char *s1, char *s2)
// // {
// // 	size_t	i;

// //     i = 0;
// // 	while (s1[i] && s2[i])
// // 	{
        
// //         if (s1[i] - s2[i] == 0 && s2[i + 1] == '\0')
// //         {
// //             return(i);
// //         }
// //         i++;
// //     }
   
// //     return(0);
// // }
// // int main ()
// // {
// //     char s1[] = "$USER";
// //     char s2[] = "USER";
// //     size_t r = ft_str_lencmp(s1, s2);
// //     printf("%zu\n",r);
// //     printf("%zu\n",ft_strlen(s2));

// // }