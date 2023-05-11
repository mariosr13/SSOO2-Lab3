/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : PaySystem.hpp
*
*   Author              : Mario Serrano Romero / Alejandro Durán de la Morena
*
*   Creation date       : 9/05/2023
*
*   Purpose             : 
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PAYSYSTEM_HPP
#define PAYSYSTEM_HPP

#include "Client.hpp"
#include <thread>

class PaySystem{
	public:
		Client getClient(int id);
		void operator()();
};

#endif