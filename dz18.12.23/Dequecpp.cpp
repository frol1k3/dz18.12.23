#include "Deque.h"
#include <iostream>

Node::Node(int data) {
	this->data = data;
	this->next = nullptr;
	this->previous = nullptr;
}

Deque::Deque() {
	this->front = nullptr;
	this->back = nullptr;
}

bool Deque::isEmpty() {
	return this->front == nullptr && this->back == nullptr;
}

Node* Deque::getBackNode() {
	return this->back;
}

Node* Deque::getFrontNode() {
	return this->front;
}

int Deque::getBack() {
	return this->back->data;
}

int Deque::getFront() {
	return this->front->data;
}

void Deque::pushFront(int data) {
	Node* first = new Node(data);
	first->next = this->front;
	if (this->front != NULL)
		this->front->previous = first;
	if (this->back == NULL)
		this->back = first;
	this->front = first;

}

void Deque::pushBack(int data) {
	Node* first = new Node(data);
	first->previous = this->back;
	if (this->back != NULL)
		this->back->next = first;
	if (this->front == NULL)
		this->front = first;
	this->back = first;
}

void Deque::popFront() {
	if (this->front == NULL) return;

	Node* ptr = this->front->next;
	if (ptr != NULL)
		ptr->previous = NULL;
	else
		this->back = NULL;

	delete this->front;
	this->front = ptr;
}

void Deque::popBack() {
	if (this->back == NULL) return;

	Node* ptr = this->back->previous;
	if (ptr != NULL)
		ptr->next = NULL;
	else
		this->front = NULL;

	delete this->back;
	this->back = ptr;
}

void Deque::traverse() {
	Node* next = this->front;
	while (next != this->back) {
		std::cout << next->data << " ";
		next = next->next;
	}
	std::cout << this->back->data;
	std::cout << std::endl;
}
void Deque::insert(Node* node, int data) {
	Node* ptr = node->next;
	node->next = new Node(data);
	node->next->next = ptr;
	node->next->next->previous = node;
}

void Deque::erase(Node* node) {
	Node* ptr = node->next->next;
	delete node->next;
	node->next = ptr;
	node->next->previous = node;
}

void Deque::clear() {
	while (this->front != nullptr) {
		Node* next = this->front->next;
		delete this->front;
		this->front = next;
	}
}