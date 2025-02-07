#pragma once

#include <iostream>
class Bureaucrat;
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
		void _setSignGrade(int grade);
		void _setExecGrade(int grade);

	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &other);
		~Form();

		Form &operator=(const Form &other);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};

		int getSignGrade() const;
		int getExecGrade() const;
		bool getIsSigned() const;
		std::string getName() const;

		void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);
