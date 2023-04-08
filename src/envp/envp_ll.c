

#include "../../includes/minishell.h"

/*
probably its possible to store envp as ll, 
so it's easier to remove/add elements in case of export/unset
*/

// typedef struct s_envp
// {
// 	char			*envp_key;
// 	char			*envp_value;
// 	struct s_envp	*next;
// }					t_envp;

/*
function to store the content of envp in a linked list
arg: char **envp  - arr of strings containing an environmental variable
return: t_env * -  first element of the new envp list
*/

void	envplist_handler(t_envp **head, char **envp)
{
	int		i;
	char 	*ptr;
	char	**envp_pair;

	i = 0;
	while (envp[i] != NULL)
	{
		ptr = ft_strchr(envp[i], '=');
		envp_pair = ft_calloc(sizeof(char *), 3);
		envp_pair[0] = ft_strdup2(envp[i], ptr - envp[i]);
		envp_pair[1] = ft_strdup(ptr + 1);
		ft_envp_add_back(head, create_envp_node(envp_pair));
		i++;
	}
	// update_shell_lvl(envp_ll) ??
}

/*
create a list element for the envp ll from an array of
two strings - key and value
takes data [char **]  - arr of two strings containing the name and
the content of an envp variable.
returns [t_env *] List element created from the string array.
*/
t_envp	*create_envp_node(char **data)
{
	t_envp	*element;

	element = malloc(sizeof(t_envp));
	if (!element)
		return (NULL);
	element->sorted = 0;
	element->envp_key = data[0];
	if (data[1] == NULL)
		element->envp_value = NULL;
	else
		element->envp_value = data[1];
	element->next = NULL;
	return (element);
}


void	ft_envp_add_back(t_envp **lst, t_envp *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_envp_last(*lst)->next = new;
}

/* 
returns pointer to the last element - NOT NEEDED, should we rewrite function?
*/
t_envp	*ft_envp_last(t_envp *lst)
{
	t_envp	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

