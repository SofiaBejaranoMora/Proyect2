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
	T* getData() {
		return data;
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
	~DoubleNode() {
		data;
	}
};




