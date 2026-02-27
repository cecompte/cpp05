/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:58:49 by cecompte          #+#    #+#             */
/*   Updated: 2026/02/27 16:43:42 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
    std::string const _name;
    int _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif

