/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:46:37 by seungcoh          #+#    #+#             */
/*   Updated: 2022/03/04 11:39:20 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_strstrf(char *str, char *to_find, int flag)
{
	int	i;
	int	j;
	int	slen;
	int	tlen;

	i = -1;
	slen = ft_strlen(str);
	tlen = ft_strlen(to_find);
	if (*to_find == 0)
		return (str);
	if (flag == 2)
		i = slen - tlen - 1;
	while (++i < slen - tlen + 1)
	{
		j = -1;
		while (++j < tlen)
			if (to_find[j] != str[i + j])
				break ;
		if (j == tlen)
			return (str + i + j);
		if (flag == 1)
			break ;
	}
	return (0);
}

void	strstr_token( t_list *wild_token, char **str, int *flag)
{
	t_list	*wild_curr;

	wild_curr = wild_token;
	while (wild_curr)
	{
		if ((*flag & 1) && wild_curr == wild_token)
			*str = ft_strstrf(*str, (char *)wild_curr->content, 1);
		else if ((*flag & 2) && !wild_curr->next)
			*str = ft_strstrf(*str, (char *)wild_curr->content, 2);
		else
			*str = ft_strstrf(*str, (char *)wild_curr->content, 0);
		if (!(*str))
			break ;
		wild_curr = wild_curr->next;
	}
}

t_list	*find_wild_str(t_list *wild_token, t_list *ls_lst, int flag)
{
	t_list	*new_ls_lst;
	t_list	*tmp;
	char	*str;

	new_ls_lst = 0;
	while (ls_lst)
	{
		str = (char *)ls_lst->content;
		strstr_token(wild_token, &str, &flag);
		if (str)
			ft_lstadd_back(&new_ls_lst, ft_lstnew(ls_lst->content));
		tmp = ls_lst->next;
		if (!str)
			free(ls_lst->content);
		free(ls_lst);
		ls_lst = tmp;
	}
	ft_lstclear(&wild_token, free);
	return (new_ls_lst);
}

void	flag_set(t_wild	*wild, t_bool null_flag)
{
	if (wild->i - wild->start_idx && wild->start_idx == 0 && !null_flag)
		wild->flag |= 1;
	wild->flag |= 4;
	wild->start_idx = wild->i + 1;
}

void	flag_set2(t_wild *wild, t_bool null_flag)
{
	if (wild->start_idx && wild->i - wild->start_idx && !null_flag)
		wild->flag |= 2;
}
