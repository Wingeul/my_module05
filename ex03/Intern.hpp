#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <stdexcept>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Bureaucrat;

class Intern
{
public:
    Intern();
    Intern(const Intern &copy);
    ~Intern();
    Intern &operator=(const Intern &other);

    AForm *makeForm(const std::string &formName, const std::string &target) const;

    class WrongFormException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return "Wrong form type.";
            }
    };
};

#endif