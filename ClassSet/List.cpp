#include "List.h"

List::List()
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
}

List::List(int n)
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
	for (int i = 0; i < n; i++)
	{
		int num = rand() % 50;
		addToTail(num);
	}
}

List::List(int* arr, int n)
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
	for (int i = 0; i < n; i++)
		addToTail(arr[i]);
}

List::List(const List& list)
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
	Node* t = list.head->next;
	while (t != list.tail)
	{
		addToTail(t->key);
		t = t->next;
	}
}

List::~List()
{
	clear();
	delete head;
	delete tail;
}

List& List::operator=(const List& list)
{	
	if (this != &list)
	{
		clear();
		Node* t = list.head->next;
		while (t != list.tail)
		{
			addToTail(t->key);
			t = t->next;
		}
	}
	return *this;
}

void List::addAfter(int value, Node* pr)
{
	Node* q = new Node;
	q->key = value;
	q->prev = pr;
	q->next = pr->next;
	pr->next = q;
	q->next->prev = q;
}

void List::addToTail(int value)
{
	addAfter(value, tail->prev);
}

void List::addToHead(int value)
{
	addAfter(value, head);
}

void List::addToTail(List& list)
{
	try
	{
		if (list.empty())
			throw 0;

		Node* t = list.head->next;
		Node* pr = tail->prev;
		while (t != list.tail)
		{
			addAfter(t->key, pr);
			t = t->next;
			pr = pr->next;
		}
	}
	catch (int i)
	{
		cout << "Error! The list you want to add is empty. " << endl;
	}
}

void List::addToHead(List& list)
{
	try
	{
		if (list.empty())
			throw 0;

		Node* t = list.head->next;
		Node* pr = head;
		while (t != list.tail)
		{
			addAfter(t->key, pr);
			t = t->next;
			pr = pr->next;
		}
	}
	catch (int i)
	{
		cout << "Error! The list you want to add is empty. " << endl;
	}
}

void List::del(Node* node)
{
	Node *t1, *t2;
	t1 = node->prev;
	t2 = node->next;
	t1->next = t2;
	t2->prev = t1;
	delete node;
}

void List::delTail()
{
	if (head->next == tail)
		cout << "List is empty" << endl;
	else
		del(tail->prev);
}

void List::delHead()
{
	if (head->next == tail)
		cout << "List is empty" << endl;
	else
		del(head->next);
}

Node* List::findKey(int value)
{	

	Node* t = head->next;
	while ((t != tail) && (t->key != value))
		t = t->next;
		
	if (t == tail)
		return NULL;
	else
		return t;

}

Node* List::findPos(int pos)
{
	try
	{
		if (empty())
			throw 0;

		int i = 1;
		Node* t = head->next;
		while ((t != tail) && (i < pos))
		{
			i++;
			t = t->next;
		}

		if (t == tail)
		{
			cout << "There are fewer than " << pos << " elements in the list" << endl;
			return NULL;
		}
		else
			return t;		
	}
	catch (int j)
	{
		cout << "List is empty" << endl;
		return NULL;
	}
}

bool List::empty()
{	
	if (head->next == tail)
		return true;
	else
		return false;
}

bool List::notEmpty()
{	
	if (head->next != tail)
		return true;
	else
		return false;
}

bool List::operator==(List& list)
{
	try
	{
		if (list.empty() || empty())
			throw 0;

		Node* t1 = head->next;
		Node* t2 = list.head->next;
		while ((t1 != tail) && (t2 != list.tail) && (t1->key == t2->key))
		{
			t1 = t1->next;
			t2 = t2->next;
		}

		if ((t1 == tail) && (t2 == list.tail))
			return true;
	}
	catch (int i)
	{
		cout << "One of two lists is empty" << endl;
	}
	return false;
}

bool List::operator!=(List& list)
{
	try
	{
		if (list.empty() || empty())
			throw 0;

		Node* t1 = head->next;
		Node* t2 = list.head->next;
		while ((t1 != tail) && (t2 != list.tail) && (t1->key == t2->key))
		{
			t1 = t1->next;
			t2 = t2->next;
		}

		if ((t1 == tail) && (t2 == list.tail))
			return false;
		else
			return true;
	}
	catch (int i)
	{
		cout << "One of two lists is empty" << endl;
	}
}

void List::clear()
{
	while (notEmpty())
		delHead();
}

Node* List::max()
{
	Node* m = NULL;
	Node* t = head->next;
	if (t == tail)
	{
		cout << "List is empty" << endl;
		return m;
	}
	m = t;
	t = t->next;
	while (t != tail)
	{
		if (t->key > m->key)
			m = t;
		t = t->next;
	}
	return m;
}

Node* List::min()
{
	Node* m = NULL;
	Node* t = head->next;
	if (t == tail)
	{
		cout << "List is empty" << endl;
		return m;
	}
	m = t;
	t = t->next;
	while (t != tail)
	{
		if (t->key < m->key)
			m = t;
		t = t->next;
	}
	return m;
}

void List::scan(int n)
{
	int input_value;
	clear();
	cout << "Enter " << n << " elements:" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> input_value;
		addToTail(input_value);
	}

}

void List::print()
{
	Node* t = head->next;
	while (t != tail)
	{
		cout << t->key << " ";
		t = t->next;
	}
	cout << endl;
}

istream& operator>>(istream& streamName, List& list)
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	list.scan(n);
	return streamName;
}

ostream& operator<<(ostream& streamName, List& list)
{
	list.print();
	return streamName;
}
