/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cecompte <cecompte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:58:53 by cecompte          #+#    #+#             */
/*   Updated: 2026/02/27 16:51:35 by cecompte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	// Instantiate Bureaucrat with different grades
	
	try
	{
		Bureaucrat New("New", 4);
		std::cout << New << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat TooHigh("Too High", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat TooLow("Too Low", 200);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Increment or decrement grades

	Bureaucrat best("Best", 1);
	std::cout << best << std::endl;
	Bureaucrat worst("Worst", 150);
	std::cout << worst << std::endl;

	try
	{
		best.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		worst.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		best.decrementGrade();
		std::cout << best << std::endl;
		worst.incrementGrade();
		std::cout << worst << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}