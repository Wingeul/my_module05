#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(Form &form);

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif