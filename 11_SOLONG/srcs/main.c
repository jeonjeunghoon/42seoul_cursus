/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:01:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/10/30 18:04:36 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_resource()
{
	return (0);
}

int	start_game()
{

	return (0);
}

int	game_data_init()
{

	return (0);
}

int	variable_init()
{

	return (0);
}

int main(void)
{
	variable_init();
	mlx_init();
	game_data_init();
	start_game();
	free_resource();
	return (0);
}
