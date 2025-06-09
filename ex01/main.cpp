#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try 
    {
        Bureaucrat bureaucrat1("Alice", 50);
        std::cout << bureaucrat1;

        Bureaucrat bureaucrat2("Bob", 7);
        std::cout << bureaucrat2;

        Form formA("Form A", 100, 10);
        std::cout << formA;

        Form formB("Form B", 25, 25);
        std::cout << formB;

        bureaucrat2.signForm(formA);
        std::cout << formA;
        bureaucrat2.signForm(formA);
        bureaucrat1.signForm(formB);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}