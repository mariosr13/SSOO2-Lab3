/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   Project             : Práctica 3 Sistemas Operativos II
*
*   Program name        : SSOOIIGLE.hpp
*
*   Author              : Mario Serrano Romero / Alejandro Duran de la Morena
*
*   Creation date       : 10/05/2023
*
*   Purpose             : 
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <functional>
#include <algorithm>
#include <queue>
#include <condition_variable>
#include <atomic>
#include <future>
#include <signal.h>

void createClients();
void createClientThreads();
void createSearchSystemThreads();
void createClientsDir();
bool wordsFileExists();
bool getWords();
void errorManage();
void installSignalHandler();
void signalHandler(int sig);