#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b1;
	Bureaucrat b2("Patrick", 1);
	Bureaucrat b3("Bob", 1222);
	Bureaucrat b4(b3);
	std::cout << std::endl;
	
	std::cout << b1;
	std::cout << b2;
	std::cout << b3;
	std::cout << b4;
	std::cout << std::endl;

	b1.incrementGrade();
	b1.decrementGrade();
	b4.incrementGrade();
	b4.decrementGrade();
	b4.decrementGrade();
	std::cout << std::endl;

	std::cout << b1;
	std::cout << b2;
	std::cout << b3;
	std::cout << b4;

	return 0;
}