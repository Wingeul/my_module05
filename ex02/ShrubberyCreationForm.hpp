#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
    const std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    std::string getTarget() const;

    void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form);

#endif