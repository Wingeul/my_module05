#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "Intern copy constructor called" << std::endl;
    (void)copy;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    if (formName == "shrubbery creation")
        return new ShrubberyCreationForm(target);
    else if (formName == "robotomy request")
        return new RobotomyRequestForm(target);
    else if (formName == "presidential pardon")
        return new PresidentialPardonForm(target);
    else
        throw WrongFormException();
}
