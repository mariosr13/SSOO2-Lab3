/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : Threads.cpp
*
*   Author              : Mario Serrano Romero / Alejandro Duran de la Morena
*
*   Creation date       : 9/05/2023
*
*   Purpose             : Implementation of the class to safe the information about threads
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Threads.hpp"

Threads::Threads(int thread_id, int begin, int end){
	this->thread_id = thread_id;
	this->begin = begin;
	this->end = end;
}

int Threads::getThreadId(){
	return this->thread_id;
}

int Threads::getBegin(){
	return this->begin;
}

int Threads::getEnd(){
	return this->end;
}

void Threads::toString(){
	std::cout << "[Hilo " << this->thread_id << " inicio:" << this->begin << " -- final: " << this->end << std::endl;
}