
#include <GL/gl.h>
#include <GL/glut.h>

#include <stdlib.h>

#include <iostream>
#include <vector>
#include <string>
#include "ObjParser.hpp"
#include "Face3D.hpp"
#include "nUpla.hpp"
#include "Object.hpp"
#include "Camera.hpp"

using namespace std;

Object * ship;
Object * s1;
Object * s2;
Object * s3;

Camera * c;

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int largurajanela = 500, alturajanela = 500;

GLdouble viewer[] = {2, 2, 2};

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0); // cor para limpeza do buffer
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
      
    glFrustum(-2.0, 2.0, -2.0, 2.0, 2.0, 100.0); // proje��o perspectiva
    
    glMatrixMode(GL_MODELVIEW);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa a janela
    glLoadIdentity();
    //gluLookAt(0, -3, 2.5, s3->getX(), s3->getY(), s3->getZ(), 0, 0, 1);
 
     gluLookAt(c->getX(), c->getY(), c->getZ(),
    c->viewX(), c->viewY(), c->viewZ(),                           
    0.0, 0.0, 1.0);  
    
    
    //cout << s1->getX() << " " << s1->getY() << " " << s1->getZ() << endl;
    //s1->draw();
    s2->draw();
    //s3->draw();
    c->attVision();
    glFlush();
    glutSwapBuffers(); //usando double buffer (para evitar 'flicker')
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'q') c->_switch();
    if (key == 27) exit(0); //ESC
    if (key == 'x') viewer[0] -= 1.0;
    if (key == 'X') viewer[0] += 1.0;
    if (key == 'y') viewer[1] -= 1.0;
    if (key == 'Y') viewer[1] += 1.0;
    if (key == 'z') viewer[2] -= 1.0;
    if (key == 'Z') viewer[2] += 1.0;
    display();
}

void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(33,timer, 1);
}

void loadEnterprise(Object* &ss){
    string s = "../models/USSEnterprise.obj";
    ss = new Object(s, 0, 0, 0, 0, 0, 1, 0.05);
    ss->setCamPos(nUpla(20, 20, 20), nUpla(0, 6, -2.5));
    ss->setFactor(7.5);
}

void loadDiscovery(Object * &ss){
    string s = "../models/Discovery.obj";
    ss = new Object(s,0, 0, 0, 0, 0, 1, 0.05);
    ss->setCamPos(nUpla(0, -0.5, 0), nUpla(0, 2.5, -6));
    ss->setFactor(7.5);
}

void loadTie(Object* &ss){
    string s = "../models/TIE.obj";
    ss = new Object(s, 0, 0, 0, 0, 0, 1, 0.05); 
    ss->setCamPos(nUpla(0, -2, 0), nUpla(0, 4, -4)); 
    ss->setFactor(5);
}

int main(int argc, char **argv) {
    //loadEnterprise(s1);
    loadDiscovery(s2);
    //loadTie(s3);
    c = new Camera(s2);

    glutInit(&argc,argv); //inicializa a glut
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //tipo de buffer/cores
    glutTimerFunc(33, timer, 1);
    glutInitWindowSize(largurajanela, alturajanela); //dimens�es da janela
    glutInitWindowPosition(100, 100); //posicao da janela
    glutCreateWindow("Flying Simulator"); //cria a janela
    init();
    glutDisplayFunc(display); //determina fun��o callback de desenho
    glutKeyboardFunc(keyboard); //determina fun��o callback de teclado
  
    glEnable(GL_CULL_FACE); //habilita remo��o de superf�cies ocultas
    
    glutMainLoop();
    return 0;
}
