/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : Search.hpp
*
*   Author              : Mario Serrano Romero/Alejandro Duran de la Morena
*
*   Creation date       : 9/05/2023
*
*   Purpose             : Definition of the class search
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
		Search(int n_line, std::string text, int line_position, Threads t):n_line{n_line}, text{text}, line_position{line_position}, t{t}{}
		int getNLine();
		int getLinePosition();
		Threads getThread();
		void toString();
		std::string getString();
};

#endif