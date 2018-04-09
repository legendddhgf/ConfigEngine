#Makefile for ConfigEngine.cpp

CPP     = g++ -std=gnu++11 -g -O0 -@all -Wextra
MODULES = ConfigEngine
HDRSRC  = ${MODULES:=.h}
CPPSRC  = ${MODULES:=.cpp} main.cpp
EXECBIN = ConfigEngine
OBJECTS = ${CPPSRC:.cpp=.o}

all : ${EXECBIN}

