#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon Form", 25, 5), target("Default")
{
    std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
    : AForm("Presidential Pardon Form", 25, 5), target(target)
{
    std::cout << "Parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) 
    : AForm(copy), target(copy.target)
{
    std::cout << "Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

const std::string &PresidentialPardonForm::getTarget() const
{
    return target;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form)
{
    std::string isSigned = "No";
    if (form.getIsSigned())
        isSigned = "Yes";
    out << "PresidentialPardonForm: " << form.getName() 
        << ", Target: " << form.getTarget() 
        << ", Signed: " << isSigned
        << ", Sign Grade: " << form.getSignGrade() 
        << ", Execute Grade: " << form.getExecuteGrade();
    return out;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
    {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > getExecuteGrade())
    {
        throw AForm::GradeTooLowException();
    }
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
