#ifndef CONTACT_HPP
# define CONTACT_HPP

# include	<iostream>
# include	<iomanip>
# include	<string>

# define	ALPHA "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define	NUMBER "0123456789"

class Contact
{
	private :
		int			index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public :
		Contact();
		void		setContact(int index);
		void		setField(std::string message, std::string valMsg, std::string &value, std::string dict = "");
		std::string	adjustContact(std::string contact);
		void		printContact(int index);
};

#endif
