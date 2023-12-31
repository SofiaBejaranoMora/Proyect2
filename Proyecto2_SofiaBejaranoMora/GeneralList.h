#pragma once
#include<iostream>
#include "DoubleNode.h"

using namespace std;

template <typename T>

class GeneralList
{
private:
	DoubleNode<T>* head; 
	DoubleNode<T>* last;
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
	DoubleNode<T>* getLast() {
		return last;
	}
	void setLast(DoubleNode<T>* last) {
		this->last = last;
	}
	void setHead(DoubleNode<T>* head) {
		this->head = head;
	}
	void insertEnd(T* data) {

		if (!head) {
			head = new DoubleNode<T>(data);
			last = head;
		}
		else {//NOTE:Elimine el codigo muerto
			/*DoubleNode<T>* currentNode = head;
			while (currentNode->getNext())
			{
				currentNode = currentNode->getNext();
			}

			currentNode->setNext(new DoubleNode<T>(data));
			currentNode->getNext()->setPrevious(currentNode);*/
			DoubleNode<T>* newNode = new DoubleNode<T>(data);
			newNode->setPrevious(last);
			last->setNext(newNode);
			last = newNode;

		}
	}
	bool deleteData(T* data) {
		if (head) {//NOTE: Codigo demasiado anidado
			if (head->getNext()) {
				DoubleNode<T>* currentNode = head;
				while (currentNode) {
					if ((currentNode == head) && (currentNode->getData() == data)) {
						head = currentNode->getNext();
						head->setPrevious(nullptr);
						currentNode->setNext(nullptr);
						delete currentNode;
						return true;
					}
					else if (currentNode->getData() == data) {
						if (currentNode->getNext()) {
							currentNode->getNext()->setPrevious(currentNode->getPrevious());
						}
						currentNode->getPrevious()->setNext(currentNode->getNext());
						currentNode->setNext(nullptr);
						currentNode->setPrevious(nullptr);
						delete currentNode;
						return true;
					}
					currentNode = currentNode->getNext();
				}
			}
			else if (head->getData() == data) {
				delete head;
				head = nullptr;
				return true;
			}
		}
		return false;
	}
	void deleteEnd() {
		if (head) {
			DoubleNode<T>* currentNode = head;
			while (currentNode->getNext()) {
				currentNode = currentNode->getNext();
			}
			if (currentNode == head) {
				head = nullptr;
				delete head;
				
			}
			else {
				currentNode->getPrevious()->setNext(nullptr);
				currentNode->setPrevious(nullptr);
				delete currentNode;
			}
		}
	}
};
 