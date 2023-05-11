/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : PriorityFunction.cpp
*
*   Author              : Mario Serrano Romero/Alejandro Duran de la Morena
*
*   Creation date       : 9/05/2023
*
*   Purpose             : Class that is going to be used to support the PriorityFunction.cpp
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PRIORITYFUNCTION_HPP
#define PRIORITYFUNCTION_HPP

#include <iostream>
#include <stdlib.h>
#include "Search.hpp"

class PriorityFunction{
	public: 
		int operator() (Search &a,Search &b);
};

#endif