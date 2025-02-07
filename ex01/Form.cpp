#include "Form.hpp"

Form::Form() : _name("Unknown form"), _isSigned(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "Form constructor called" << std::endl;
	_setSignGrade(signGrade);
	_setExecGrade(execGrade);
}

Form::Form(const Form &other) : _name(other.getName()), _isSigned(false), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form ()
{
	std::cout << "Default Form destructor called" << std::endl;
}

void Form::_setSignGrade(int grade)
{
	try
	{
		int *signGrade = (const_cast<int *>(&this->_signGrade));
		if (grade < 1)
		{
			*signGrade = 1;
			throw GradeTooHighException();
		}
		if (grade > 150)
		{
			*signGrade = 150;
			throw GradeTooLowException();
		}
		*signGrade = grade;
	}
	catch(std::exception& e)
	{
		std::cerr << "Form _setSignGrade: " << e.what() << std::endl;
	}
}

void Form::_setExecGrade(int grade)
{
	try
	{
		int *execGrade = (const_cast<int *>(&this->_execGrade));
		if (grade < 1)
		{
			*execGrade = 1;
			throw GradeTooHighException();
		}
		if (grade > 150)
		{
			*execGrade = 150;
			throw GradeTooLowException();
		}
		*execGrade = grade;
	}
	catch(std::exception& e)
	{
		std::cerr << "Form _setExecGrade: " << e.what() << std::endl;
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high exception";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low exception";
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		std::string *name = (const_cast<std::string *>(&this->_name));

		// this->_isSigned = other.getIsSigned();
		*name = other.getName();
		this->_setSignGrade(other.getSignGrade());
		this->_setExecGrade(other.getExecGrade());
	}
	return *this;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecGrade() const
{
	return this->_execGrade;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_isSigned)
	{
		std::cout << "Form " << this->_name << " already signed" << std::endl;
		return;
	}
	try
	{
		if (bureaucrat.getGrade() > this->_signGrade)
			throw GradeTooLowException();
		this->_isSigned = true;
		std::cout << bureaucrat.getName() << " signed form " << this->_name << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << bureaucrat.getName() << " couldn't sign form " << this->_name << ": " << e.what() << std::endl;
	}
	
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName() << ":" << std::endl;
	if (form.getIsSigned())
		os << "Signed: yes" << std::endl;
	else
		os << "Signed: no" << std::endl;
	os << "Sign grade: " << form.getSignGrade() << std::endl;
	os << "Exec grade: " << form.getExecGrade() << std::endl;
	os << "-------------------------" << std::endl;
	return os;
}
