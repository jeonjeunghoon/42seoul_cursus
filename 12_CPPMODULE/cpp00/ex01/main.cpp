/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:20:48 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/04/05 16:03:15 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
	Phonebook	phonebook;
	std::string	input;

	while (true)
	{
		std::cout << "Enter a command(ADD or SEARCH or EXIT) > ";
		std::getline(std::cin, input);
		for (int i = 0; input[i]; i++)
			input[i] = (char)toupper((char)input[i]);
		if (input.compare("EXIT") == 0)
			break ;
		else if (input.compare("ADD") == 0)
			phonebook.actionAdd();
		else if (input.compare("SEARCH") == 0)
			phonebook.actionSearch();
	}
	phonebook.actionExit();
	return (0);
}
