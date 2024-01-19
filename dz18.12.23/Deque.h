#pragma once
class Node {
public:
	int data;
	Node* next;
	Node* previous;
	Node(int data);
};

class Deque {
public:
	Node* front;
	Node* back;


	Deque();
	bool isEmpty();
	int getFront();
	int getBack();
	Node* getFrontNode();
	Node* getBackNode();
	void pushFront(int data);
	void popFront();
	void pushBack(int data);
	void popBack();
	void insert(Node* node, int data);
	void erase(Node* node);
	void traverse();
	void clear();

};
