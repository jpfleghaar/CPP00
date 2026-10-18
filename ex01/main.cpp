/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 04:17:50 by jpflegha          #+#    #+#             */
/*   Updated: 2025/11/27 20:06:46 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string cmd;

    std::cout   << "Welcome to the Awesome Phone Book!!!" <<std::endl;
    while (42)
    {
        std::cout   << "Enter ADD to add a new contact, SEARCH to look one up, or EXIT to quit.\n";
        if (!std::getline(std::cin, cmd))
            break;
        if (cmd == "ADD")
            phoneBook.addContact();
        else if (cmd == "SEARCH")
            phoneBook.searchContacts();
        else if (cmd == "EXIT")
            break;
    }
    return(0);
}