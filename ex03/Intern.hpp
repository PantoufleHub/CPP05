#pragma once

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "InvalidForm.hpp"


typedef struct forms
{
	std::string name;
	AForm		*form;
} forms;

class Intern
{
	private:
		forms _knowledge[3];
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();

		Intern &operator=(const Intern &other);
		AForm *makeForm(std::string formName, std::string target) const;
};
