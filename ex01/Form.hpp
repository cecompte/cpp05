/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:58:49 by cecompte          #+#    #+#             */
/*   Updated: 2026/02/27 18:15:34 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
        std::string const _name;
        bool _isSigned;
        int const _gradeToSign;
        int const _gradeToExecute;
    public:
        Form(void);
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form &operator=(const Form &other);
        ~Form();
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat& bureaucrat);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too high";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too low";
                }
        };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif

