/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : FileManager.hpp
*
*   Author              : Mario Serrano Romero / Alejandro Duran de la Morena
*
*   Creation date       : 9/05/2023 
*
*   Purpose             : Definition of the class FileManager
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <string>
#include <queue>
#include "PriorityFunction.hpp"

std::vector<std::string> openFile(std::string file);
std::vector<std::string> split(std::string str);
std::string convertToLower(std::string s);
std::priority_queue<Search, std::vector<Search>, PriorityFunction> findWord(std::vector<std::string> string_vector ,std::string searched_word, int id_linea, int thread_id, int min_limit, int max_limit, std::priority_queue<Search, std::vector<Search>, PriorityFunction> pq);
bool compareWords(std::string word, std::string result);