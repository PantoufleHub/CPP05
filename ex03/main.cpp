#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
	Intern someRandomIntern;
	Bureaucrat b1("Paul", 150);
	Bureaucrat b2("Shaggy", 1);

	AForm *rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm *rrf2 = someRandomIntern.makeForm("shrubbery creation", "shrubs");
	AForm *rrf3 = someRandomIntern.makeForm("presidential pardon", "Bob");
	AForm *rrf4 = someRandomIntern.makeForm("patati patata", "larry");
	std::cout << *rrf1;
	std::cout << *rrf2;
	std::cout << *rrf3;
	std::cout << *rrf4 << std::endl;

	rrf1->execute(b2);
	rrf2->execute(b2);
	rrf3->execute(b2);
	rrf4->execute(b2);
	return 0;
}