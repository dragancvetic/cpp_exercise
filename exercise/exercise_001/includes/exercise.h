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
		 * @param argdir		directory path name
		 * @param argflag		sort/unsort flag
		 * @param print_sizes	print sizes enable flag
		 * @param dbg_flag		debug log enable flag
		 */
	void main( bool dbg_flag);
		/**
		 * List all files/folders in the current folder.
		 */
		bool getItem ( void );

	private:

};

#endif
