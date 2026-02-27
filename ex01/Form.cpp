/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:58:44 by cecompte          #+#    #+#             */
/*   Updated: 2026/02/27 18:15:28 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form(void) : _name("Default name"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << "Form default constructor called\n";
    return ;
}

// Parametized constructor
Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
    _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form parametized constructor called\n";
}

// Copy constructor
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), 
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
{
    std::cout << "Form copy consructor called\n";
    return ;
}

// Assignment operator overload
Form &Form::operator=(const Form &other)
{
    std::cout << "Form assignment operator called\n";
    if (this != &other)
    {
        // _name, _gradeToSign and _gradeToExecute are const, cannot be reassigned
        this->_isSigned = other._isSigned;
    }
    return (*this);
}

// Destructor
Form::~Form(void)
{
    std::cout << "Form destructor called\n";
    return ;
}

std::string Form::getName() const
{
    return (_name);
}

bool Form::getIsSigned() const
{
    return (_isSigned);
}

int Form::getGradeToSign() const
{
    return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << " is ";
    if (form.getIsSigned() == false)
        out << "not signed, ";
    else
        out << "signed, ";
    out << "grade required to sign is " << form.getGradeToSign();
    out << " and grade required to execute is " << form.getGradeToExecute() << ".";
    return (out);
}