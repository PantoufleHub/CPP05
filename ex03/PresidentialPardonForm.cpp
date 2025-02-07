#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential pardon form", 25, 5, "")
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential pardon form", 25, 5, target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("Presidential pardon form", 72, 45, other.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm ()
{
	std::cout << "Default PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::perfromAction(std::string target) const
{
	std::cout << target << " has been pardoned by Zaphrod Beeblebrox." << std::endl;
}

PresidentialPardonForm *PresidentialPardonForm::create(std::string target) const
{
	return (new PresidentialPardonForm(target));
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return *this;
}
