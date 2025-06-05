#include "Bureaucrat.hpp"

int main() {
    try 
    {
        Bureaucrat bureaucrat1("Alice", 50);
        std::cout << bureaucrat1;

        Bureaucrat bureaucrat2("Bob", 1);
        std::cout << bureaucrat2;
        Bureaucrat bureaucrat3("Charlie", 150);
        std::cout << bureaucrat3;
        bureaucrat3.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}