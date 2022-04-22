/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:20:48 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/04/22 17:37:58 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
	PhoneBook	pb;

	while (true) {
		pb.getInput();
		switch (pb.checkInput()) {
			case INPUT_EXIT:
				pb.actionExit();
				return 0;
			case INPUT_ADD:
				pb.actionAdd();
				break;
			case INPUT_SEARCH:
				pb.actionSearch();
				break;
			default:
				std::cout << "Wrong input !\n" << std::endl;
				continue;
		}
    }
	return 0;
}
