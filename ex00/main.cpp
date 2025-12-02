/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:51:23 by opopov            #+#    #+#             */
/*   Updated: 2025/11/27 13:48:12 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Incorrect input" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
