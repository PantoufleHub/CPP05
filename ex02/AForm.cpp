#include "AForm.hpp"

AForm::AForm() : _name("Unknown form"), _isSigned(false), _signGrade(150), _execGrade(150), _target("")
{
	std::cout << "Default Form constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade, std::string target) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade), _target(target)
{
	std::cout << "Form constructor called" << std::endl;
	_setSignGrade(signGrade);
	_setExecGrade(execGrade);
}

AForm::AForm(const AForm &other) : _name(other.getName()), _isSigned(false), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade()), _target(other.getTarget())
{
	std::cout << "Form copy constructor called" << std::endl;
}

AForm::~AForm ()
{
	std::cout << "Default Form destructor called" << std::endl;
}

void AForm::_setSignGrade(int grade)
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

void AForm::_setExecGrade(int grade)
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

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high exception";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low exception";
}

AForm &AForm::operator=(const AForm &other)
{
	// std::cout << "form = operator" << std::endl;
	if (this != &other)
	{
		std::string *name = (const_cast<std::string *>(&this->_name));
		std::string *target = (const_cast<std::string *>(&this->_target));

		// this->_isSigned = other.getIsSigned();
		*name = other.getName();
		*target = other.getTarget();
		this->_setSignGrade(other.getSignGrade());
		this->_setExecGrade(other.getExecGrade());
	}
	return *this;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecGrade() const
{
	return this->_execGrade;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

std::string AForm::getTarget() const
{
	return this->_target;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
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

void AForm::execute(const Bureaucrat &executor) const
{
	try
	{
		if(executor.getGrade() > this->_execGrade)
			throw GradeTooLowException();
		this->perfromAction(this->_target);
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " couldn't execute form " << this->_name << ": " << e.what() << std::endl;
	}
	
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form: " << form.getName() << ":" << std::endl;
	if (form.getIsSigned())
		os << "Signed: yes" << std::endl;
	else
		os << "Signed: no" << std::endl;
	os << "Sign grade: " << form.getSignGrade() << std::endl;
	os << "Exec grade: " << form.getExecGrade() << std::endl;
	os << "-------------------------" << std::endl;
	return os;
}
