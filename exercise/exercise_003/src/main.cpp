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

#include <GL/glut.h>//Drawing funciton
void draw(void)
{
	//Background color
	glClearColor(0,1,0,1);
	glClear(GL_COLOR_BUFFER_BIT );

	//Draw order
	glFlush();
}

//Main program
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	//Simple buffer
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition(50,25);
	glutInitWindowSize(500,250);
	glutCreateWindow("Green window");

	//Call to the drawing function
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
