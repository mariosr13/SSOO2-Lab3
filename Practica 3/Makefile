DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/
DIRCL  := Clients/

CFLAGS := -I$(DIRHEA) -pthread -std=c++17
FILES := $(DIRSRC)Search.cpp $(DIRSRC)Threads.cpp $(DIRSRC)PriorityFunction.cpp
CC := g++

all: dirs SSOOIIGLE main execute

compile: dirs SSOOIIGLE main

dirs:
	mkdir -p $(DIREXE) $(DIROBJ)

SSOOIIGLE:
	$(CC) $(CFLAGS)  $(DIRSRC)SSOOIIGLE.cpp -o $(DIROBJ)SSOOIIGLE.o $(FILES) $(CFLAGS)
	
main:
	$(CC) -o $(DIREXE)SSOOIIGLE $(DIRSRC)SSOOIIGLE.cpp $(FILES) $(CFLAGS)

execute:
	$(DIREXE)SSOOIIGLE

clean:
	rm -r $(DIREXE) $(DIROBJ) $(DIRCL)