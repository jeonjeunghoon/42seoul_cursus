/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:37:13 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/27 18:51:06 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_bool	stream_condition(char c)
{
	if (c != '|' && c != '>' && c != '<' && c != '&')
		return (FALSE);
	return (TRUE);
}

t_bool	str_condition(char c, t_token *token)
{
	if (c == '|' || c == '>' || c == '<' || c == '&')
		return (FALSE);
	exception_utility(c, &(token->single_quote), &(token->double_quote));
	if (token->single_quote == FALSE && token->double_quote == FALSE && \
		c == ' ')
		return (FALSE);
	return (TRUE);
}
