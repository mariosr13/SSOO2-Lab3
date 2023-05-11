/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : SearchSystem.cpp
*
*   Authors             : Mario Serrano Romero / Alejandro Durán de la Morena
*
*   Creation Date       : 9/05/2023
*
*   Purpose             : Implementation of the class search system
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "SearchSystem.hpp"

Client SearchSystem::getClient(int id){
	bool find = false;
	Client client(0, 1, "");

	for(int i = 0; i < v_clients.size() && !find; i++){
		if(v_clients[i].getClientId() == id){
			Client client = v_clients[i];
			find = true;
			
			return client;
		}
	}

	return client;
}

// Method that returns the SearchRequest acording to the relation 80% (PRIME OF BOTH TYPES), 20% (FREE)
SearchRequest SearchSystem::getRequest(){
	int position = 0;
	srand(time(NULL));
	SearchRequest search_request(-1,"",-1);

	if(v_search_request.areAllSame() == true){
		SearchRequest aux_sr = v_search_request.getFront();
		search_request = aux_sr;
		v_search_request.pop();
	}else{
		int random_number = 1 + rand()%(11-1);

		if(random_number <= 8){
			position = v_search_request.getLimitedRequestPos();
			SearchRequest aux_sr = v_search_request.getRequest(position);
			search_request = aux_sr;
		}else{
			position = v_search_request.getFreeRequestPos();
			SearchRequest aux_sr = v_search_request.getRequest(position);
			search_request = aux_sr;
		}
		v_search_request.deleteRequest(position);		
	}

	return search_request;
}

void SearchSystem::doPrioQVector(){
	std::priority_queue<Search, std::vector<Search>, PriorityFunction> pq;

	for(int i = 0; i < NBooks; i++){
		prio_q_vector.push_back(pq);
	}
}

void SearchSystem::doSearchBook(SearchRequest request){
	Client client = getClient(request.getClientId());
	int limit = client.getLimitClient();
				
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	for(int i = 0; i < NBooks; i++){
		limit = doSearch(request, client, books[i], limit, std::ref(prio_q_vector[i]));
	}
}

int SearchSystem::doSearch(SearchRequest request, Client client, std::string text, int limit, std::priority_queue<Search, std::vector<Search>,PriorityFunction> &prio_q_pointer){
	std::priority_queue<Search, std::vector<Search>,PriorityFunction> aux_prio_q;
	int limit_aux = limit;
	std::vector<std::string> arrayLine;
	arrayLine = openFile(text);

	if(arrayLine.size() != 0){				
		arrayLine.erase(arrayLine.end());
    }

	for(int i = 0; i < arrayLine.size(); i++){
		aux_prio_q = findWord(split(arrayLine[i]), request.getWord(), i, 1, 0, arrayLine.size(), aux_prio_q);
	}
	
	while(limit_aux != 0 && aux_prio_q.size() > 0){
		limit_aux--;
		Search search = aux_prio_q.top();
		aux_prio_q.pop();
		prio_q_pointer.push(search);
        
		if(limit_aux == 0 && client.getTypeClient() == 2){
			std::cout << CYAN << "\n------------------------------------ SEARCH SYSTEM -----------------------------------" << std::endl;
			std::cout << CYAN << "FREE CLIENT WITH ID " << client.getClientId() << " WITHOUT SEARCH." << std::endl;
			std::cout << CYAN << "--------------------------------------------------------------------------------------" << std::endl;
		}else if(limit_aux == 0 && client.getTypeClient()  == 1){
			std::cout << CYAN << "\n------------------------------------ SEARCH SYSTEM -----------------------------------" << std::endl;
			std::cout << CYAN << "PREMIUM WITH BALANCE CLIENT WITH ID " << client.getClientId() << " WITHOUT BALANCE." << std::endl;
			std::cout << CYAN << "--------------------------------------------------------------------------------------" << std::endl;

			PayRequest r(client.getClientId());
			std::lock_guard<std::mutex> lk(sem_pay_req);
			pay_queue.push(std::move(r));
			wait_pay.notify_one();
			limit_aux = pay_queue.front().client_future.get();
			pay_queue.pop();
			wait_pay.notify_all();					
		}
	}

	return limit_aux;
}

// Method that will block if the queue is emty, and when completed a reply is created and inserted in a vector.
void SearchSystem::operator()(){
	while(1){
		doPrioQVector();
		std::unique_lock<std::mutex> lock_queue(sem_search_sys);

		wait_search.wait(lock_queue, [] {return (v_search_request.getVector().size() != 0);});	
		lock_queue.unlock();
		sem_search_req.lock();
		SearchRequest search_request = getRequest();
		sem_search_req.unlock();

		std::cout << CYAN << "\n------------------------------------ SEARCH SYSTEM -----------------------------------" << std::endl;
		std::cout << CYAN "Searching the word " << search_request.getWord() << " in the books for the client with id " << search_request.getClientId() << std::endl;
		std::cout << CYAN << "--------------------------------------------------------------------------------------" << std::endl;

		doSearchBook(search_request);
				
		std::cout << CYAN << "\n------------------------------------ SEARCH SYSTEM -----------------------------------" << std::endl;
		std::cout << CYAN <<"The search request of the client with id " << search_request.getClientId() << " has finished, the results will be stored." << std::endl;
		std::cout << CYAN << "--------------------------------------------------------------------------------------" << std::endl;
					
		ReplySearch reply_search(search_request.getClientId(), prio_q_vector);
		v_reply_search.insert(reply_search);
		wait_client.notify_all();
		wait_search.notify_one();
	}	
}
