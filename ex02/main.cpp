/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:04:14 by opopov            #+#    #+#             */
/*   Updated: 2025/12/01 14:27:38 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main()
{
	srand(time(NULL));
	Base *p = generate();
	Base &r = *p;
	identify(p);
	identify(r);
	delete p;
	return (0);
}
