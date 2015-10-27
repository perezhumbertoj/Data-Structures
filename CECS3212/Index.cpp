#include "Index.h"
#include<string>
using namespace std;

//Asigna a start el primer index de la proxima palabra y a end el ultimo
void Index::findNext() 
{
	//Encuentra el primer char q no es una excepcion
	start = line.find_first_not_of(exceptions, end);
	//Encuentra la proxima excepcion empezando en el valor actual de start
	end = line.find_first_of(exceptions, start);
}

// npos es el index mas alto q puede tener el string q invoca esta funcion

bool Index::hasMoreWords() 
{ 
	return start != string::npos; 
}

//Devuelve la proxima palabra
//si no hay mas palabra devuelve un string vacio

string Index::nextWord() 
{
	// Si no hay mas palabras devuelve un string vacio
	if (!hasMoreWords())
		return "";
	// Save the next token.
	string token = line.substr(start, end - start);
	//Find the following token.
	findNext();
	//Return the next token.
	return token;
}