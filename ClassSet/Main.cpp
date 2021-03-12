#include "Set.h"

int main()
{
	cout << "Task 1\n";
	Set s1(10);
	cout << "S1: ";
	s1.print();

	cout << "\nTask 2\n";
	Set s2 = s1;
	cout << "S2: " << s2;
	if (s1 == s2)
		cout << "S1 equals S2" << endl;
	else
		cout << "S1 does not equal S2" << endl;

	cout << "\nTask 3\n";
	Set s3;
	if (s1.findKey(5))
	{
		cout << "S1 contains 5" << endl;
		s3 = s1 - 5;
	}
	else
	{
		cout << "S1 does not contain 5" << endl;
		s3 = s1 + 5;
	}
	cout << "S3: " << s3;
	if (s2 != s3)
		cout << "S2 does not equal S3" << endl;
	else
		cout << "S2 equals S3" << endl;

	cout << "\nTask 4\n";
	Set s4;
	if (s4.empty())
		cout << "S4 is empty" << endl;
	else
		cout << "S4 is not empty" << endl;

	s4 += 5;
	s4 += 10;
	s4 += 15;
	s4 += 5;
	cout << "S4: " << s4;

	cout << "\nTask 5\n";
	Set s5;
	s5 = s4;
	if (s5.findKey(15))
	{
		cout << "S5 contains 15" << endl;
		s5 -= 15;
	}
	else
	{
		cout << "S5 does not contain 15" << endl;
	}
	cout << "S5: " << s5;

	cout << "\nTask 6\n";
	List t(20);
	cout << "T: " << t;
	Set s6(t);
	cout << "S6: " << s6;

	cout << "\nTask 7\n";
	Set s7;
	s7 = ~s6;
	cout << "S7: " << s7;

	Set s8;
	s8 = s7 * s6;
	cout << "S8: " << s8;

	cout << "\nTask 8\n";
	Set s9;
	cin >> s9;
	cout << "S9: " << s9;

	Set v1, v2, v3;
	v1 = s7 * s9;
	v2 = s7 + s9;
	v3 = s7 - s9;
	cout << "V1: " << v1;
	cout << "V2: " << v2;
	cout << "V3: " << v3;
	
	cout << "\nTask 9\n";
	v1 += v3;
	cout << "Changed V1 (v1 += v3): " << v1;
	if (v1 == s7)
		cout << "V1 equals S7" << endl;
	else
		cout << "V1 does not equal S7" << endl;

	cout << "\nTask 10\n";
	v2 = v2 - v3;
	cout << "S9: " << s9;
	cout << "Changed V2 (v2 - v3): " << v2;
	if (v2 == s9)
		cout << "V2 equals S9" << endl;
	else
		cout << "V2 does not equal S9" << endl;
}