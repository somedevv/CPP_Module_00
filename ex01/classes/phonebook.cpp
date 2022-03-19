/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:27:19 by agaliste          #+#    #+#             */
/*   Updated: 2022/03/19 02:08:40 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

phonebook::phonebook(){ _numberOfContacts = 0;}

phonebook::~phonebook(){}

void	phonebook::search()	{
	std::string index;
	uint64_t 	indexnum;
	
	system("clear");
	_printTable();
	while (true) {
		std::cout << "Index: ";
		std::cin >> index;
		if (!std::regex_match(index, std::regex("^[0-9]+$"))) {
			std::cout << "Index can only be a number!" << std::endl;
			continue;
		}
		indexnum = std::stoi(index);
		if (index.length() == 1 && indexnum < MAX_USERS) {
			if (_contacts[indexnum].contentIsEmpty())
				std::cout << "That index does not exist!" << std::endl;
			else {
				_contacts[indexnum].printContact();
				break;
			}
		}
		else
			std::cout << "Index not valid!" << std::endl;
	}
}

void	phonebook::add()
{
	uint64_t i = 0;

	system("clear");
	std::cout << std::endl << "*-------------------------------------------*" << std::endl;
	std::cout << "|                 ADD USER                  |" << std::endl;
	std::cout << "*-------------------------------------------*" << std::endl;
	while(!_contacts[i].contentIsEmpty())
	{
		if (i >= MAX_USERS)
		{
			i = 0;
			break;
		}
		i++;
	}
	_contacts[i].create();
	if (!(_numberOfContacts > 7))
		_numberOfContacts += 1;
}

void	phonebook::_printTable() {
	std::string	string;

	std::cout << std::endl << "*-------------------------------------------*" << std::endl;
	std::cout << "|     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|" << std::endl;
	std::cout << "*-------------------------------------------*" << std::endl;
	for(int i = 0; (i < _numberOfContacts) && (i < 8); i++) {
		std::cout << "|"; std::cout << std::setw(10) << std::right << i;

		if (_contacts[i].getFName().length() > 9) {
			string = _contacts[i].getFName().substr(0, 9);
			std::cout << "|"; std::cout << std::setw(10) << std::right << string.append(".");
		}
		else {
			std::cout << "|"; std::cout << std::setw(10) << std::right << _contacts[i].getFName();	
		}

		if (_contacts[i].getLName().length() > 9) {
			string = _contacts[i].getLName().substr(0, 9);
			std::cout << "|"; std::cout << std::setw(10) << std::right << string.append(".");
		}
		else {
			std::cout << "|"; std::cout << std::setw(10) << std::right << _contacts[i].getLName();
		}

		if (_contacts[i].getNickname().length() > 9) {
			string = _contacts[i].getNickname().substr(0, 9);
			std::cout << "|"; std::cout << std::setw(10) << std::right << string.append(".");
		}
		else {
			std::cout << "|"; std::cout << std::setw(10) <<  std::right << _contacts[i].getNickname();
		}
		std::cout << "|"; std::setw(1); std::cout << "\n";
	}
	std::cout << "*-------------------------------------------*\n" << std::endl;
}