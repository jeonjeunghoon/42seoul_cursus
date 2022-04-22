/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:47:35 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/04/22 17:47:13 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include	<iostream>
# include	<iomanip>
# include	<string>

# define	INPUT_EXIT 0
# define	INPUT_ADD 1
# define	INPUT_SEARCH 2
# define	INPUT_WRONG -1
# define	ALPHA "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define	NUMBER "0123456789"

class Contact {
	private :
		int			i;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public :
		void		setContact(int index);
		void		setField(std::string message, std::string valMsg, std::string &value, std::string dict = "");
		std::string	adjustContact(std::string contact);
		void		printContact();
		void		printContact(int index);
};

class PhoneBook {
	private:
		std::string	input;
		Contact		page[8];
	public:
		void		getInput();
		int			checkInput();
		void		actionExit();
		void		actionAdd();
		void		actionSearch();
};

#endif
