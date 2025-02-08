#pragma once

#include <iostream>
#include "AForm.hpp"

class InvalidForm : public AForm
{
	public:
		InvalidForm();
		InvalidForm(std::string target);
		InvalidForm(const InvalidForm &other);
		~InvalidForm();

		InvalidForm &operator=(const InvalidForm &other);

		void perfromAction(std::string target) const;
		AForm *create(std::string target) const;
};