#Makefile for ConfigEngine.cpp

MODULES = ConfigEngine
SOURCE  = $(MODULES).cpp
HEADER  = $(MODULES).hpp
OBJECTS = $(MODULES).o
COMPILE = g++ -std=gnu++11 -g -O0 -Wall -Wextra
LINK    = g++ -o
REMOVE  = rm -f

ConfigEngine : $(OBJECTS)
	$(LINK) $(OBJECTS)

$(OBJECTS) : $(SOURCE)
	$(COMPILE) $(SOURCE)

clean :
	$(REMOVE) ConfigEngine ConfigEngine.o

