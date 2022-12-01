// =================================================================
//
// File: main.cpp
// Author: 
// Alan Patricio González Bernal - A01067546
// Diego Perdomo Salcedo A01709150
// Ian Joab Padrón Corona - A01708940
// Date: 20/11/22
//
// =================================================================
#include <iostream>
#include <fstream>
#include "Heap.h"
int main(int argc, char *argv[])
{
    std::ifstream inputFile;
    std::ofstream outputFile;

	int N, E;

	inputFile >> N;

	Heap<int> heap;
	for (int i = 0; i < N; i++)
	{
		inputFile >> E;
		heap.push(E);
	}

	int c = 0;
	int t;

	while (heap.size() > 1)
	{
		t = heap.pop() + heap.pop() - 1;
		heap.push(t);
		c += t;
	}

	outputFile << c << std::endl;
}