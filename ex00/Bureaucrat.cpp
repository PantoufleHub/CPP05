#include "Bureaucrat.hpp"

void Bureaucrat::_setGrade(int grade)
{
	try
	{
		if (grade < 1)
			this->_grade = 1, throw GradeTooHighException();
		if (grade > 150)
			this->_grade = 150, throw GradeTooLowException();
		this->_grade = grade;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat() : _name("Unknown bureaucrat")
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
	this->_setGrade(150);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	this->_setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->_setGrade(other.getGrade());
}

Bureaucrat::~Bureaucrat ()
{
	std::cout << "Default Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->_setGrade(other.getGrade());
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	this->_setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	this->_setGrade(this->_grade + 1);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat cannot have a grade higher than 1.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat cannot have a grade lower than 150.";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << "Bureaucrat: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade() << std::endl;
	return os;
}