/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:50:49 by aabdenou          #+#    #+#             */
/*   Updated: 2024/06/30 16:38:02 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../minishell.h"

void	add_node_env(t_env **head, char *key, char *value)
{
	t_env	*node;
	node = ft_env_new(key, value);
	if (!node)
	{
		//memory problem
		return ;
	}
	ft_lstadd_back_env(head, node);
}

void expand(char **env)
{
    t_env *head = NULL;
    int i = 0;
    char **key_and_value = NULL;

    while (env[i])
    {
        key_and_value = ft_split_for_equal(env[i], '=');
        if (key_and_value)
        {
            add_node_env(&head, key_and_value[0], key_and_value[1]);

            // Free the key-value pair
            // free(key_and_value[0]);
            // free(key_and_value[1]);
            free(key_and_value);
        }
        i++;
    }
    aff(head);
    t_env *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);
    }
 } 
// }

void aff(t_env *data)
{
    while (data)
    {
        printf("key-[%s]-\tvalue-[%s]-\n", data->key, data->value);
        data = data->next;
    }
}