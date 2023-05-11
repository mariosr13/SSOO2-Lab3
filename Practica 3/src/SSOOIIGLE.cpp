/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : SSOOIIGLE.cpp
*
*   Author              : Mario Serrano Romero / Alejandro Duran de la Morena
*
*   Creation date       : 10/05/2023
*
*   Purpose             : Main file of the program where all is executed.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "SSOOIIGLE.hpp"
#include "GlobalVariables.hpp"

#include "SearchRequest.cpp"
#include "SearchRequestManager.cpp"
SearchRequestManager v_search_request;
#include "PayRequest.cpp"
std::queue<PayRequest> pay_queue;	
#include "FileManager.cpp"
#include "ReplySearch.cpp"
#include "ReplySearchManager.cpp"
ReplySearchManager v_reply_search;
#include "Client.cpp"
std::vector<Client> v_clients; 
#include "SearchSystem.cpp"
#include "PaySystem.cpp"		                

int main(){
	PaySystem pay_sys;
	std::cout << WHITE << "\nWelcome to SSOOIIGLE" << std::endl;
	installSignalHandler();
	errorManage();
	std::thread create_clients(createClients);
	create_clients.detach();
	createClientsDir();
	std::thread create_client_threads(createClientThreads);
	create_client_threads.detach();
	createSearchSystemThreads();
	std::thread thread_pay_system(pay_sys);	
	thread_pay_system.join();
	
	return EXIT_SUCCESS;
}

void createClients(){
	int rand_type, rand_word, rand_limit;
    srand(time(NULL));

	for(int i = 0; i < NUM_CLIENTS; i++){
		rand_type = rand() % 3;
		rand_word = 1 + rand()%(dictionary.size()-1);
		rand_limit = 1 + rand()%(MAX_LIMIT - 1);

		switch(rand_type){
			case 2:{
				Client client(i, rand_type, dictionary[rand_word], rand_limit);
				v_clients.push_back(client);		
				break;
			}
			case 1:{
				Client client(i, rand_type, rand_limit, dictionary[rand_word]);
				v_clients.push_back(client);
				break;
			}
			case 0:{
				Client client(i, rand_type, dictionary[rand_word]);
				v_clients.push_back(client);
				break;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void createClientThreads(){
	std::thread threads_clients[NUM_CLIENTS];

	for(int i = 0; i < v_clients.size();i++){
		threads_clients[i] = std::thread(v_clients[i], i);
		threads_clients[i].detach();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void createSearchSystemThreads(){
	SearchSystem s;
	std::thread threads_search_system[NUM_SEARCH];
	
	for(int i = 0; i < NUM_SEARCH; i++){
		threads_search_system[i] = std::thread(s);
		threads_search_system[i].detach();
	}
}

void createClientsDir(){
	if(v_clients[0].dirExists("Clients") == false){
		system("mkdir Clients");
	}else{
		system("rm -r Clients");
		system("mkdir Clients");
	}
}

bool wordsFileExists(){
	FILE *f;

	if( (f = fopen(WORDS_FILE, "r")) == NULL){
		return false;
	}else{
		return true;
	}
}

bool getWords(){
	std::vector<std::string> words_vector = openFile(WORDS_FILE);
	std::vector<std::string> words_split;

	if(words_vector[0].size() == 0){
		return true;
	}

	for(int i = 0; i < words_vector.size(); i++){
		words_split = split(words_vector[i]);
	
		for(int j = 0; j < words_split.size(); j++){
			dictionary.push_back(words_split[j]);
		}
	}

	return false;
}

void errorManage(){
	bool empty;

	if(!wordsFileExists()){
		std::cerr << RED << "The " << WORDS_FILE << " doesn't exists, please, create it " << std::endl;

		exit(-1);
	}
	
	empty = getWords();
	
	if(empty == true && books.size() == 0){
		std::cerr << RED << "The " << WORDS_FILE << " and the books array are empty, please, put some words on the " << WORDS_FILE << " and some books on the books array" << std::endl;
		std::cerr << RED << "Finishing the program..." << std::endl;

		exit(-1);
	}
	if(empty == true){
		std::cerr << RED << "The " << WORDS_FILE << " is empty, please, put some words on it " << std::endl;
		std::cerr << RED << "Finishing the program..." << std::endl;

		exit(-1);
	}else if(books.size() == 0){
		std::cerr << RED << "The books array is empty, please, put some books on it " << std::endl;
		std::cerr << RED << "Finishing the program..." << std::endl;

		exit(-1);
	}
}

void installSignalHandler(){
	if(signal(SIGINT,signalHandler) == SIG_ERR){
		std::cerr << RED << "\nError installing the signal handler" << std::endl;
	}
}

void signalHandler(int sig){
	std::cout << RED << "\nCtrl+c signal received" << std::endl;

	exit(EXIT_FAILURE);
}