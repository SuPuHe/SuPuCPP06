/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:52:40 by omizin            #+#    #+#             */
/*   Updated: 2025/12/10 16:40:50 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {};

Base*	generate(void)
{
	int num = rand() % 3;
	if (num == 1)
	{
		std::cout << GREEN << "Class A generated" << RESET << std::endl;
		return new A;
	}
	if (num == 2)
	{
		std::cout << CYAN << "Class B generated" << RESET << std::endl;
		return new B;
	}
	else
	{
		std::cout << MAGENTA << "Class C generated" << RESET << std::endl;
		return new C;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "This is class A identify by pointer" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << CYAN << "This is class B identify by pointer" << RESET << std::endl;
	else
		std::cout << MAGENTA << "This is class C identify by pointer" << RESET << std::endl;
}

void	identify(Base& p)
{
	Base tmp;
	try{
		tmp = dynamic_cast<A&>(p);
		std::cout << GREEN << "This is class A identify by ref" << RESET << std::endl;
		return;
	} catch(...) {}

	try{
		tmp = dynamic_cast<B&>(p);
		std::cout << CYAN << "This is class B identify by ref" << RESET << std::endl;
		return;
	} catch(...) {}

	try{
		tmp = dynamic_cast<C&>(p);
		std::cout << MAGENTA << "This is class C identify by ref" << RESET << std::endl;
		return;
	} catch(...) {}
}
