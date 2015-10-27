#pragma once
#include<iostream>
#include<string>
#include "BinarySearchTree.h"
using namespace std;

//Esta clase recibe una linea del txt file y la divide en
//palabras separadas por las excepciones q incluyas en el
//constructor
class Index 
{
public:

	Index(string source, string delim = " ") :line(source), exceptions(delim), start(0), end(0) 
	{ 
		findNext();
	}


	bool hasMoreWords();
	string nextWord();

private:

	void findNext();
	
	string line;
	
	string exceptions;
	
	size_t start;

	size_t end;
};


