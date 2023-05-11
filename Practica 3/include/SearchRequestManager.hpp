/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : SearchRequestManager.hpp
*
*   Author              : Mario Serrano Romero / Alejandro Duran de la Morena
*
*   Creation date       : 9/05/2023
*
*   Purpose             : 
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SEARCHREQUESTMANAGER_HPP
#define SEARCHREQUESTMANAGER_HPP

#include <vector>
#include <mutex>
#include "SearchRequest.hpp"

class SearchRequestManager {
	private:
		std::vector <SearchRequest> v_request;	/* Vector where the SearchRequest are going to be stored */
		std::mutex sem_mtx;

	public:
		SearchRequestManager();
		std::vector <SearchRequest> getVector();
		SearchRequest getRequest(int position);
		void deleteRequest(int position);
		int getFreeRequestPos();
		int getLimitedRequestPos();
		void pop();
		SearchRequest getFront();
		void insert(SearchRequest request);
		bool findRequest(int client_id);
		bool areAllSame();
};

#endif