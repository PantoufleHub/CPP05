#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <unistd.h>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy request form", 72, 45, "")
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request form", 72, 45, target)
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("Robotomy request form", 72, 45, other.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm ()
{
	std::cout << "Default RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::perfromAction(std::string target) const
{
	for (int i = 0; i < 3; i ++)
	{
		std::cout << "* Drilling noises *" << std::endl;
		sleep(1);
	}
	srand(static_cast<unsigned int>(time(NULL)));
	int rnd = rand() % 2;
	if (rnd == 1)
		std::cout << target << " has successfully been robotomized!" << std::endl;
	else
		std::cout << target << " has NOT successfully been robotomized." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return *this;
}
