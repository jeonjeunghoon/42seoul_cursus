/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:02:38 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/04/08 18:53:15 by jeunjeon         ###   ########.fr       */
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
	static int	index = 0;

	this->page[index].setContact(index);
	index = (index + 1) % 8;
}

void	Phonebook::actionSearch()
{
	std::string	input;
	int			ret;

	for (int i = 0; i < 8; i++)
		this->page[i].printContact(i);
	std::cout << "Enter index(0 ~ 7): ";
	getline(std::cin, input);
	if (input.size() == 1 && input.find_first_of("01234567") != std::string::npos)
		this->page[input[0] - '0'].printContact(input[0] - '0');
	else
		std::cout << "Wrong index" << std::endl;
}
