/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 04:16:59 by jpflegha          #+#    #+#             */
/*   Updated: 2025/12/02 16:04:37 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

PhoneBook::PhoneBook() : count(0), next(0) {}

static  std::string truncation(const std::string &str)
{
    if (str.length() > 10)
    {
        return (str.substr(0, 9) + '.');
    }
    else
        return (str);
}
void    PhoneBook::addContact()
{
    std::string input = "";
    while (input == "")
    {

        std::cout << "What is the first name ?\n";
        if (!std::getline(std::cin, input))
            return ;
        contacts[next].setFirstName(input);
        
    }
    
    input = "";
    while (input == "")
    {
        
        std::cout << "What is the last name ?\n";
        if (!std::getline(std::cin, input))
            return ;
        contacts[next].setLastName(input);
        
    }
    
    input = "";
    while (input == "")
    {

        std::cout << "What is the nickname ?\n";
        if (!std::getline(std::cin, input))
            return ;
        contacts[next].setNickname(input);
        
    }
    input = "";

    while (input == "")
    {

        input = "";
        std::cout << "What is the Phone number ?\n";
        if (!std::getline(std::cin, input))
            return ;
        contacts[next].setPhoneNumber(input);

    }
    
    input = "";
    while (input == "")
    {
        std::cout << "What is the Darkest secret ?\n";
        if (!std::getline(std::cin, input))
            return ;
        contacts[next].setDarkestSecret(input);

    }

    if (count < 8)
        count++;
    next = (next + 1) % 8;
}
void PhoneBook::displayContacts(int index) const
{
    const contact &c = contacts[index];

    std::cout << std::left; // left-align text

    std::cout << std::setw(15) << "\nFirst name:"     << c.getFirstName()     << '\n';
    std::cout << std::setw(15) << "Last name:"      << c.getLastName()      << '\n';
    std::cout << std::setw(15) << "Nickname:"       << c.getNickname()      << '\n';
    std::cout << std::setw(15) << "Phone number:"   << c.getPhoneNumber()   << '\n';
    std::cout << std::setw(15) << "Darkest secret:" << c.getDarkestSecret() << "\n\n";
}


void    PhoneBook::searchContacts() const
{
    if (count == 0)
    {
        std::cout << "PhoneBook is empty or broken.\n";
        return ;
    }
    std::cout   << std::setw(10) << "Index" << " | "
                << std::setw(10) << "First Name" << " | "
                << std::setw(10) << "Last Name" << " | "
                << std::setw(10) << "Nickname" << "\n";
    for (int i = 0; i < count; i++)
    {
        std::cout   << std::setw(10) << i << " | "
                    << std::setw(10) << truncation(contacts[i].getFirstName()) << " | "
                    << std::setw(10) << truncation(contacts[i].getLastName()) << " | "
                    << std::setw(10) << truncation(contacts[i].getNickname())<< " | \n";
    }
    
    std::cout << "Enter index: ";
    std::string indexStr;
    std::getline(std::cin, indexStr);

    if (indexStr.size() != 1 || !isdigit(indexStr[0]))
    {
        std::cout << "Invalid index \n";
        return;
    }
    int index = indexStr[0] - '0';
    if (index < 0 || index >= count)
    {
        std::cout << "Invalid index \n";
        return;
    }
    displayContacts(index);
}
