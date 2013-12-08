#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
	char *data;
	long m,n;

	cout << "Content-Type:text/html;charset=iso-8859-1" << endl << endl;
	cout << "<TITLE>Multiplication results</TITLE>" << endl;
	cout << "<H3>Multiplication results</H3>" << endl;
	data = getenv("QUERY_STRING");
	if(data == NULL)
		cout << "<P>Error! Error in passing data from form to script." << endl;
	else if(sscanf(data,"m=%ld&n=%ld",&m,&n)!=2)
		cout << "<P>Error! Invalid data. Data must be numeric." << endl;
	else
		cout << "<P>The product of " << m << " and " << n << " is " << m*n << "." << endl;
	return 0;
}
