/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:34:49 by paul              #+#    #+#             */
/*   Updated: 2025/06/18 19:06:12 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137), target("Default")
{
    std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("Shrubbery Creation Form", 145, 137), target(target)
{
    std::cout << "Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
    : AForm(copy), target(copy.target)
{
    std::cout << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this == &other) {
        return *this;
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (this->target);
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
    std::string isSigned = "No";
    if (form.getIsSigned())
        isSigned = "Yes";
    out << "ShrubberyCreationForm: " << form.getName() 
        << ", Target: " << form.getTarget() 
        << ", Signed: " << isSigned
        << ", Sign Grade: " << form.getSignGrade() 
        << ", Execute Grade: " << form.getExecuteGrade();
    return out;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
    {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > getExecuteGrade())
    {
        throw Bureaucrat::GradeTooLowException();
    }

    std::ofstream file(this->getTarget().append("_shrubbery").c_str());

    file << "       ###    ###     ####   ###    ###     ##    " << std::endl;
    file << "      #####  #####   ###### #####  #####   ####   " << std::endl;
    file << "     ############## ########### ####### ########  " << std::endl;
    file << "       ||     ||       ||     ||     ||     ||    " << std::endl;
    file << "       ||     ||       ||     ||     ||     ||    " << std::endl;
    file << "       ||     ||       ||     ||     ||     ||    " << std::endl;
    file << "                                                 " << std::endl;
    file << "   ###    ###     ###   ###     ####     ###     " << std::endl;
    file << "  #####  #####   ##### #####   ######   #####    " << std::endl;
    file << " ####### ###### ###### ###### ######## ######   " << std::endl;
    file << "    ||     ||      ||    ||      ||       ||     " << std::endl;
    file << "    ||     ||      ||    ||      ||       ||     " << std::endl;
    file << "    ||     ||      ||    ||      ||       ||     " << std::endl;
    file.close();
}