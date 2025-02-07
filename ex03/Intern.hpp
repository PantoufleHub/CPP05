#pragma once

#include <iostream>
#include "AForm.hpp"

// template <typename T> T *createForm(std::string, std::string);
// typedef struct forms
// {
// 	char	*name;
// 	AForm	*copy;
// } forms;

typedef struct s_form_dict
{
	std::string name;
	
} t_form_dict;

class Intern
{
	private:
		t_form_dict _knowledge;
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();

		Intern &operator=(const Intern &other);
		AForm *makeForm(std::string formName, std::string target) const;
};
