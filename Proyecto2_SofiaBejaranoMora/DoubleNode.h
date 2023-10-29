#pragma once
#include<iostream>

template <typename T>

class DoubleNode
{
private:
	T data;
	DoubleNode* next;
	DoubleNode* previous;
public:
	DoubleNode(T data) {
		this->data = data;
		next = nullptr;
		previous = nullptr;
	}
	DoubleNode* getNext() {

	}
	DoubleNode* getPrevious();


};


