/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:48:31 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/03 01:49:02 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exception(int argc, char *map_file)
{
	int	i;
	int	correct_extension;

	if (argc != 2) // 매개변수는 ./so_long *.ber 형태로 들어온다.
		return (ERROR);
	i = 0;
	while (map_file[i] != '\0' && map_file[i] != '.') // 맵파일 검사1
		i++;
	if (map_file[i] == '\0')
		return (ERROR);
	while (map_file[i] == '.') // 일단 map..............ber 이런 형태의 이름도 가능하게 해뒀는데 이건 얘기해보자
		i++;
	correct_extension = ft_strncmp(&(map_file[i]), "ber", ft_strlen(&(map_file[i]))); // 확장자 ber 검사 마지막 인자가 ft_strlen 인 이유는 *.berrrrrr 이런 형식의 오류도 잡기 위해서임
	if (correct_extension != 0)
		return (ERROR);
	return (0); // -> 다 잡은 것같긴 한데 놓친거 있을 지도 모르니까 한번 확인해주셈
}
