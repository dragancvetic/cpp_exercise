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

#ifndef EXERCISE_H_
#define EXERCISE_H_


class Cexerc {
	public:
		/**
		 * The Algoritham's main logic
		 *
		 * @param dbg_flag		debug log enable flag
		 */
		void main( void );

		/**
		 * array,new,delete,try,catch,throw
		 */
		void arrayNewDeleteTryCatchThrow ( void );

		/**
		 * array,new,delete,try,catch,throw
		 */
		void divadeByZero ( void );

		void set_test_no( int a)		{ test_no = a; }
		void set_dbg_flag( int a)		{ dbg_flag = a; }
		void set_num( long long a )		{ num= a; }
		void set_operand1( long a )		{ operand1 = a; }
		void set_operand2( long a )		{ operand2 = a; }

	private:
		int test_no;
		int dbg_flag;
		long long num;
		long operand1;
		long operand2;

};

#endif
