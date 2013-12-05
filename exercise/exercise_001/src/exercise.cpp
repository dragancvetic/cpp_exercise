/**
 * Copyright (C) 2013 Dragan Cvetic. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Contact information:
 * --------------------
 * e-mail:      dragan.m.cvetic@gmail.com
 */
#include <iostream>
#include <typeinfo>

extern "C" {
#include <string.h>
#include <errno.h>
}

#include <exercise.h>

using namespace std;


/*
 * Function description is in exercise.h
 */
bool Cexerc::main( void )
{
	bool ret=false;

	cout << "Hello world!" << endl;
	cout << "Exercise " << test_no << " - STARTED" << endl;

	switch( test_no ) {
	case 1:
		ret = true;
		this->arrayNewDeleteTryCatchThrow();
		break;
	case 2:
		ret = true;
		this->divadeByZero();
		break;
	case 3:
		ret = true;
		this->printTypeSizes();
		break;
	default:
		break;
	}

	cout << "Exercise " << test_no << " - ENDED" << endl;
	return ret;
}

void Cexerc::arrayNewDeleteTryCatchThrow( void )
{
	double *p;
	try {
		p = new double[num];
		cout << "No exception. Successfully allocate " << num << " integers" << endl;
	}
	catch (exception& e)
	{
		cout << "UnSuccessfully allocation of " << num << " integers" << endl;
		cout << "Standard exception: " << e.what() << endl;
		return;
	}

	// Make sure to do the delete at the end of the function too:
	delete[] p;
}

void Cexerc::divadeByZero ( void )
{
	cout << "operand1 = " << operand1 << ", operand2 = " << operand2 << "; resulet = " ;
	try {
		long a = operand1/operand2;
		cout << a << endl;
	}
	catch (exception& e)
	{
		cout << "Standard exception: " << e.what() << endl;
	}
}

void Cexerc::printTypeSizes(void)
{
	cout << "Size of the type: " << typeid(char).name() << " is: " << sizeof(char) << endl;
	cout << "Size of the type: " << typeid(int).name() << " is: " << sizeof(int) << endl;
	cout << "Size of the type: " << typeid(short).name() << " is: " << sizeof(short) << endl;
	cout << "Size of the type: " << typeid(long).name() << " is: " << sizeof(long) << endl;
	cout << "Size of the type: " << typeid(long long).name() << " is: " << sizeof(long long) << endl;
	cout << "Size of the type: " << typeid(float).name() << " is: " << sizeof(float) << endl;
	cout << "Size of the type: " << typeid(double).name() << " is: " << sizeof(double) << endl;
	cout << "typeid of this is: " << typeid(this).name() << " is: " << sizeof(this) << endl;

}

