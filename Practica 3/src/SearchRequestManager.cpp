/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : SearchRequestManager.cpp
*
*   Author              : Mario Serrano Romero / Alejandro Duran de la Morena
*
*   Creation date       : 10/05/2023
*
*   Purpose             : 
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "SearchRequestManager.hpp"

SearchRequestManager::SearchRequestManager(){}

std::vector <SearchRequest> SearchRequestManager::getVector(){
	return v_request;
}

SearchRequest SearchRequestManager::getRequest(int position){
	SearchRequest search_request = v_request[position];

	return search_request;
}

void SearchRequestManager::deleteRequest(int position){
	SearchRequest request(-1,"",0);
	std::lock_guard<std::mutex> lockk(sem_mtx);
    
	for(int i = 0; i < v_request.size(); i++){
		if(i == position){
			request = v_request[i];
			auto elem_to_remove = v_request.begin() + i;

			if(elem_to_remove != v_request.end()){
				v_request.erase(elem_to_remove);
				wait_search.notify_all();
			}

			break;
		}
	}
}

int SearchRequestManager::getFreeRequestPos(){
	int position = 0;

	for(int i = 0; i < v_request.size();i++){
		if(v_request[i].getPriority() == 0){
			position = i;

			break;	
        }
	}
	
	return position;
}

int SearchRequestManager::getLimitedRequestPos(){
	int position = 0;

	for(int i = 0; i < v_request.size();i++){
		if(v_request[i].getPriority() == 1){
			position = i;

			break;	
        }
	}
	
	return position;
}

/* Method that remove the first SearchRequest of the Request_vector */
void SearchRequestManager::pop(){
	std::lock_guard<std::mutex> lock(sem_mtx);

	for(int i = 0; i < v_request.size(); i++){
		if(i == 0){
			while(i < v_request.size()-1){
				v_request[i] = v_request[i+1];
				i++;
			}

		    wait_search.notify_all();
		    break;
		}	
	}

	v_request.erase(v_request.end());
}

/* Method that return the first SearchRequest of the Request_vector */
SearchRequest SearchRequestManager::getFront(){
	std::lock_guard<std::mutex> lock(sem_mtx);

	SearchRequest request = v_request[0];

	return request;
}

/* Method that insert a SearchRequest in the request_vector */
void SearchRequestManager::insert(SearchRequest r){
	std::lock_guard<std::mutex> lock(sem_mtx);
	v_request.push_back(r);
}

/* Method that return true if there is a SearchRequest */
bool SearchRequestManager::findRequest(int client_id){
	bool flag = false;

	for(int i = 0; i < v_request.size(); i++){
		if(v_request[i].getClientId() == client_id){
			flag = true;

			break;
		}
	}

	return flag;
}

/* Method that return true if all the SearchRequests has the same priority */
bool SearchRequestManager::areAllSame(){
	bool same_type = false;
	int counter = 0;
	std::lock_guard<std::mutex> lock(sem_mtx);

	for(int i = 0; i < v_request.size(); i++){
		counter += v_request[i].getPriority();
	}

	if(counter == 0 || counter == v_request.size()){
		same_type = true;
    }
	
    return same_type;
}