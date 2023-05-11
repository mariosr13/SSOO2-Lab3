/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : ReplySearch.cpp
*
*   Author              : Mario Serrano Romero / Alejandro Durán de la Morena
*
*   Creation date       : 10/05/2023
*
*   Purpose             : 
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "ReplySearch.hpp"

int ReplySearch::getClientId(){
	return client_id;
}

ReplySearch::ReplySearch(int client_id, std::vector <std::priority_queue<Search, std::vector<Search>, PriorityFunction>> prio_q_vector){
	this->client_id = client_id;
	this->prio_q_vector = prio_q_vector;
}