#include<iostream>
#include<string>
#include"ListQueue.h"
using namespace std;

int main()
{
	ListQueue<int> queue;
	int value, opt;

	do
	{
		cout << "Menu principal\n\n";
		cout << "1. Add un nodo al queue\n" << endl;
		cout << "2. Eliminar un nodo del queue\n" << endl;
		cout << "3. Ver el primer nodo del queue\n" << endl;
		cout << "4. Salida\n" << endl;

		cin >> opt;

		switch (opt)
		{
		case 1:
			cout << "\nEntre un numero: ";
			cin >> value;
			queue.enqueue(value);
			queue.print();
			cout << endl << endl;
			break;
		case 2:
			cout << "\nValor eliminado: " << queue.peekFront() << endl;
			queue.dequeue();
			queue.print();
			cout << endl << endl;
			break;
		case 3:
			cout << "\nValor al inicio del queue: " << queue.peekFront() << endl;
			queue.print();
			cout << endl << endl << endl;
			break;
		case 4:
			break;
		}
	}

	while (opt != 4);

	return 0;
}