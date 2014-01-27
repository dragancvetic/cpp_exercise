#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int foo( int a, int& b);

int main()
{
	int a;
	int& b=a;

	for(int i=0; i<10; i++)
	{
		a=i;
		cout << "a=" << a << "; b=" << b << "; c=" << foo(a,b) << endl;
	}
}

int foo( int a, int& b)
{
	return a*b;
}
