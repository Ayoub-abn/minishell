#include "minishell.h"

int	env_lstsize(t_env *lst)
{
	t_env	*p;
	int		i;

	i = 0;
	p = lst;
	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}

char **list_to_envp(t_env *list)
{
	char *tmp_key;
	char **line;
	int i = 0;

	line = malloc(sizeof(char *) * env_lstsize(list) + 1);
	while (list)
	{
		tmp_key = list->key;
		tmp_key = ft_strjoin(tmp_key, "=");
		line[i++] = ft_strjoin(tmp_key, list->value);
		list = list->next;
	}
	line[i] = NULL;
	return (line);
}
