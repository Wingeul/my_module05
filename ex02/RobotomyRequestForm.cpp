#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 72, 45), target("Default")
{
    std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("Robotomy Request Form", 72, 45), target(target)
{
    std::cout << "Parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
    : AForm(copy), target(copy.target)
{
    std::cout << "Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

const std::string &RobotomyRequestForm::getTarget() const
{
    return target;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
    std::string isSigned = "No";
    if (form.getIsSigned())
        isSigned = "Yes";
    out << "RobotomyRequestForm: " << form.getName() 
        << ", Target: " << form.getTarget() 
        << ", Signed: " << isSigned
        << ", Sign Grade: " << form.getSignGrade() 
        << ", Execute Grade: " << form.getExecuteGrade();
    return out;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
    {
        std::cout << "Form " << getName() << " is not signed." << std::endl;
        return;
    }
    if (executor.getGrade() > getExecuteGrade())
    {
        throw Bureaucrat::GradeTooLowException();
    }
    
    std::cout << " BzZzZzZ... **drilling noises** BzZzZzZ... "<< std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully !" << std::endl;
    else
        std::cout << " robotomy failed..." << std::endl;
}