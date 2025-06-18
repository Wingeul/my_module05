/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:35:20 by paul              #+#    #+#             */
/*   Updated: 2025/06/18 19:14:24 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try 
    {
        Bureaucrat bureaucrat1("Alice", 50);
        std::cout << bureaucrat1 << std::endl;

        Bureaucrat bureaucrat2("Bob", 7);
        std::cout << bureaucrat2 << std::endl;
        
        Intern intern;
        AForm *shrubberyForm = intern.makeForm("Shrubbery creation", "Garden");
        std::cout << *shrubberyForm << std::endl;
        delete shrubberyForm;
        AForm *robotomyForm = intern.makeForm("rature", "Robot");
        std::cout << *robotomyForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}