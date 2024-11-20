#include "robo.h"
#include <iostream>
#include <math.h>

void Robo::DesenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B)
{
    glColor3f(R, G, B);

    glBegin(GL_QUADS);
      glVertex2f(-width/2, 0);
      glVertex2f(width/2, 0);
      glVertex2f(width/2, height);
      glVertex2f(-width/2, height);
    glEnd();
}

void Robo::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{
    glColor3f(R, G, B);

    glBegin(GL_POINTS);
        for (int i = 0; i < 12; i++)
        {
            glPointSize(30.0);
            float theta = i * M_PI / 6;
            glVertex2f(radius * cos(theta), radius * sin(theta));
        }
    glEnd();

}

void Robo::DesenhaRoda(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat R, GLfloat G, GLfloat B)
{
    glPushMatrix();
        glTranslatef(x, y, 0);
        glRotatef(thetaWheel, 0, 0, 1);
        DesenhaCirc(radiusWheel, R, G, B);
    glPopMatrix();
}

void Robo::DesenhaBraco(GLfloat x, GLfloat y, GLfloat theta1, GLfloat theta2, GLfloat theta3)
{
    glPushMatrix();
        glTranslatef(x, y, 0);
        glRotatef(theta1, 0, 0, 1);
        DesenhaRect(paddleHeight, paddleWidth, 0.0, 0.0, 1.0);
        glTranslatef(0, paddleHeight, 0);
        glRotatef(theta2, 0, 0, 1);
        DesenhaRect(paddleHeight, paddleWidth, 1.0, 1.0, 0.0);
        glTranslatef(0, paddleHeight, 0);
        glRotatef(theta3, 0, 0, 1);
        DesenhaRect(paddleHeight, paddleWidth, 0.0, 1.0, .0);
    glPopMatrix();
}

void Robo::DesenhaRobo(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat theta1, GLfloat theta2, GLfloat theta3)
{
    glPushMatrix();
        glTranslatef(x, y, 0);
        DesenhaRect(baseHeight, baseWidth, 1.0, 0.0, 0.0);
        DesenhaBraco(0, baseHeight, theta1, theta2, theta3);
        DesenhaRoda(-baseWidth/2, 0, gThetaWheel, 1.0, 1.0, 1.0);
        DesenhaRoda(baseWidth/2, 0, gThetaWheel, 1.0, 1.0, 1.0);
    glPopMatrix();
}

void Robo::RodaBraco1(GLfloat inc)
{
    gTheta1 += inc;
}

void Robo::RodaBraco2(GLfloat inc)
{
    gTheta2 += inc;
}

void Robo::RodaBraco3(GLfloat inc)
{
    gTheta3 += inc;
}

void Robo::MoveEmX(GLfloat dx)
{
    gX += dx;
    gThetaWheel -= dx;
}

//Funcao auxiliar de rotacao
void RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut){

}

Tiro* Robo::Atira()
{
    return NULL;
}
