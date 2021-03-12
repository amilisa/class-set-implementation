#include "List.h"

class Set: public List
{
	int N;

public:
	Set();
	Set(int n);
	Set(List& list);
	Set(const Set& set);
	~Set();

	Set& operator=(const Set& set);

	bool operator==(Set set);
	bool operator!=(Set set);

	virtual void addToTail(int value) override;

	Set operator+(int value);
	Set& operator+=(int value);

	Set operator-(int value);
	Set operator-=(int value);

	Set operator+(Set set);
	Set& operator+=(Set set);

	Set operator*(Set set);
	Set& operator*=(Set set);

	Set operator-(Set set);
	Set operator-=(Set set);

	Set operator~();

	virtual void print() override;

	friend ostream& operator<<(ostream& streamName, Set& set);
	friend istream& operator>>(istream& streamName, Set& set);
};