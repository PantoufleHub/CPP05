#pragma once

#include <iostream>
class Bureaucrat;
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
		const std::string _target;
		void _setSignGrade(int grade);
		void _setExecGrade(int grade);

	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade, std::string target);
		AForm(const AForm &other);
		virtual ~AForm();

		AForm &operator=(const AForm &other);

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
		std::string getTarget() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &executor) const;
		virtual void perfromAction(std::string target) const = 0;
		virtual AForm *create(std::string target) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
