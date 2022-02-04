/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:00:31 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/02/04 16:17:04 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_bool	is_valid_symbol(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '&')
	{
		error_1(str, "invalid symbol");
		return (FALSE);
	}
	if (len == 2 && str[0] != str[1])
	{
		error_symbol(str[1]);
		return (FALSE);
	}
	if (len > 2 || (len == 2 && str[0] != str[1]))
	{
		error_symbol(str[len - 1]);
		return (FALSE);
	}
	return (TRUE);
}

int	stream_flag_str(t_token *token)
{
	int		i;
	char	*str;

	if (token->single_quote == TRUE || token->double_quote == TRUE)
		return (0);
	i = 0;
	str = token->token;
	while (str[i] != '\0')
	{
		if (str[i] == '|' || str[i] == '>' || str[i] == '<' || str[i] == '&')
			return (TRUE);
		i++;
	}
	return (0);
}

void	token_init(t_token *token)
{
	token->token = NULL;
	token->single_quote = FALSE;
	token->double_quote = FALSE;
}

void	create_stream(t_argv **stream, t_token *token, t_list **argv_lst)
{
	(*stream) = (t_argv *)malloc(sizeof(t_argv));
	(*stream)->argv = (char **)malloc(sizeof(char *) * 2);
	(*stream)->argv[0] = ft_strdup(token->token);
	(*stream)->argv[1] = NULL;
	(*stream)->is_stream = TRUE;
	ft_lstadd_back(argv_lst, ft_lstnew(*stream));
}

void	create_argv(t_argv **argv, t_list *token_lst, \
					t_list **argv_lst, int size)
{
	int		i;

	(*argv) = (t_argv *)malloc(sizeof(t_argv));
	(*argv)->argv = (char **)malloc(sizeof(char *) * (size + 1));
	(*argv)->argv[size] = NULL;
	i = 0;
	while (token_lst != NULL && i < size && \
			stream_flag_str(token_lst->content) == FALSE)
	{
		(*argv)->argv[i] = ft_strdup(((t_token *)token_lst->content)->token);
		i++;
		token_lst = token_lst->next;
	}
	(*argv)->is_stream = FALSE;
	ft_lstadd_back(argv_lst, ft_lstnew(*argv));
}
