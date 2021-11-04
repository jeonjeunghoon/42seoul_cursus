/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:48:31 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/05 03:45:40 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	exception(int argc, char *map_file)
{
	int	i;
	int	correct_extension;

	if (argc != 2)
		return (ERROR);
	i = 0;
	while (map_file[i] != '\0' && map_file[i] != '.')
		i++;
	if (map_file[i] == '\0')
		return (ERROR);
	while (map_file[i] == '.')
		i++;
	correct_extension = ft_strncmp(&(map_file[i]), "ber", \
									ft_strlen(&(map_file[i])));
	if (correct_extension != 0)
		return (ERROR);
	return (0);
}
