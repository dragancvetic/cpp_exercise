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


class algorithm {
	public:
		/**
		 * The Algoritham's main logic
		 *
		 * @param dbg_flag		debug log enable flag
		 */
		void main( bool dbg_flag,
				int test_no,
				long long num,
				long operand1,
				long operand2 );

		/**
		 * array,new,delete,try,catch,throw
		 */
		void arrayNewDeleteTryCatchThrow ( long long num );

		/**
		 * array,new,delete,try,catch,throw
		 */
		void divadeByZero ( int operand1, int operand2 );

	private:

};

#endif
