/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : PriorityFunction.cpp
*
*   Author              : Mario Serrano Romero/Alejandro Duran de la Morena
*
*   Creation date       : 9/05/2023
*
*   Purpose             : Class that is going to be used to order the priority queue.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <stdlib.h>
#include "PriorityFunction.hpp"

// Method that return the search with the most priority.
int PriorityFunction::operator() (Search &a,Search &b){
	if(a.getThread().getThreadId() == b.getThread().getThreadId()){     	
		if(a.getNLine() == b.getNLine()){				
			return a.getLinePosition() > b.getLinePosition();		
        }else{
			return a.getNLine() > b.getNLine();			
        }
	}
	
    return a.getThread().getThreadId() > b.getThread().getThreadId();
}