#pragma once
#include<iostream>

template <typename T>

class DoubleNode
{
private:
	T* data;
	DoubleNode* next;
	DoubleNode* previous;
public:
	DoubleNode(T* data) {
		this->data = data;
		next = nullptr;
		previous = nullptr;
	}
	DoubleNode* getNext() {
		return next;
	}
	DoubleNode* getPrevious() {
		return previous;
	}
	void getData() {
		data->toString();
	}
	void setData(T* data) {
		this->data = data;
	}
	void setPrevious(DoubleNode* previous) {
		this->previous = previous;
	}
	void setNext(DoubleNode* next) {
		this->next = next;
	}

};


