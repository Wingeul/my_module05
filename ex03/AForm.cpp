/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <paul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:35:02 by paul              #+#    #+#             */
/*   Updated: 2025/06/18 18:35:03 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
    std::cout << "Default constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "Destructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
    std::cout << "Copy constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade) 
    : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
}

const std::string &AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getSignGrade() const {
    return signGrade;
}

int AForm::getExecuteGrade() const {
    return executeGrade;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (isSigned)
    {
        std::cout << bureaucrat.getName() << " couldn't sign " << name 
                  << " because it is already signed." << std::endl;
        return;
    }
    if (bureaucrat.getGrade() > signGrade)
    {
        std::cout << bureaucrat.getName() << " couldn't sign " << name 
                  << " because their grade is too low." << std::endl;
        throw GradeTooLowException();
    }
    isSigned = true;
    std::cout << bureaucrat.getName() << " signed "<< name << std::endl;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    std::string signedStatus;
    signedStatus = "no";
    if (form.getIsSigned())
        signedStatus = "yes";
    out << "Form: " << form.getName() 
        << ", Signed: " << signedStatus
        << ", Sign Grade: " << form.getSignGrade() 
        << ", Execute Grade: " << form.getExecuteGrade() 
        << "." << std::endl;
    return out;
}