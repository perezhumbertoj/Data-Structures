#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include "Index.h"
#include "BinarySearchTree.h"

using namespace std;

//convierte todos los valores del string a letras minusculas para
//mantener el orden alfabetico
void toLower(string& aString) 
{ 
	for (size_t i = 0; i < aString.length(); i++)
		aString[i] = tolower(aString[i]);
}


//Recibe el .txt y el tree en el cual se va a almacenar

void build_index(BinarySearchTree<string>& tree, istream& in) 
{ 
	string nextLine; 
	int lineNum = 0; 
	while (getline(in, nextLine))
	{ 
		lineNum++;

		Index index(nextLine, " ,.:-!?()/%\'\"");
		
		while (index.hasMoreWords())
		{ 
			string word = index.nextWord();
			toLower(word);
			ostringstream os; 
			os << word; 
			os << ", "; 
			os << right; 
			os << setw(3) << lineNum;	//mantiene los espacios constantes para q el tama~o de 
			tree.add(os.str());			//la linea no afecte el orden q se construye el tree
		} 
	} 
}

int main() 
{
	BinarySearchTree<string> aTree;
	ifstream myfile("poem.txt");
	string line;

	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, line);
			cout << line << endl;
		}
		myfile.close();
	}

	else cout << "Unable to open file";

	system("pause");
	system("cls");
	
	ifstream myfile1("poem.txt");

	build_index(aTree, myfile1);
	
	aTree.inorderTraversePrint();


	myfile1.close();

	system("pause");
}