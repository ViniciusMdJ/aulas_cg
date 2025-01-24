#include "alvo.h"
#include <math.h>

void Alvo::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{
    glColor3f(R, G, B);

    glBegin(GL_POLYGON);
        for (int i = 0; i < 12; i++)
        {
            glPointSize(30.0);
            float theta = i * M_PI / 6;
            glVertex2f(radius * cos(theta), radius * sin(theta));
        }
    glEnd();

}

void Alvo::DesenhaAlvo(GLfloat x, GLfloat y)
{
    GLfloat R = 0, G = 0, B = 0;
    switch (gColor)
    {
        case 0: R = 1.0; break;
        case 1: G = 1.0; break;
        case 2: B = 1.0; break;
    }
    glPushMatrix();
        glTranslatef(x, y, 0);
        DesenhaCirc(radiusAlvo, R, G, B);
    glPopMatrix();
}

void Alvo::Recria(GLfloat x, GLfloat y)
{
    gX = x;
    gY = y;
    gColor = rand()%3;
}

bool Alvo::Atingido(Tiro *tiro)
{
    GLfloat xTiro, yTiro;
    tiro->GetPos(xTiro, yTiro);
    if (sqrt((xTiro - gX)*(xTiro - gX) + (yTiro - gY)*(yTiro - gY)) < radiusAlvo + radiusTiro)
    {
        return true;
    }
    return false;
}
