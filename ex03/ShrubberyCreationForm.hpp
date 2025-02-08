#pragma once

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:


	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		void perfromAction(std::string target) const;
		AForm *create(std::string target) const;
};
