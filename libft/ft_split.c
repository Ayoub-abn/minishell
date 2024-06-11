/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:11:12 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/11 16:54:32 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


// static int	count_words(const char *str, char c)
// {
// 	int	i;
// 	int	count;
// 	char quote_char;

// 	i = 0;
// 	count = 0;
// 	while (str && str[i])
// 	{
// 		while (str[i] == c && str[i])
// 			i++;
// 		if(str[i] == '"' || str[i] == '\'')
// 		{
// 			quote_char = str[i];
// 			i++;
//             while (str[i] && str[i] != quote_char)
//                 i++;
//             if (str[i] == quote_char)
//                 i++;
//             count++;
// 		}
//   		 else if (str[i])
//         {
//             count++;
//             while (str[i] != c && str[i] != quote_char && str[i])
//                 i++;
//         }
// 	}
// 	return (count);
// }

// static char	**free_list(char **str, int n)
// {
// 	while (n > 0)
// 		free(str[--n]);
// 	free(str);
// 	return (NULL);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**ptr;
// 	char quote_char;
// 	int		i;
// 	int		n;
// 	int start;
// 	int end;

// 	ptr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
// 	if (ptr == NULL)
// 		return (NULL);
// 	i = 0;
// 	n = 0;

// 	while (s && s[i])
// 	{
// 		while (s[i] == c && s[i])
// 			i++;
// 		if(s[i] == '\0')
// 			break;
// 		if(s[i] == '"' || s[i] == '\'')
// 		{
// 			quote_char = s[i];
// 			start = i;
// 			i++;
//             while (s[i] && s[i] != quote_char)
//                 i++;
// 			end = i + 1;
// 			if (s[i] == quote_char)
//                 i++;
// 		}
//   		 else if (s[i])
//         {
// 			start = i;
//             while (s[i] != c && s[i] != quote_char && s[i])
//                 i++;
// 			end = i;
//         }
// 		ptr[n] = ft_substr(s, start, end - start);
// 		if (ptr[n++] == NULL)
// 			return (free_list(ptr, n));
// 	}
// 	ptr[n] = NULL;
// 	return (ptr);
// }

// int count_words(const char *str, char c) 
// {
//     int i = 0, count = 0;
//     char quote_char;

//     while (str && str[i]) {
//         // Skip delimiters
//         while (str[i] == c && str[i])
//             i++;
//         if (str[i] == '\0')
//             break;

//         // Check if current character is a quote
//         if (str[i] == '"' || str[i] == '\'') {
//             quote_char = str[i++];
//             // Move i to the end of the quoted string
//             while (str[i] && str[i] != quote_char)
//                 i++;
//             // If end quote found, move past it
//             if (str[i] == quote_char)
//                 i++;
//             // Count the quoted string as a single word
//             // count++;
//         } else {
//             // Otherwise count the current word
//             count++;
//             while (str[i] && str[i] != c && str[i] != '"' && str[i] != '\'')
//                 i++;
//         }
//     }
//     return count;
// }


// #include <stdio.h>

int count_words(const char *str, char delimiter) 
{
    int i = 0, count = 0;
    char quote_char;
    // int in_word = 0;

    while (str && str[i]) {
        // Skip delimiters
        while (str[i] == delimiter && str[i])
            i++;
        if (str[i] == '\0')
            break;

        // Check if current character is a quote
        if (str[i] == '"' || str[i] == '\'') {
            quote_char = str[i++];
            // Move i to the end of the quoted string
            while (str[i] && str[i] != quote_char)
                i++;
            // If end quote found, move past it
            if (str[i] == quote_char)
                i++;
            if(!str[i])
                count++;
                // i++;
            // continue;
            // Count the quoted string as a single word
        } 
        else if (str[i]){
            // Count the current word
            count++;
            while (str[i] && str[i] != delimiter && str[i] != '"' && str[i] != '\'')
                i++;
        }
    }
    return count;
}

// int main() {
//     const char *test1 = "ls\"a\" one";
//     const char *test2 = "ls\"a\" \"-l\"";
//     const char *test3 = "ls \"a\" one two";
//     const char *test4 = "ls \"a\" \"-l\"";

//     printf("Test 1: %d\n", count_words(test1, ' ')); // should output 2
//     printf("Test 2: %d\n", count_words(test2, ' ')); // should output 2
//     printf("Test 3: %d\n", count_words(test3, ' ')); // should output 3
//     printf("Test 4: %d\n", count_words(test4, ' ')); // should output 2

//     return 0;
// }

//  char **free_list(char **str, int n) {
//     while (n > 0)
//         free(str[--n]);
//     free(str);
//     return NULL;
// }

char **ft_split(char const *s, char c) 
{
    printf("%s\n",s);

    printf("%d\n",count_words(s,c));
    // char **ptr;
    // char quote_char;
    // int i = 0, n = 0, start, end;

    // ptr = malloc((count_words(s, c) + 1) * sizeof(char *));
    // if (ptr == NULL)
    //     return NULL;

    // while (s && s[i]) {
    //     while (s[i] == c && s[i])
    //         i++;
    //     if (s[i] == '\0')
    //         break;

    //     if (s[i] == '"' || s[i] == '\'') 
    //     {
    //         start = i;
    //         quote_char = s[i++];
    //         while (s[i] && s[i] != quote_char)
    //             i++;
    //         if(s[i] == quote_char)
    //             i++;
    //         end = i;
    //         // end = (s[i] == quote_char) ? i++ : i;
    //     } else {
    //         start = i;
    //         while (s[i] && s[i] != c && s[i] != '"' && s[i] != '\'')
    //             i++;
    //         end = i;
    //     }

    //     ptr[n] = ft_substr(s, start, end - start);
    //     if (ptr[n++] == NULL)
    //         return free_list(ptr, n);
    // }
    // ptr[n] = NULL;
    // return ptr;
    return NULL;
}

// l"s -al" ==> exm no val