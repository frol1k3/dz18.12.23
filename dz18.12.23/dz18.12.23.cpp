#include "Deque.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	Deque* d1 = new Deque();
	d1->pushFront(8);
	d1->pushFront(5);
	d1->pushBack(21);
	d1->pushFront(24);
	d1->pushFront(20);
	d1->pushBack(34);

	cout << "Вывод списка: ";
	d1->traverse();

	d1->popFront();
	d1->popBack();

	cout << "Вывод списка: ";
	d1->traverse();

	d1->insert(d1->getFrontNode()->next, 9);

	cout << "Вывод списка: ";
	d1->traverse();

	d1->erase(d1->getFrontNode()->next);

	cout << "Вывод списка: ";
	d1->traverse();

	d1->clear();

	cout << "Вывод списка: ";
	d1->traverse();
}