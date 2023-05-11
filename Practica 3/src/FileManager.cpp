/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : FileManager.cpp
*
*   Author              : Mario Serrano Romero / Alejandro Durán de la Morena
*
*   Date created        : 27/04/2023
*
*   Purpose             : Create a file manager to manage the library.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <sstream>
#include <fstream>

#include "Search.hpp"
#include "Threads.hpp"
#include "PriorityFunction.hpp"
#include "FileManager.hpp"

std::vector<std::string> openFile(std::string file){	     
	std::ifstream ifs;
	std::vector<std::string> arrayLine;
	std::string line;
	
	ifs.open(file, std::ios::in);
	
	if(ifs.fail()){
		std::cerr << RED << "\nError, the file " << file << " could not be open" << std::endl;
	}else{
		while(!ifs.eof()){
			getline(ifs, line);
			arrayLine.insert(arrayLine.end(), line);
		}
	}

	return arrayLine;
};


std::vector<std::string> split(std::string str){	
	std::vector<std::string> string_vector;
	std::istringstream isstream(str);
	std::string word;

	while(isstream >> word){
		string_vector.push_back(word);
	}

	return string_vector;
}

std::string convertToLower(std::string line){
    for(int i = 0; i < line.length(); i++){
        line[i] = tolower(line[i]);
    }
    return line;
}

std::priority_queue<Search, std::vector<Search>, PriorityFunction> findWord(std::vector<std::string> string_vector ,std::string searched_word, int id_linea, int thread_id, int min_limit, int max_limit, std::priority_queue<Search, std::vector<Search>, PriorityFunction> pq){ 
	std::string text;
	
	searched_word = convertToLower(searched_word);

	for(int i = 0; i < string_vector.size();i++){
		if(compareWords(searched_word, string_vector[i]) == true) {	
			if(i == 0 && string_vector.size()>1){
				text = string_vector[i] + " " + string_vector[i+1] + " ...";
			}else if(string_vector.size() ==1){
				text = string_vector[i] + " ...";
            }else if(i+1==string_vector.size()){
				text = string_vector[i-1] + " " + string_vector[i] + " ...";
            }else{ 						
				text = string_vector[i-1] + " " + string_vector[i] + " " + string_vector[i+1] + " ...";
            }
            
			Threads thread(1, 0, max_limit);	
			Search search((id_linea + 1), text, i, thread);
			pq.push(search);
		}
	}

	return pq;
}

// We use this method to find the words with and without a symbol next to them.
bool compareWords(std::string word, std::string result){	
	bool coincidence_found = false;
	std::vector<std::string> symbols = {"!","¡","·","$","%","&","/","(",")","=","?","¿",",","^","]","[","-","_","@","*","|",">","<","#","+","{","}","¬",".", ";",":"};
	
	result = convertToLower(result);

	for(int i = 0; i < symbols.size() && coincidence_found == false;i++){
		if(result == word ||result == word + symbols[i] || result == symbols[i] + word){
			coincidence_found = true;
        }
	}

	return coincidence_found;
}