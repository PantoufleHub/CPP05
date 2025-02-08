#include "InvalidForm.hpp"

InvalidForm::InvalidForm() : AForm("Invalid form", 150, 150, "")
{
	// std::cout << "Default InvalidForm constructor called" << std::endl;
}

InvalidForm::InvalidForm(std::string target) : AForm("Invalid form", 150, 150, target)
{
	// std::cout << "InvalidForm constructor called" << std::endl;
}

InvalidForm::InvalidForm(const InvalidForm &other) : AForm("Invalid form", 150, 150, other.getTarget())
{
	// std::cout << "InvalidForm copy constructor called" << std::endl;
}

InvalidForm::~InvalidForm ()
{
	// std::cout << "Default InvalidForm destructor called" << std::endl;
}

void InvalidForm::perfromAction(std::string target) const
{
	(void)target;
	std::cout << "Invalid form did absolutely nothing" << std::endl;
}

AForm *InvalidForm::create(std::string target) const
{
	return (AForm *)(new InvalidForm(target));
}

InvalidForm &InvalidForm::operator=(const InvalidForm &other)
{
	(void)other;
	return *this;
}
