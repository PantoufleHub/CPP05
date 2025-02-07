#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	ShrubberyCreationForm s1;
	ShrubberyCreationForm s2("boo");
	ShrubberyCreationForm s3;
	RobotomyRequestForm r1;
	RobotomyRequestForm r2("Zibu");
	RobotomyRequestForm r3(r2);
	PresidentialPardonForm p1;
	PresidentialPardonForm p2("Gnocchi");
	PresidentialPardonForm p3(p2);
	Bureaucrat b1("Patrick", 150);
	Bureaucrat b2("Bob", 1);
	std::cout << std::endl;

	std::cout << s2;
	std::cout << r2;
	std::cout << p2;
	std::cout << std::endl;

	s2.execute(b1);
	r2.execute(b1);
	p2.execute(b1);
	std::cout << std::endl;

	s2.execute(b2);
	r2.execute(b2);
	p2.execute(b2);
	std::cout << std::endl;

	return 0;
}