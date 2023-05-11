/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : 
*
*   Author              : Mario Serrano Romero/Alejandro Duran de la Morena
*
*   Creation date       : 9/05/2023
*
*   Purpose             : 
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <iostream>
#include <stdlib.h>
#include "Threads.hpp"


class Search{	
	private:
		int n_line;
		std::string text;
		int line_position;
		Threads t;
	public:
		Search(int line_id, std::string text, int line_position, Threads t):n_line{n_line}, text{text}, line_position{line_position}, t{t}{}
		int getLineId();
		int getLinePosition();
		Threads getThread();
		void toString();
		std::string getString();
};

#endif