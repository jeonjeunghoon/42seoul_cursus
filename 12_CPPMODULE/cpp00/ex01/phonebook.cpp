/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:02:38 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/04/05 22:15:42 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	Phonebook::actionExit()
{
	std::cout << "BYE" << std::endl;
	return ;
}

void	Phonebook::actionAdd()
{
	static int	i = 0;

	if (i == 8)
	{
		std::cout << "Contacts Full" << std::endl;
		return ;
	}
	this->page[i].setContact(i);
	i++;
}

void	Phonebook::actionSearch(int i)
{
	if (i == -1)
	{
		for (i = 0; i < 8; i++)
			this->page[i].printContact(i);
	}
	else
		this->page[i].printContact(i);
}
