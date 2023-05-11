/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project                 : Práctica 3 Sistemas Operativos II
*
*   Name of the program     : SearchRequest.cpp
*
*   Authors                 : Mario Serrano Romero / Alejandro Durán de la Morena
*
*   Creation Date           : 2/05/2023
*
*   Purpose                 : Implementation of the search request class
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "SearchRequest.hpp"

SearchRequest::SearchRequest(int client_id, std::string word, int priority){
	this->client_id = client_id;
	this->word = word;
	this->priority = priority;
}

int SearchRequest::getClientId(){
	return client_id;
}

int SearchRequest::getSearchId(){
	return search_id;
}

int SearchRequest::getPriority(){
	return priority;
}

std::string SearchRequest::getWord(){
    return word;
}

void SearchRequest::setRequestId(){
	this->search_id = request_id;
	request_id++;
}
    
void SearchRequest::toString(){
	std::cout << "SearchRequest: client id " << client_id << ", search id " << search_id << ", searched word " << word << " and priority " << priority;
}