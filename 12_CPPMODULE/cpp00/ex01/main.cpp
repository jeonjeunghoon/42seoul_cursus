/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:20:48 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/03/10 18:18:21 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	Phonebook	phonebook;
	std::string	input;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "Please Enter a Command" << std::endl;
		std::cout << "> ";
		std::cin >> input;
		if (input.compare("EXIT") == 0) // EXIT
		{
			std::cout << "BYE" << std::endl;
			break ;
		}
		else if (input.compare("ADD") == 0) // ADD
			phonebook.action_add();
		else if (input.compare("SEARCH") == 0) // SEARCH
			phonebook.action_search();
		else
			std::cout << "Please Enter ADD or SEARCH or EXIT" << std::endl;
		std::cout << std::endl;
	}
	return (0);
}