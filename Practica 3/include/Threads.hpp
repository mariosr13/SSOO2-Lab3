/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : Thread.hpp
*
*   Author              : Mario Serrano Romero / Alejandro Duran de la Morena
*
*   Creation date       : 9/05/2023
*
*   Purpose             : Class definition to safe the information about threads
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef THREADS_HPP
#define THREADS_HPP

#include <iostream>
#include <stdlib.h>

class Threads{
	private:
		int thread_id;
		int begin;
		int end;

	public:
		Threads(int thread_id, int begin, int end);
		int getThreadId();
		int getBegin();
		int getEnd();
		void toString();
};

#endif