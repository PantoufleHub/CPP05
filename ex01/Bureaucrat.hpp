#pragma once

#include <iostream>
class Form;
#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		void _setGrade(int grade);

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &other);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
