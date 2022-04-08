/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:20:48 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/04/08 18:54:40 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
	Phonebook	phonebook;
	std::string	input;

	while (1)
	{
		input.clear();
		std::cout << "Enter a command(ADD or SEARCH or EXIT) > ";
		std::getline(std::cin, input);
		for (int index = 0; input[index]; index++)
			input[index] = static_cast<char>(toupper(input[index]));
		if (input.compare("EXIT") == 0)
			break ;
		else if (input.compare("ADD") == 0)
			phonebook.actionAdd();
		else if (input.compare("SEARCH") == 0)
			phonebook.actionSearch();
		else
			std::cout << "Wrong input !" << std::endl;
	}
	phonebook.actionExit();
	return (0);
}
