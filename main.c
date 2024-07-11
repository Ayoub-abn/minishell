/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:58:05 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/11 18:08:51 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//norm lexer
//syntax
int	main(int ac, char **av, char **env)
{
	t_tool	tools;
	t_env	*list;

	if (ac != 1 || av[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	list = envp_to_list(env);
	loop_minishell(&tools, list);
}
