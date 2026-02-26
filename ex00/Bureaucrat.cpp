#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void) : _name("name"), _grade(1)
{
    std::cout << "Bureaucrat default constructor called\n";
    return ;
}

// Parametized constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException;
    std::cout << "Bureaucrat parametized constructor called\n";
    return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy consructor called\n";
    (void) other;
    return ;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat assignment operator called\n";
    (void) other;
    return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called\n";
    return ;
}

