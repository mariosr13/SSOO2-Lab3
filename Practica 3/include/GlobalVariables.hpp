/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   Proyect                 : Práctica 3 Sistemas Operativos II
 *
 *   Name of the program     : GlobalVariables.hpp
 *
 *   Authors                 : Mario Serrano Romero / Alejandro Durán de la Morena
 *
 *   Creation Date           : 2/05/2023
 *
 *   Purpose                 : Store and define all important global variables.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <vector>
#include <mutex>
#include <string>
#include <condition_variable> 
#include <atomic>

// Definition of the colors ->
#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"

#define NUM_CLIENTS 10          // Maximun number of clients
#define MAX_LIMIT   50          // Max balance for the free and prime clients 
#define NUM_SEARCH  4           // Number of searchers
#define WORDS_FILE "words.txt"	// Name of the file where we have the words to shearch

std::vector<std::string> dictionary = {}; // Vector where words are introduced to be searched

// The books where the words will be searched ->
std::vector<std::string> books = {"./Libros/17-LEYES-DEL-TRABJO-EN-EQUIPO.txt", "./Libros/21-LEYES-DEL-LIDERAZGO.txt", 
"./Libros/VIVE-TU-SUEÑO.txt", "./Libros/El-oro-y-la-ceniza.txt", "./Libros/25-MANERAS-DE-GANARSE-A-LA-GENTE.txt", 
"./Libros/ACTITUD-DE-VENDEDOR.txt", "./Libros/La-última-sirena.txt", "./Libros/prueba.txt", "./Libros/SEAMOS-PERSONAS-DE-INFLUENCIA.txt"};

int NBooks = books.size();

// Condition variables used in some classes
std::condition_variable wait_pay;
std::condition_variable wait_search;
std::condition_variable wait_client;

// Semaphores used in the several systems and requests
std::mutex sem_search_sys;
std::mutex sem_pay_sys;
std::mutex sem_pay_req;
std::mutex sem_search_req;
std::mutex sem_client;

// Atomic variables
std::atomic<int> request_id (0);