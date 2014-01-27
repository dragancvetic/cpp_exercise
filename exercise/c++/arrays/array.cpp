#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
	std::array<int,3> myarray {{10,1,2}};
	std::array<string,3> myarray2 {{"asdf","1asddasd","1aSAs"}};
	int *p;

	try
	{
		p = new int[3];
	}
	catch (exception& e)
	{
		cout << "Exception is: " << e.what() << endl;
	}

	for (int i=0; i<(int)myarray.size(); ++i) {
		++myarray[i];
		p[i] = myarray[i];
	}

	std::sort(myarray.begin(),myarray.end());
	for (int i=0; i<(int)myarray.size(); i++)
		cout << myarray.at(i) << " - " << p[i] << endl;

	std::sort(myarray2.begin(),myarray2.end());
	for (int i=0; i<(int)myarray2.size(); i++)
		cout << myarray2.at(i) << endl;

	delete[] p;
}
