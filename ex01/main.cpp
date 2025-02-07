#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	Form f1;
	Form f2("Cool form", 60, 20);
	Form f3("Contract", -1, 200);
	Form f4(f3);
	std::cout << std::endl;

	std::cout << f1;
	std::cout << f2;
	std::cout << f3;
	std::cout << f4;
	std::cout << std::endl;

	std::cout << b1;
	b1.incrementGrade();
	std::cout << b1;
	b1.decrementGrade();
	std::cout << b1;
	b1.decrementGrade();
	std::cout << b2;
	b2.incrementGrade();
	std::cout << std::endl;

	b2.signForm(f2);
	b2.signForm(f2);
	b4.signForm(f3);
	std::cout << std::endl;

	std::cout << b1;
	std::cout << b2;
	std::cout << b3;
	std::cout << b4;
	std::cout << std::endl;

	return 0;
}