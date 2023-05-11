/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : PaySystem.cpp
*
*   Author              : Mario Serrano Romero / Alejandro Durán de la Morena
*
*   Creation date       : 10/05/2023 
*
*   Purpose             : 
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "PaySystem.hpp"

Client PaySystem::getClient(int id){
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

void PaySystem::operator()(){
	while(1){
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::unique_lock<std::mutex> lock_queue(sem_pay_sys);
		wait_pay.wait(lock_queue, [] {return (pay_queue.empty() == false);});
		Client client = getClient(pay_queue.front().client_id);
		
		try{
			pay_queue.front().client_promise.set_value(client.getBalanceClient());
		}catch(std::exception e){
			std::cerr << "Error while waiting for the new balance... " << std::endl;
		}
				
		std::cout << CYAN << "\n------------------------------------- PAY SYSTEM -------------------------------------" << std::endl;
		std::cout << CYAN << "The PaymentRequest of client with ID " << client.getClientId() << " has been completed." << std::endl;
		std::cout << CYAN << "--------------------------------------------------------------------------------------" << std::endl;
	}
}