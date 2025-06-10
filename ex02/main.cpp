#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    try 
    {
        Bureaucrat bureaucrat1("Alice", 50);
        std::cout << bureaucrat1;

        Bureaucrat bureaucrat2("Bob", 7);
        std::cout << bureaucrat2;
        ShrubberyCreationForm shrubberyForm("Garden");
        std::cout << shrubberyForm;
        RobotomyRequestForm robotomyForm("Robot");
        std::cout << robotomyForm;
        PresidentialPardonForm pardonForm("President");
        std::cout << pardonForm;
        bureaucrat1.signForm(shrubberyForm);
        std::cout << shrubberyForm;
        shrubberyForm.execute(bureaucrat2);
        bureaucrat2.signForm(robotomyForm);
        std::cout << robotomyForm;
        robotomyForm.execute(bureaucrat2);

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}