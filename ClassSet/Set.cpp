#include "Set.h"

Set::Set(): List()
{
	N = 0;
}

Set::Set(int n): List()
{
	int randomNumber;
	N = 0;
	while (N < n)
	{
		randomNumber = rand() % 50;
		addToTail(randomNumber);
	}
}

Set::Set(List& list): List()
{
	N = 0;
	Node* t = list.head->next;
	while (t != list.tail)
	{
		addToTail(t->key);
		t = t->next;
	}
}

Set::Set(const Set& set): List(set)
{
	N = set.N;
}

Set::~Set() {}

Set& Set::operator=(const Set& set)
{
	if (this != &set)
	{
		clear();
		N = 0;
		Node* t = set.head->next;
		while (t != set.tail)
		{
			addToTail(t->key);
			t = t->next;
		}
	}
	return *this;
}

bool Set::operator==(Set set)
{
	int k;
	if (N != set.N)
		return false;
	else
	{
		Node* t = set.head->next;
		while (t != set.tail)
		{
			k = t->key;
			if (findKey(k) == NULL)
				return false;
			t = t->next;
		}
	}
	return true;
}

bool Set::operator!=(Set set)
{
	int k;
	if (N != set.N)
		return true;
	else
	{
		Node* t = set.head->next;
		while (t != set.tail)
		{
			k = t->key;
			if (findKey(k) == NULL)
				return true;
			t = t->next;
		}
	}
	return false;
}

void Set::addToTail(int value)
{
	if (findKey(value) == NULL)
	{
		List::addToTail(value);
		N++;
	}
}

Set Set::operator+(int value)
{
	Set res = *this;
	res.addToTail(value);
	return res;
}

Set& Set::operator+=(int value)
{
	addToTail(value);
	return *this;
}

Set Set::operator-(int value)
{
	try
	{
		Node* t = findKey(value);
		if (t == NULL)
			throw 0;

		Set res = *this;
		res.del(t);
		res.N--;
		return res;
	}
	catch (int i)
	{
		cout << value << "is not in the set. Return original set." << endl;
		return *this;
	}
}

Set Set::operator-=(int value)
{
	try
	{
		Node* t = findKey(value);
		if (t == NULL)
			throw 0;

		del(t);
		N--;
		return *this;
	}
	catch (int i)
	{
		cout << value << "is not in the set. Return original set." << endl;
		return *this;
	}
}

Set Set::operator+(Set set)
{
	try
	{
		if (set.empty())
			throw 0;

		Set res = *this;
		Node* t = set.head->next;
		while (t != set.tail)
		{
			res.addToTail(t->key);
			t = t->next;
		}
		return res;
	}
	catch (int i)
	{
		cout << "Error! The set you want to add is empty. Return the first set." << endl;
		return *this;
	}
}

Set& Set::operator+=(Set set)
{
	try
	{
		if (set.empty())
			throw 0;

		Node* t = set.head->next;
		while (t != set.tail)
		{
			addToTail(t->key);
			t = t->next;
		}
		return *this;
	}
	catch (int i)
	{
		cout << "Error! The set you want to add is empty. Return original set." << endl;
		return *this;
	}
}

Set Set::operator*(Set set)
{
	Set res;
	int k;
	Node* t = set.head->next;
	while (t != set.tail)
	{
		k = t->key;
		if (findKey(k))
			res += k;
		t = t->next;
	}
	return res;
}

Set& Set::operator*=(Set set)
{
	Set temp;
	int k;
	Node* t = set.head->next;
	while (t != set.tail)
	{
		k = t->key;
		if (findKey(k))
			temp += k;
		t = t->next;
	}
	*this = temp;
	temp.clear();
	return *this;
}

Set Set::operator-(Set set)
{
	Set res = *this;
	int k;
	Node* t = set.head->next;
	while (t != set.tail)
	{
		k = t->key;
		if (findKey(k))
			res -= k;
		t = t->next;
	}
	return res;
}

Set Set::operator-=(Set set)
{
	int k;
	Node* t = set.head->next;
	while (t != set.tail)
	{
		k = t->key;
		if (findKey(k))
			*this -= k;
		t = t->next;
	}
	return *this;
}

Set Set::operator~()
{
	Set res(50);
	res -= (*this);
	return res;
}

void Set::print()
{
	if (N == 0)
		cout << "Set is empty";
	else
		List::print();
}

ostream& operator<<(ostream& streamName, Set& set)
{
	set.print();
	return streamName;
}

istream& operator>>(istream& streamName, Set& set)
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	set.scan(n);
	return streamName;
}
