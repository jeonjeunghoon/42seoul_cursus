/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 00:37:13 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/17 00:39:26 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	stream_parse_condition(char ch)
{
	if (ch != '\0' && ch != ' ' && ch != '\'' && ch != '\"' && \
		(ch == '|' || ch == '>' || ch == '<' || ch == '&'))
		return (TRUE);
	return (FALSE);
}

int	str_parse_condition(char ch)
{
	if (ch != '\0' && ch != ' ' && ch != '\'' && ch != '\"' && \
		ch != '|' && ch != '>' && ch != '<' && ch != '&')
		return (TRUE);
	return (FALSE);
}
