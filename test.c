// #include "minishell.h"

// size_t	ft_strlen(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// size_t	ft_str_lencmp(char *s1, char *s2)
// {
// 	size_t	i;

//     i = 0;
// 	while (s1[i] && s2[i])
// 	{
        
//         if (s1[i] - s2[i] == 0 && s2[i + 1] == '\0')
//         {
//             return(i);
//         }
//         i++;
//     }
   
//     return(0);
// }
// int main ()
// {
//     char s1[] = "$USER";
//     char s2[] = "USER";
//     size_t r = ft_str_lencmp(s1, s2);
//     printf("%zu\n",r);
//     printf("%zu\n",ft_strlen(s2));

// }