#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
	std::string mystr {"This is a string"};

	cout << mystr << endl;
	std::sort(mystr.begin(),mystr.end());
	cout << mystr << endl;
	mystr.at(0) = 'X';
	mystr.at(1) = 'x';
	mystr.at(2) = 'A';
	mystr.at(3) = 'a';
	mystr.at(3) = '1';
	cout << mystr << endl;
	std::sort(mystr.begin(),mystr.end());
	cout << mystr << endl;

}

