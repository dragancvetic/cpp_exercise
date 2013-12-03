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
#include <algorithm>
#include <vector>

#include <exercise.h>

extern "C" {
#include <ctype.h>
#include <unistd.h>
}

using namespace std;


void printHelp(void);

int main (int argc, char **argv)
{
	int c;
	char *argdir = NULL;
	int dbg_flag=0;
	Cexerc alg;

	opterr = 0;

	while ((c = getopt (argc, argv, "a:b:dn:t:")) != -1) {
		switch (c)
		{
		case 'a':
			argdir = optarg;
			alg.set_operand1( atol(argdir) );
			break;
		case 'b':
			argdir = optarg;
			alg.set_operand2( atol(argdir) );
			break;
		case 'd':
			alg.set_dbg_flag(dbg_flag);
			break;
		case 'n':
			argdir = optarg;
			alg.set_num( atoll(argdir) );
			break;
		case 't':
			argdir = optarg;
			alg.set_test_no( atoi(argdir) );
			break;
		case '?':
			printHelp();
			return 1;
		default:
			abort();
		}
	}

	alg.main( );

	return 0;
}

void printHelp(void)
{
	cout << "Options:" << endl;
	cout << "  -d         Print-out debug logs" << endl;
	cout << "  -a<str>    operand1" << endl;
	cout << "  -b<str>    operand2" << endl;
	cout << "  -n<str>    Required parameters, long long" << endl;
	cout << "  -s<str>    String" << endl;
	cout << "  -t<str>    test number" << endl;
}
