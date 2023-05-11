/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : ReplySearchManager.hpp
*
*   Author              : Mario Serrano Romero / Alejandro Durán de la Morena
*
*   Creation date       : 9/05/2023 
*
*   Purpose             : Definition of the class ReplaySearchManager
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef REPLYSEARCHMANAGER_HPP
#define REPLYSEARCHMANAGER_HPP

#include <vector>
#include <mutex>
#include "ReplySearch.hpp"

class ReplySearchManager{
	private:
		std::vector <ReplySearch> v_reply_search;	/* Vector where the ReplySearchs are going to be stored */
		std::mutex sem_mtx;						
		
	public:
		ReplySearchManager();
		std::vector <ReplySearch> getVector();
		void insert(ReplySearch);
		bool findReply(int client_id);
		ReplySearch getReply(int client_id);
};

#endif