#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;


class List;

class Node
{
	int key;
	Node* prev;
	Node* next;

public:
	Node()
	{
		key = -1; //
		prev = NULL;
		next = NULL;
	}

	Node(int k, Node* prv, Node* nxt)
	{
		key = k;
		prev = prv;
		next = nxt;
	}

	int& getKey()
	{
		return key;
	}

	friend class List;
	friend class Set;
};

class List
{
protected:
	Node *head, *tail;

public:
	List();
	List(int n);
	List(int* arr, int n);
	List(const List& list);
	virtual ~List();

	List& operator=(const List& list);
	
	void addAfter(int value, Node* pr);
	virtual void addToTail(int value);
	void addToHead(int value);

	void addToTail(List& list);
	void addToHead(List& list);

	void del(Node* node);
	void delTail();
	void delHead();

	Node* findKey(int value);
	Node* findPos(int pos);

	bool empty();
	bool notEmpty();
	bool operator==(List& list);
	bool operator!=(List& list);

	void clear();

	Node* max();
	Node* min();

	void scan(int n);
	virtual void print();

	friend istream& operator>>(istream& streamName, List& list);
	friend ostream& operator<<(ostream& streamName, List& list);
	
	friend class Set;
};