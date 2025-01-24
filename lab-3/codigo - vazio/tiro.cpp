#include "tiro.h"
#include <iostream>
#include <math.h>
#define DISTANCIA_MAX 500

void Tiro::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
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

void Tiro::DesenhaTiro(GLfloat x, GLfloat y)
{
    glPushMatrix();
        glTranslatef(x, y, 0);
        DesenhaCirc(radiusTiro, 1.0, 1.0, 1.0);
    glPopMatrix();
}

void Tiro::Move(GLdouble timeDiference)
{
    gX += gVel * cos(gDirectionAng * M_PI / 180) * timeDiference;
    gY += gVel * sin(gDirectionAng * M_PI / 180) * timeDiference;
}

bool Tiro::Valido()
{
    if (sqrt(pow(gX - gXInit, 2) + pow(gY - gYInit, 2)) > DISTANCIA_MAX)
        return false;
    return true;
}
