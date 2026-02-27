/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:58:53 by cecompte          #+#    #+#             */
/*   Updated: 2026/02/27 18:14:40 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	// Instantiate Form with different grades
	try
	{
		Form Form1("Form1", 5, 7);
		std::cout << Form1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form Form2("TooHigh1", 0, 2);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form Form2("TooHigh2", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form Form2("TooLow1", 200, 2);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form Form2("TooLow2", 2, 200);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// beSigned() and signForm() tests
	
	Bureaucrat Boss("Boss", 4);
	std::cout << Boss << std::endl;
	Bureaucrat Employee("Employee", 10);
	std::cout << Employee << std::endl;
	Form Important("Important File", 5, 7);
	std::cout << Important << std::endl;

	Employee.signForm(Important);
	Boss.signForm(Important);
	
	return 0;
}