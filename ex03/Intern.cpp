#include "Intern.hpp"

// test

// template <typename T> T *createForm(std::string, )
// {

// }

// intern.makeform(name target);


// ---

Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	if (&other == &other)
		std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern ()
{
	std::cout << "Default Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
		std::cout << "Pouet pouet" << std::endl;
	return *this;
}
