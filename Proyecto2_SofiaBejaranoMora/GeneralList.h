#pragma once
#include<iostream>
#include"DoubleNode.h"

using namespace std;

template <typename T>

class GeneralList
{
private:
	DoubleNode<T>* head;
public:
	GeneralList() {
		head = nullptr;
	}
	GeneralList(DoubleNode<T>* head) {
		this->head = head;
	}
	DoubleNode<T>* getHead() {
		return head;
	}
	void setHead(DoubleNode<T>* head) {
		this->head = head;
	}
	void insertEnd(T* data) {

		if (!head) {
			head = new DoubleNode<T>(data);
		}
		else {
			DoubleNode<T>* currentNode = head;
			while (currentNode->getNext())
			{
				currentNode = currentNode->getNext();
			}

			currentNode->setNext(new DoubleNode<T>(data));
			currentNode->getNext()->setPrevious(currentNode);

		}
	}
	void imprimir() {
		DoubleNode<T>* currentNode = head;
		while (currentNode) {
			currentNode->getData()->toString();
			currentNode = currentNode->getNext();
		}
		cout << endl;
	}
};
