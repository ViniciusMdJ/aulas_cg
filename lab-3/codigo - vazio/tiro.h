#ifndef TIRO_H
#define	TIRO_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#define radiusTiro 5

class Tiro {
    GLfloat gXInit; 
    GLfloat gYInit; 
    GLfloat gX; 
    GLfloat gY; 
    GLfloat gDirectionAng;
    GLfloat gVel;
private:
    void DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B);
    void DesenhaTiro(GLfloat x, GLfloat y);
public:
    Tiro(GLfloat x, GLfloat y, GLfloat directionAng){
        gXInit = x; 
        gYInit = y; 
        gX = x; 
        gY = y; 
        gDirectionAng = directionAng; 
        gVel = 0.3;
        
        printf("Tiro criado em (%f, %f) com angulo %f\n", gX, gY, gDirectionAng);
    };
    void Desenha(){ 
        DesenhaTiro(gX, gY);
    };
    void Move(GLdouble timeDiference);
    bool Valido();
    void GetPos(GLfloat &xOut, GLfloat &yOut){
        xOut = gX;
        yOut = gY;
    };
};

#endif	/* TIRO_H */

