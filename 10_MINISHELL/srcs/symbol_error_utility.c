/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_error_utility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:43:38 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/04 15:43:47 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	error_check_another(char *symbol)
{
	error_1(symbol, "command not found", 127);
	return (ERROR);
}

int	error_check_nearsymbol(char *near_symbol)
{
	error_symbol(near_symbol, 258);
	return (ERROR);
}

int	error_check_redirect(char *next_str)
{
	if (next_str == NULL)
	{
		error_symbol("newline", 258);
		return (ERROR);
	}
	if ((is_symbol(next_str) == TRUE))
	{
		error_symbol(next_str, 258);
		return (ERROR);
	}
	return (0);
}

int	error_check_pipe(char *prev_str, char *next_str, char *symbol)
{
	if (prev_str == NULL || next_str == NULL)
	{
		error_symbol(symbol, 258);
		return (ERROR);
	}
	return (0);
}

int	error_check_and_or(char *prev_str, char *next_str, char *symbol)
{
	if (prev_str == NULL || next_str == NULL || \
		is_symbol(prev_str) == TRUE || \
		is_symbol(next_str) == TRUE)
	{
		error_symbol(symbol, 258);
		return (ERROR);
	}
	return (0);
}
