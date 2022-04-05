#ifndef CONTACT_HPP
# define CONTACT_HPP

# include	<iostream>
# include	<iomanip>

# define	ALPHA "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define	NUMBER "0123456789"

class Contact
{
	private :
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	login;
		std::string	postalAddress;
		std::string	emailAddress;
		std::string	phoneNumber;
		std::string	birthDayDate;
		std::string	favoriteMeal;
		std::string	underwearColor;
		std::string	darkestSecret;
	public :
		Contact();
		void	setContact(void);
		void	setField(std::string message, std::string valMsg, std::string &value, std::string dict = 0);
		void	printContact(void);
};

#endif
