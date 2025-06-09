#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int executeGrade;
public:
    Form();
    Form(const Form &copy);
    Form(const std::string &name, int signGrade, int executeGrade);
    ~Form();

    const std::string &getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void beSigned(Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return "Grade too high.";
            }
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {    
                return "Grade too low.";
            }
    };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif