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
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

#include <exercise.h>

using namespace std;

struct Phone {
	string name;
	long number;
};

bool numberCompare( const Phone& e1, const Phone& e2 ) {
	return e1.number < e2.number;
}

/*
 * Function description is in exercise.h
 */
bool Cexerc::main( void )
{

	ifstream in("phone.txt");
	if( !in )
	{
		cout << "Unable to open phone.txt" << endl;
		return false;
	}

	vector<Phone> phoneNumbers;		// container for entry
	Phone entry;					// Temporary entry for reading

	while ( in >> entry.name >> entry.number ) {
		phoneNumbers.push_back(entry);		// Add to end
	}

	in.close();

	sort( phoneNumbers.begin(), phoneNumbers.end(), numberCompare );

	for (
			vector<Phone>::const_iterator it = phoneNumbers.begin();
			it < phoneNumbers.end();
			it++
			)
	{
		cout << it->number << ' ' << it->name << endl;
	}

	return true;
}

