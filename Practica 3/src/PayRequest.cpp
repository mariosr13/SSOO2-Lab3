/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   Proyect                 : Práctica 3 Sistemas Operativos II
 *
 *   Name of the program     : PayRequest.cpp
 *
 *   Authors                 : Mario Serrano Romero / Alejandro Durán de la Morena
 *
 *   Creation Date           : 2/05/2023
 *
 *   Purpose                 : Implementation of the pay request class
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <future>

class PayRequest{
    public:
        int client_id;
        std::promise<int> client_promise;
        std::future<int> client_future;

        PayRequest(int id): client_id(id){
            client_future = client_promise.get_future();
        }
};