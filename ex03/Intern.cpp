#include "Intern.hpp"

Intern::Intern()
{
	// std::cout << "Default Intern constructor called" << std::endl;
	_knowledge[0].name = "presidential pardon";
	_knowledge[0].form = new PresidentialPardonForm();
	_knowledge[1].name = "robotomy request";
	_knowledge[1].form = new RobotomyRequestForm();
	_knowledge[2].name = "shrubbery creation";
	_knowledge[2].form = new ShrubberyCreationForm();
}

Intern::Intern(const Intern &other)
{
	(void)other;
	// std::cout << "Intern copy constructor called" << std::endl;
	_knowledge[0].name = "presidential pardon";
	_knowledge[0].form = new PresidentialPardonForm();
	_knowledge[1].name = "robotomy request";
	_knowledge[1].form = new RobotomyRequestForm();
	_knowledge[2].name = "shrubbery creation";
	_knowledge[2].form = new ShrubberyCreationForm();
}

Intern::~Intern ()
{
	// std::cout << "Default Intern destructor called" << std::endl;
	for (int i = 0; i < 3; i++)
		delete(_knowledge[i].form);
}

AForm *Intern::makeForm(std::string name, std::string target) const
{
	for (int i = 0; i < 3; i++)
	{
		if (name == _knowledge[i].name)
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			return _knowledge[i].form->create(target);
		}
	}
	std::cout << "Intern couldn't find " << name << " form" << std::endl;
	return new InvalidForm();
}

Intern &Intern::operator=(const Intern &other)
{
	// nothing to do
	(void)other;
	return *this;
}
