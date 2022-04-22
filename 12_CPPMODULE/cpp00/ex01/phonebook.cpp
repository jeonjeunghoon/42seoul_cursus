/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:02:38 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/04/22 18:07:11 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string Contact::adjustContact(std::string contact) {
	std::string result_str;

	std::cout << std::setw(10);
	if (contact.size() > 10) {
		result_str.assign(contact, 0, 9);
		result_str.append(".");
	}
	else {
		result_str.assign(contact);
	}
	return result_str;
}

void	Contact::printContact() {
		if (this->firstName.empty() || this->lastName.empty() || this->nickname.empty())
			return ;
		std::cout << "=======================" << std::endl;
		std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << this->i << "|" << std::endl;
		std::cout << "|" << std::setw(10) << "First name" << "|" << adjustContact(this->firstName) << "|" << std::endl;
		std::cout << "|" << std::setw(10) << "Last name" << "|" << adjustContact(this->lastName) << "|" << std::endl;
		std::cout << "|" << std::setw(10) << "Nickname" << "|" << adjustContact(this->nickname) << "|" << std::endl;
		std::cout << "=======================\n" << std::endl;
}

void	Contact::printContact(int i) {
	if (this->firstName.empty() || this->lastName.empty() || this->nickname.empty()) {
		std::cout << "This page is empty\n" << std::endl;
		return ;
	}
	std::cout << "=======================" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << i << "|" << std::endl;
	std::cout << "|" << std::setw(10) << "First name" << "|" << adjustContact(this->firstName) << "|" << std::endl;
	std::cout << "|" << std::setw(10) << "Last name" << "|" << adjustContact(this->lastName) << "|" << std::endl;
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << adjustContact(this->nickname) << "|" << std::endl;
	std::cout << "=======================\n" << std::endl;
}

void	Contact::setField(std::string message, std::string valMsg, std::string &value, std::string dict) {
	std::string	input;

	while (true) {
		std::cout << message;
		std::cout << valMsg;
		getline(std::cin, input);
		std::cout << std::endl;
		if (dict.empty() && !input.empty()) {
			value.assign(input);
			break ;
		}
		else if (!dict.empty() && !input.empty() && input.find_first_not_of(dict) == std::string::npos) {
			value.assign(input);
			break ;
		}
		std::cout << "Wrong input!\n" << std::endl;
	}
}

void	Contact::setContact(int i) {
	this->i = i + 1;
	setField("Please enter only alphabets\n", "First name> ", this->firstName, ALPHA);
	setField("Please enter only alphabets\n", "Last name> ", this->lastName, ALPHA);
	setField("Please enter only alphabets\n", "Nickname> ", this->nickname, ALPHA);
	setField("Please enter only numbers\n", "Phone number> ", this->phoneNumber, NUMBER);
	setField("Please Enter alphabets and numbers\n", "Darkest secret> ", this->darkestSecret);
}

void	PhoneBook::getInput() {
	std::cout << "Enter a command(ADD or SEARCH or EXIT)> ";
	std::getline(std::cin, input);
	for (int i = 0; input[i]; i++)
		input[i] = static_cast<char>(toupper(static_cast<int>(input[i])));
}

int		PhoneBook::checkInput() {
	if (input.compare("EXIT") == 0)
		return INPUT_EXIT;
	else if (input.compare("ADD") == 0)
		return INPUT_ADD;
	else if (input.compare("SEARCH") == 0)
		return INPUT_SEARCH;
	return INPUT_WRONG;
}

void	PhoneBook::actionExit() {
	std::cout << "\nEXIT\n" << std::endl;
	return ;
}

void	PhoneBook::actionAdd() {
	static int	i = 0;

	std::cout << "\nADD ...\n" << std::endl;
	this->page[i].setContact(i);
	i = (i + 1) % 8;
}

void	PhoneBook::actionSearch() {
	std::string	input;

	std::cout << "\nSEARCH ...\n" << std::endl;
	for (int i = 0; i < 8; i++)
		this->page[i].printContact();
	while (true) {
		std::cout << "Enter index(1 ~ 8)> ";
		getline(std::cin, input);
		if (input.size() == 1 && input.find_first_of("12345678") != std::string::npos) {
			this->page[input[0] - 1 - '0'].printContact(input[0] - '0');
			break;
		}
		else if (input.size() == 1 && input.compare("0") == 0) {
			break;
		}
		std::cout << "Wrong input !\n" << std::endl;
	}
}
