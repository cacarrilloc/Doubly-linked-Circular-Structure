#Author: Carlos Carrillo
#Date:   11/19/2015
#Description: This is the makefile for Lab_8

#This target will compile the entire program

All: total

total:	mainQueue.o Queue.o 
	g++ mainQueue.o Queue.o -o list

mainQueue.o: mainQueue.cpp
	g++ -c mainQueue.cpp

Queue.o: Queue.cpp
	g++ -c Queue.cpp

clean:
	rm -rf *o total