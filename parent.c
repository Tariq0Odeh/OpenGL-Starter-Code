#include <GL/glut.h>

//------------------------------------------------[OpenGL variables]-------------------------------------------------------------//
void startOpenGl();
void display();
void init();
void reshape(int w, int h);
void timer(int value);
void rectangle(int x1, int y1, int x2, int y2, float r, float g, float b);
void drawSquare(int centerX, int centerY, int sideLength, float red, float green, float blue);
void drawText_size(int centerX, int centerY, char *str, int size);
void drawLine(int centerX1, int centerY1, int centerX2, int centerY2);
void writeIntegerAtPosition(int number, float x, float y);

float move_x = 300.0; 		// Initial x position of the rectangle
float move_speed = 2.0; 	// Speed of movement
float move_y = 300.0; 		// Initial x position of the rectangle


//-------------------------------------------------[    Main    ]----------------------------------------------------------------//

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	startOpenGl();
    return 0;
}

//------------------------------------------------[OpenGL functions]-------------------------------------------------------------//

void startOpenGl(){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Moving Rectangle");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
}

//--------------------------------------------------------------------

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 600);
	glMatrixMode(GL_MODELVIEW);
}

//--------------------------------------------------------------------


void init()
{
	glClearColor(1, 1, 1, 1);
}

//--------------------------------------------------------------------

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    ///

    rectangle(move_x - 50, move_y, move_x + 50, move_y+50, 0, 1, 0); // First rectangle
    drawSquare(150, 200, 20, 0, 1, 1); // Second rectangle
    drawText_size(200, 400, "OpenGL", 18); // Text positioned above the first rectangle, size 18

    ///

    glFlush();
}


//--------------------------------------------------------------------

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);


    // Update the x position of the rectangle
    move_x += move_speed;
    if (move_x > 550) // If the rectangle reaches the right side, reset its position
        move_x = -50;

 	move_y += 2;
    if (move_y > 550) // If the rectangle reaches the right side, reset its position
        move_y = -50;


	
}

//--------------------------------------------------------------------

void rectangle(int x1, int y1, int x2, int y2, float r, float g, float b)
{
	glBegin(GL_POLYGON);
	glColor3f(r, g, b);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}

//--------------------------------------------------------------------

void drawSquare(int centerX, int centerY, int sideLength, float red, float green, float blue)
{
	int halfSide = sideLength / 2; // Calculate half of the side length

	int vertices[] = {
		centerX - halfSide, centerY - halfSide, // Bottom-left vertex
		centerX + halfSide, centerY - halfSide, // Bottom-right vertex
		centerX + halfSide, centerY + halfSide, // Top-right vertex
		centerX - halfSide, centerY + halfSide	// Top-left vertex
	};

	glColor3f(red, green, blue); // Set the color of the square

	glBegin(GL_QUADS); // Draw the square
	for (int i = 0; i < 4; i++)
		glVertex2f(vertices[i * 2], vertices[i * 2 + 1]);
	glEnd();
}

//--------------------------------------------------------------------

void drawText_size(int centerX, int centerY, char *str, int size)
{
	glRasterPos2i(centerX, centerY); // Position for Square 1 text
	const char *text1 = str;

	if (size == 18)
	{
		glColor3f(1, 1, 1);
		for (int i = 0; i < strlen(text1); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text1[i]);
	}
	else if (size == 10)
	{
		glColor3f(0, 0, 0);
		for (int i = 0; i < strlen(text1); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, text1[i]);
	}
	else if (size == 15)
	{
		glColor3f(0, 0, 0);
		for (int i = 0; i < strlen(text1); i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text1[i]);
	}
}

//--------------------------------------------------------------------

void drawLine(int centerX1, int centerY1, int centerX2, int centerY2)
{
	glColor3f(0, 0, 0); // Set color to black
	glBegin(GL_LINES);
	glVertex2i(centerX1, centerY1);
	glVertex2i(centerX2, centerY2);
	glEnd();
}

//--------------------------------------------------------------------

void writeIntegerAtPosition(int number, float x, float y)
{
	glRasterPos2f(x, y);
	char str[10];
	sprintf(str, "%d", number);
	for (int i = 0; str[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
}

//--------------------------------------------------------------------