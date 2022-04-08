/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:00:45 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/04/08 19:04:36 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::adjustContact(std::string contact)
{
	std::string result_str;

	std::cout << std::setw(10);
	if (contact.size() > 10) {
		result_str.assign(contact, 0, 9);
		result_str.append(".");
	}
	else
		result_str.assign(contact);
	return result_str;
}

void	Contact::printContact(int index)
{
	if (this->firstName.empty() || this->lastName.empty() || this->nickname.empty())
	{
		std::cout << "This page is empty" << std::endl;
		return ;
	}
	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << index << "|" << std::endl;
	std::cout << "|" << std::setw(10) << "First name" << "|" << adjustContact(this->firstName) << "|" << std::endl;
	std::cout << "|" << std::setw(10) << "Last name" << "|" << adjustContact(this->lastName) << "|" << std::endl;
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << adjustContact(this->nickname) << "|" << std::endl;
}

void	Contact::setField(std::string message, std::string valMsg, std::string &value, std::string dict)
{
	std::string	input;

	while (1)
	{
		std::cout << message << std::endl;
		std::cout << valMsg << " > ";
		getline(std::cin, input);
		if (dict.empty() && !input.empty())
		{
			value.assign(input);
			break ;
		}
		else if (!dict.empty() && !input.empty() && input.find_first_of(dict) != std::string::npos)
		{
			value.assign(input);
			break ;
		}
	}
}

void	Contact::setContact(int index)
{
	this->index = index;
	setField("Please enter only alphabets", "First name", this->firstName, ALPHA);
	setField("Please enter only alphabets", "Last name", this->lastName, ALPHA);
	setField("Please enter only alphabets", "Nickname", this->nickname, ALPHA);
	setField("Please enter only numbers", "Phone number", this->phoneNumber, NUMBER);
	setField("Please Enter alphabets and numbers", "Darkest secret", this->darkestSecret);
}

Contact::Contact(void)
{
	this->firstName.clear();
	this->lastName.clear();
	this->nickname.clear();
	this->phoneNumber.clear();
	this->darkestSecret.clear();
}
