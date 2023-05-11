/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   Project                 : Práctica 3 Sistemas Operativos II
 *
 *   Name of the program     : Client.cpp
 *
 *   Authors                 : Mario Serrano Romero / Alejandro Durán de la Morena
 *
 *   Creation Date           : 17/04/2023
 *
 *   Purpose                 : Implemantation of the client class.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Client.hpp"

// Constructor of the premium client:
Client::Client(int id_client, int type_client, std::string word_client)
{
    this->id_client = id_client;
    this->type_client = type_client;
    this->word_client = word_client;
    this->limit_client = -1;
}

// Constructor of the premium client with a limited balance:
Client::Client(int id_client, int type_client, std::string word_client, int balance_client)
{
    this->id_client = id_client;
    this->type_client = type_client;
    this->word_client = word_client;
    this->balance_client = balance_client;
    this->limit_client = balance_client;
}

// Constructor of the free client:
Client::Client(int id_client, int type_client, int limit_client, std::string word_client)
{
    this->id_client = id_client;
    this->type_client = type_client;
    this->word_client = word_client;
    this->limit_client = limit_client;
}

std::string Client::getWordClient(){
    return word_client;
}

int Client::getTypeClient(){
    return type_client;
}

int Client::getClientId(){
    return id_client;
}

int Client::getBalanceClient(){
    return balance_client;
}

int Client::getLimitClient(){
    return limit_client;
}

void Client::toString(){
    switch(type_client){
        case 0:
            std::cout << "Client with id " << getClientId() + 1 << ", type PREMIUM have word " << getWordClient() << " has been created." << std::endl;   
        break;
        
        case 1:
            std::cout << "Client with id " << getClientId() + 1 << ", type PREMIUM WITH BALANCE, word " << getWordClient() << " and first balance " << getLimitClient() << " has been created." << std::endl;
        break;

        case 2:
            std::cout << "Client with id " << getClientId() + 1 << ", type FREE, word " << getWordClient() << " and limit " << getLimitClient() << " has been created." << std::endl;
        break;
    }
}

void Client::setLimit(int limit){
	this->limit_client = limit;
}

SearchRequest Client::doSearchRequest(){
	SearchRequest search_request (-1, "", -1);

	if(type_client == 2){
		SearchRequest aux_sr(id_client, getWordClient(), 0);
		search_request = aux_sr;
	}else{
		SearchRequest aux_sr(id_client, getWordClient(), 1);
		search_request = aux_sr;
	}
	search_request.setRequestId();

	return search_request;
}

void Client::createFiles(ReplySearch replay_search){
	std::string title;
	char client_direction[30];

	std::sprintf(client_direction, "mkdir ./Clients/client_%d", getClientId() + 1);
	system(client_direction);
    
	for(int i = 0; i < NBooks; i++){
		std::ofstream file;
		file.open("./Clients/client_" + std::to_string(getClientId() + 1) + "/Results_" + books[i].substr(9, 50), std::ios::out);

		if(file.fail()){
			std::cerr << RED << "Can't open the file\n" << std::endl;
			exit(EXIT_FAILURE);
		}

		title = "----------------------- RESULTS IN THE TEXT SEARCHING THE WORD " + getWordClient() + " IN THE TEXT -----------------------\n";
		file << title;

		while(replay_search.prio_q_vector[i].empty() == false){
			Search search = replay_search.prio_q_vector[i].top();
			replay_search.prio_q_vector[i].pop();
			file << search.getString() + "\n";
		}

		file.close();
	}
}

bool Client::dirExists(std::string dir){
	DIR * directory;
	if(directory = opendir(dir.c_str())){
		closedir(directory);
		return true;
	}

	return false;
}

// Show when a clients starts and finish a seach.
int Client::operator()(int number){
	std::cout << WHITE << "\n---------------------------------- CLIENT WITH ID " << id_client << " -----------------------------------" << std::endl;
	toString();
	std::cout << WHITE << " has been created." << std::endl;
	std::cout << WHITE << "--------------------------------------------------------------------------------------" << std::endl;
	
	const int id = id_client;
	SearchRequest search_request = doSearchRequest();
	v_search_request.insert(search_request);

	// When the SearchRequest is in the vector, notify the wait_search condition variable to unlock a SearchSystem 
	wait_search.notify_one();		
	std::unique_lock<std::mutex> lock_client(sem_client);
	// It will be blocked if the v_reply_search is empty and if this vector doesn't have a SearchReply with the id of the client
	wait_client.wait(lock_client, [id] {return (v_reply_search.getVector().empty() == false && v_reply_search.findReply(id) == true);});
	ReplySearch reply_search = v_reply_search.getReply(id);
	createFiles(reply_search);
			
	std::cout << GREEN << "---------------------------------- CLIENT WITH ID " << id_client << " ------------------------------------" << std::endl;
	std::cout << GREEN << "The client with ID " << id_client << " has finished and his results has stored on his folder." << std::endl;
	std::cout << GREEN << "--------------------------------------------------------------------------------------" << std::endl;
			
	return EXIT_SUCCESS;
}
