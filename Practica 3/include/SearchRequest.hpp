/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   Proyect                 : Práctica 3 Sistemas Operativos II
 *
 *   Name of the program     : SearchRequest.hpp
 *
 *   Authors                 : Mario Serrano Romero / Alejandro Durán de la Morena
 *
 *   Creation Date           : 2/05/2023
 *
 *   Purpose                 : Definition of the class SearchRequest
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SEARCHREQUEST_HPP
#define SEARCHREQUEST_HPP

class SearchRequest{
    private:
        int client_id;
        int search_id;
        std::string word;
        int priority; //If it is 0 free client, if 1 premium clients (with and without balance)
    public:
        SearchRequest(int client_id, std::string word, int priority);
        int getClientId();
        int getSearchId();
        int getPriority();
        std::string getWord();
		void setRequestId();
		void toString();
};

#endif