#include <GL/freeglut.h>
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glext.h>
#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

GLuint prog, vbo;

void display(){
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void createBuffer(){
    float vertices[]={
        -1.0f, -1.0f, 0.0f,
        1.0f,  -1.0f, 0.0f,
        0.0f,  1.0f,  0.0f
    };
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void init(){
    createBuffer();
    GLuint shaders[]={
        createShader("shader.vs", GL_VERTEX_SHADER),
        createShader("shader.fs", GL_FRAGMENT_SHADER)
    };
    int len=sizeof(shaders)/sizeof(shaders[0]);
    createProg(shaders, len);
    for(int i=0; i<len; ++i){
        glDeleteShader(shaders[i]);
    }
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(300, 200);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Window Render");
    glutDisplayFunc(display);
    glutMainLoop();
}