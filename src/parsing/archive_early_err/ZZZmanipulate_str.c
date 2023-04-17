
#include "../../includes/minishell.h"

// void	manipulate_input(char **input)
// {
// 	unify_spaces(input);
// 	remove_extra_spaces(input);
// 	printf("cleaned input: %s\n", *input);
// }

// int	ft_isspace(char c)
// {
// 	return ((c == ' ' || c == '\f'
// 			|| c == '\r' || c == '\t' || c == '\v'));
// }

// /* 
// all ISSPACE chars will become SPACE char

// then uses STRTRIM to cut leading and closing spaces
// */
// void	unify_spaces(char **input)
// {
// 	char	*new;
// 	int		i;
// 	int		j;


// 	new = ft_strdup(*input);
// 	i = -1;
// 	j = 0;
// 	while ((*input)[++i])
// 	{
// 		if (quotes_are_closed((*input)[i]) && ft_isspace((*input)[i]))
// 		{
// 			new[j++] = ' ';
// 			continue ;
// 		}
// 		new[j++] = (*input)[i];
// 	}
// 	quotes_default(); // reset for using this check in next function
// 	new[j] = '\0';
// 	new = ft_strtrim(new, " "); //malloc, remove left, right spaces
// 	*input = ft_strdup(new);
// 	free(new);
// }

// /* removes SPACES which occure more then 1 time in a row */
// void	remove_extra_spaces(char **input)
// {
// 	char	*new;
// 	int		i;
// 	int		j;

// 	new = ft_strdup(*input);
// 	i = -1;
// 	j = 0;
// 	while ((*input)[++i])
// 	{
// 		if (quotes_are_closed((*input)[i]) && (*input)[i] == ' '
// 			&& (*input)[i + 1] && (*input)[i + 1] == ' ')
// 			continue ;
// 		new[j++] = (*input)[i];
// 	}
// 	quotes_default();
// 	new[j] = '\0';
// 	new = ft_strtrim(new, " ");
// 	*input = ft_strdup(new);
// 	free(new);
// }