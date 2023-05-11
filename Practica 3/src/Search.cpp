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

#include "Search.hpp"

int Search::getLineId(){
	return this->n_line;
}
		
int Search::getLinePosition(){
	return this->line_position;
}

Threads Search::getThread(){
	return this->t;
}

void Search::toString(){	
	std::cout << "[Hilo " << this->t.getThreadId() << " inicio:" << this->t.getBegin() << " -- final: " << this->t.getEnd() << "] :: línea " << this->n_line << " :: ... " << this->text << std::endl;
}

std::string Search::getString(){
	return "[Hilo " + std::to_string(this->t.getThreadId()) + " inicio:" + std::to_string(this->t.getBegin()) + " -- final: " + std::to_string(this->t.getEnd()) + "] :: línea " + std::to_string(this->n_line) + " :: ... " + this->text;
}