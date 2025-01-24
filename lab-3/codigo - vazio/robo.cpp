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

            glPointSize(30.0);
    glBegin(GL_POINTS);
        for (int i = 0; i < 12; i++)
        {
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

void TranslatePoint(GLfloat x, GLfloat y, GLfloat sumX, GLfloat sumY, GLfloat &xOut, GLfloat &yOut){
    xOut = x + sumX;
    yOut = y + sumY;
}

//Funcao auxiliar de rotacao
void RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut){
    xOut = x * cos(angle * M_PI / 180) - y * sin(angle * M_PI / 180);
    yOut = x * sin(angle * M_PI / 180) + y * cos(angle * M_PI / 180);
}

Tiro* Robo::Atira()
{
    GLfloat initX = 0;
    GLfloat initY = 0;

    TranslatePoint(initX, initY, 0, paddleHeight, initX, initY);
    RotatePoint(initX, initY, gTheta3, initX, initY);
    TranslatePoint(initX, initY, 0, paddleHeight, initX, initY);
    RotatePoint(initX, initY, gTheta2, initX, initY);
    TranslatePoint(initX, initY, 0, paddleHeight, initX, initY);
    RotatePoint(initX, initY, gTheta1, initX, initY);

    TranslatePoint(initX, initY, gX, gY + baseHeight, initX, initY);
    
    GLfloat angle = gTheta1 + gTheta2 + gTheta3 + 90;
    printf("Angulo dos bracos: %f, %f, %f\n", gTheta1, gTheta2, gTheta3);
    printf("Atirando: x=%f, y=%f\n", initX, initY);
    return new Tiro(initX, initY, angle);
}
