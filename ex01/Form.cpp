#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}

Form::Form(const Form &copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Form::Form(const std::string &name, int signGrade, int executeGrade) 
    : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

const std::string &Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getSignGrade() const {
    return signGrade;
}

int Form::getExecuteGrade() const {
    return executeGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat)
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

std::ostream &operator<<(std::ostream &out, const Form &form)
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