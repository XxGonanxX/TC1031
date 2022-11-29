// =================================================================
//
// File: main.cpp
// Author: Alan Patricio González Bernal
// Date: 17/11/2022
//
// =================================================================

#include <iostream>
#include <list>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include "grafo_DFS.h"
using namespace std;


int contador;

int main(int argc, char *argv[]) {
  // main, <inputfile.txt> outputfile.txt
  ifstream inputfile;
  ofstream outputfile;

  if(argc != 3){
    cout<< "Invocación incorrecta !" << endl; 
  }
  
  inputfile.open(argv[1]); // entrada a array
  if(inputfile.fail()){

    cout << "No se pudo leer el archivo de entrada bro" << endl;
    return -1;
  
  }

  outputfile.open(argv[2]);
  if(inputfile.fail()){

    cout << "No se pudo abrir el archivo de salida bro" << endl;
    return -1;
  
  }

int NumVert, numpruebas, NMD;
string graf1, graf2, graftest; 



inputfile >> NumVert;

DFSGraph gdfs(NumVert);

for(int i; i <= NumVert; i++){
inputfile >> graf1 >> graf2;
gdfs.addEdge(i, graf1);
}


inputfile >> numpruebas;
inputfile >> graftest;
inputfile >> NMD;

outputfile << "Texto regreso:";
 gdfs.DFS();

}