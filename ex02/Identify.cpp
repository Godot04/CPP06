/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:04:56 by opopov            #+#    #+#             */
/*   Updated: 2025/12/01 14:36:22 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base::~Base()
{
}

Base *generate(void)
{
	int n = (std::rand() % 3) + 1;
	switch (n)
	{
	case 1:
		return (new A);
	case 2:
		return (new B);
	case 3:
		return (new C);
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer: C" << std::endl;
	else
		std::cout << "Pointer: Error" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference: A" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference: B" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference: C" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	std::cout << "Reference: Error" << std::endl;
}
