/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : ReplySearchManager.cpp
*
*   Author              : Mario Serrano Romero / Alejandro Durán de la Morena
*
*   Creation date       : 10/05/2023 
*
*   Purpose             : 
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "ReplySearchManager.hpp"

ReplySearchManager::ReplySearchManager(){}

std::vector<ReplySearch> ReplySearchManager::getVector(){
	return v_reply_search;
}

/* Method that insert a reply search in the vector */
void ReplySearchManager::insert(ReplySearch request){
	std::lock_guard<std::mutex> lockk(sem_mtx);
	v_reply_search.push_back(request);
}

/* Method that return if the reply request exists */
bool ReplySearchManager::findReply(int client_id){
	bool flag = false;

	for(int i = 0; i < v_reply_search.size(); i++){
		if(v_reply_search[i].getClientId() == client_id){
			flag = true;
			break;
		}
	}

	return flag;
}

ReplySearch ReplySearchManager::getReply(int client_id){
	std::vector<std::priority_queue<Search, std::vector<Search>, PriorityFunction>> prio_q_vector;
	ReplySearch reply_search(-1, prio_q_vector);
	std::lock_guard<std::mutex> lock(sem_mtx);

	for(int i = 0; i < v_reply_search.size(); i++){
		if(v_reply_search[i].getClientId() == client_id){
			reply_search = v_reply_search[i];
			auto elem_to_remove = v_reply_search.begin() + i;

			if(elem_to_remove != v_reply_search.end()){
				v_reply_search.erase(elem_to_remove);
			}

			break;
		}
	}

	return reply_search;
}		