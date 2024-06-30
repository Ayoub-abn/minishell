/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:58:05 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/30 23:55:40 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_tool	tools;
	// t_list *head = NULL;
	// ft_memset(&tools,0,sizeof(t_tool));

	if (ac != 1 || av[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	// tools.env_copy = array_cpy(env);
	t_env *list = envp_to_list(env);
  /*   while (list)
    {
        printf("key = %s\n", list->key);
        printf("value = %s\n", list->value);
        list = list->next;
    } */
	loop_minishell(&tools,list);
}
