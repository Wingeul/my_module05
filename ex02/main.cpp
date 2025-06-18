/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:34:33 by paul              #+#    #+#             */
/*   Updated: 2025/06/18 19:21:17 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat bureaucrat1("Alice", 50);
        std::cout << bureaucrat1 << std::endl;

        Bureaucrat bureaucrat2("Bob", 7);
        std::cout << bureaucrat2 << std::endl;
        ShrubberyCreationForm shrubberyForm("Garden");
        std::cout << shrubberyForm << std::endl;
        RobotomyRequestForm robotomyForm("Robot");
        std::cout << robotomyForm << std::endl;
        PresidentialPardonForm pardonForm("President");
        std::cout << pardonForm << std::endl;
        bureaucrat1.signForm(shrubberyForm);
        std::cout << shrubberyForm << std::endl;
        shrubberyForm.execute(bureaucrat2);
        //bureaucrat2.signForm(robotomyForm);
        std::cout << robotomyForm << std::endl;
        bureaucrat2.executeForm(robotomyForm);

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}