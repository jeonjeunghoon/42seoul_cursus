/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:00:45 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/04/05 22:17:49 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::printContact(int i)
{
	if (this->firstName.empty() || this->lastName.empty() || this->nickname.empty())
	{
		std::cout << "Empty contact" << std::endl;
		Contact();
		i--;
		return ;
	}
	std::cout << "Index : " << i << " | ";
	std::cout << "First name : " << this->firstName << " | ";
	std::cout << "Last name : " << this->lastName << " | ";
	std::cout << "Nickname : " << this->nickname << " | ";
	std::cout << "Login : " << this->login << " | ";
	std::cout << "Postal address : " << this->postalAddress << " | ";
	std::cout << "Email address : " << this->emailAddress << " | ";
	std::cout << "Phone number : " << this->phoneNumber << " | ";
	std::cout << "Birth day date : " << this->birthDayDate << " | ";
	std::cout << "Favorite meal : " << this->favoriteMeal << " | ";
	std::cout << "Underwear color : " << this->underwearColor << " | ";
	std::cout << "Darkest secret : " << this->darkestSecret << std::endl;
}

void	Contact::setField(std::string message, std::string valMsg, std::string &value, std::string dict)
{
	std::string	input;

	while (true)
	{
		input.clear();
		std::cout << message << std::endl;
		std::cout << valMsg << " > ";
		getline(std::cin, input);
		if (dict.empty())
		{
			value.assign(input);
			break ;
		}
		if (input.find_first_not_of(dict) == std::string::npos)
		{
			value.assign(input);
			break ;
		}
	}
}

void	Contact::setContact(int index)
{
	this->index = stoi();
	setField("Please enter only alphabets", "First name", this->firstName, ALPHA);
	setField("Please enter only alphabets", "Last name", this->lastName, ALPHA);
	setField("Please enter only alphabets", "Nickname", this->nickname, ALPHA);
	setField("Please Enter alphabets and numbers", "Login", this->login);
	setField("Please enter only numbers", "Phone number", this->postalAddress, NUMBER);
	setField("Please Enter alphabets and numbers", "Email address", this->emailAddress);
	setField("Please enter only numbers", "Postal address", this->phoneNumber, NUMBER);
	setField("Please enter only numbers", "Birth day date", this->birthDayDate, NUMBER);
	setField("Please enter only alphabets", "Favorite meal", this->favoriteMeal, ALPHA);
	setField("Please enter only alphabets", "Underwear color", this->underwearColor, ALPHA);
	setField("Please Enter alphabets and numbers", "Darkest secret", this->darkestSecret);
}

Contact::Contact(void)
{
	firstName.clear();
	lastName.clear();
	nickname.clear();
	login.clear();
	postalAddress.clear();
	emailAddress.clear();
	phoneNumber.clear();
	birthDayDate.clear();
	favoriteMeal.clear();
	underwearColor.clear();
	darkestSecret.clear();
}
