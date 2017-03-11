#include <GL/glut.h>

// This is an OpenGL example
// Compile with the following comman
// gcc -o glut glut.c -lGL -lGLU -lglut
//

#define DEFAULT_WINDOW_WIDTH 640
#define DEFAULT_WINDOW_HEIGHT 480

GLdouble width, height;
int mainWindow;

void init(void) {
	width = DEFAULT_WINDOW_WIDTH;
	height = DEFAULT_WINDOW_HEIGHT;
	return;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINES);
		glVertex2i(0, 0);
		glVertex2i(400, 400);
	glEnd();
	glFlush();

	return;
}

void reshape(int w, int h) {
	width = (GLdouble) w;
	height = (GLdouble) h;

	glViewport(0, 0, (GLsizei) width, (GLsizei) height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, 0.0, height, -1.f, 1.f);

	return;
}

void keyboard(unsigned char key, int x, int y) {
	switch((char) key) {
		case 'q':
		case 27: // ESC
			glutDestroyWindow(mainWindow);
			exit(0);
		default:
			break;
	}
	return;
}

int main(int argc, char *argv[]) {
	
	init();
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize((int) width, (int) height);
	
	mainWindow = glutCreateWindow("Sandbox");
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3.0);

	glutMainLoop();

	exit(0);
}

