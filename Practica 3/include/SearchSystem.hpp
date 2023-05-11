/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : SearchSystem.hpp
*
*   Authors             : Mario Serrano Romero / Alejandro Durán de la Morena
*
*   Creation Date       : 2/05/2023
*
*   Purpose             : 
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SEARCHSYSTEM_HPP
#define SEARCHSYSTEM_HPP

#include <vector>
#include <queue>
#include <string>
#include <thread>
#include "Client.hpp"
#include "Search.hpp"
#include "SearchRequest.hpp"
#include "PriorityFunction.hpp"
#include "FileManager.hpp"

class SearchSystem{
	public:
		std::vector <std::priority_queue<Search, std::vector<Search>, PriorityFunction>> prio_q_vector;
		Client getClient(int id);
		SearchRequest getRequest();
		void doPrioQVector();
		void doSearchBook(SearchRequest reuest);
		int doSearch(SearchRequest request, Client client, std::string text, int limit, std::priority_queue<Search, std::vector<Search>,PriorityFunction> &prio_q_pointer);
		void operator()();
};

#endif