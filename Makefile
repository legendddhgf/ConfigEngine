#Makefile for ConfigEngine.cpp

MODULE  = ConfigEngine
SOURCE  = $(MODULE).cpp
HEADER  = $(MODULE).hpp
OBJECTS = $(MODULE).o
COMPILE = g++ -c -g
#COMPILE = gcc -c -std=c99 -Wall #-std=gnu++11 -g -O0 -Wall -Wextra
LINK    = g++ -g -o
REMOVE  = rm -f

all: $(MODULE)

$(MODULE) : $(OBJECTS)
	$(LINK) $(MODULE) $(OBJECTS)

$(OBJECTS) : $(SOURCE)
	$(COMPILE) $(SOURCE)

clean :
	$(REMOVE) $(MODULE) $(OBJECTS)

