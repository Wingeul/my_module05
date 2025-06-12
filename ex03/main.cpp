#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    try 
    {
        Bureaucrat bureaucrat1("Alice", 50);
        std::cout << bureaucrat1;

        Bureaucrat bureaucrat2("Bob", 7);
        std::cout << bureaucrat2;
        
        Intern intern;
        AForm *shrubberyForm = intern.makeForm("Shrubbery creation", "Garden");
        std::cout << *shrubberyForm;
        AForm *robotomyForm = intern.makeForm("rature", "Robot");
        std::cout << *robotomyForm;

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}