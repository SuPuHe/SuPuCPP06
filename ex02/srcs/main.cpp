/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:52:32 by omizin            #+#    #+#             */
/*   Updated: 2025/12/10 16:41:18 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main()
{
	srand(time(NULL));

	std::cout << "=== Test 1: indentify random class ===\n";
	Base *ptr;
	for (int i = 0; i < 10; i++)
	{
		ptr = generate();
		identify(*ptr);
		identify(ptr);
		std::cout << std::endl;
		delete ptr;
	}
	std::cout << "=== Test 2: indentify manual class creation ===\n";
	Base* a = new A;
	Base* b = new B;
	Base* c = new C;

	std::cout << "A*: ";
	identify(a);
	std::cout << "A&: ";
	identify(*a);

	std::cout << "B*: ";
	identify(b);
	std::cout << "B&: ";
	identify(*b);

	std::cout << "C*: ";
	identify(c);
	std::cout << "C&: ";
	identify(*c);

	delete a;
	delete b;
	delete c;
}
