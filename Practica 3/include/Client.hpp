/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project                 : Práctica 3 Sistemas Operativos II
*
*   Name of the program     : Client.hpp
*
*   Authors                 : Mario Serrano Romero / Alejandro Durán de la Morena
*
*   Creation Date           : 17/04/2023
*
*   Purpose                 : Definition of the class client.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>
#include "SearchRequest.hpp"
#include "ReplySearch.hpp"

#define PREMIUM 0
#define LIMITED 1
#define FREE 2    

class Client{
    private:
        int id_client;
        int type_client;
        int limit_client;
        int balance_client;
        std::string word_client;
        
    public:
        // Constructor of the premium client:
        Client(int id_client, int type_client, std::string word_client);
        // Constructor of the premium client with a limited balance:
        Client(int id_client, int type_client, std::string word_client, int balance_client);
        // Constructor of the free client:
        Client(int id_client, int type_client, int limit_client, std::string word_client);

        std::string getWordClient();
        int getTypeClient();
        int getClientId();
        int getBalanceClient();
        int getLimitClient();
        void toString();
        void setLimit(int limit);
		SearchRequest doSearchRequest();
        void createFiles(ReplySearch replay_search);
		bool dirExists(std::string dir);
		int operator()(int number);
};

#endif