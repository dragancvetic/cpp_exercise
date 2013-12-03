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
//	char *argdir = NULL;
	bool dbg_flag = false;
	int c;
	algorithm alg;

	opterr = 0;

	while ((c = getopt (argc, argv, "bd:")) != -1) {
		switch (c)
		{
		case 'b':
			dbg_flag = true;
			break;
		case 'd':
//			argdir = optarg;
			break;
		case '?':
			printHelp();
			return 1;
		default:
			abort();
		}
	}
//	if(argdir==NULL)
//	{
//		printHelp();
//		return 1;
//	}

	alg.main( dbg_flag );

	return 0;
}

void printHelp(void)
{
	cout << "Options:" << endl;
	cout << "  -d<path>   Directory path; required parameter" << endl;
	cout << "  -b         Print-out debug logs" << endl;
}
