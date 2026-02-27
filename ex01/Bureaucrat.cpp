/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:58:44 by cecompte          #+#    #+#             */
/*   Updated: 2026/02/27 18:15:57 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void) : _name("Default name"), _grade(1)
{
    std::cout << "Bureaucrat default constructor called\n";
    return ;
}

// Parametized constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else
        this->_grade = grade;
    std::cout << "Bureaucrat parametized constructor called\n";
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat copy consructor called\n";
    return ;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat assignment operator called\n";
    if (this != &other)
    {
        // _name is const, cannot be reassigned
        this->_grade = other._grade;
    }
    return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called\n";
    return ;
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw (Bureaucrat::GradeTooHighException());
    else
        this->_grade = _grade - 1;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw (Bureaucrat::GradeTooLowException());
    else
        this->_grade = _grade + 1;
}

void Bureaucrat::signForm(Form& form)
{
    try 
    { 
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << ".\n";
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because their " << e.what() << ".\n";
    }  
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return (out);
}