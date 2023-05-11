/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : ReplySearch.hpp
*
*   Author              : Mario Serrano Romero / Alejandro Durán de la Morena
*
*   Creation date       : 9/05/2023
*
*   Purpose             : 
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef REPLYSEARCH_HPP
#define REPLYSEARCH_HPP

#include <vector>
#include <queue>
#include "Search.hpp"
#include "PriorityFunction.hpp"

class ReplySearch{
	private:
		int client_id;
	public:
		std::vector <std::priority_queue<Search, std::vector<Search>, PriorityFunction>> prio_q_vector;
		int getClientId();
		ReplySearch(int client_id, std::vector <std::priority_queue<Search, std::vector<Search>, PriorityFunction>> prio_q_vector);
};

#endif