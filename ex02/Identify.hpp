/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:04:47 by opopov            #+#    #+#             */
/*   Updated: 2025/12/01 14:28:39 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include <iostream>
# include <ctime>
# include <stdlib.h>
# include <time.h>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

# endif
