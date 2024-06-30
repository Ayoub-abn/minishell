/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:58:05 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/29 22:41:49 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)env;
	t_tool	tools;
	// t_list *head = NULL;
	// ft_memset(&tools,0,sizeof(t_tool));

	if (ac != 1 || av[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	// tools.env_copy = array_cpy(env);
	// int i = 0;

	// while (tools.env[i])
	// {
	// 	printf("%s\n",tools.env[i++]);
	// }
	
	loop_minishell(&tools,env);
}
