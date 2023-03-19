#include <GL/freeglut.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
GLuint prog, vbo;

void square(){
    glColor3f(0.75, 1.0, 0.3);
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.75, 1.0, 0.0);
    glEnd();
    glFlush();
}

void display(){
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    square();
    glutSwapBuffers();
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Window Render");
    glutDisplayFunc(display);
    glutMainLoop();
}