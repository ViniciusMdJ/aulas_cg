#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#define TAMANHO_JANELA 500

float gX = 0, gY = 0;
bool keyStatus[256] = {false};

float initial values[2][4] = {{0.25, 0.75, 0.75, 0.25}, {0.25, 0.25, 0.75, 0.75}};

void display(void)
{
   /* Limpar todos os pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   /* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
   glColor3f (1.0, 1.0, 1.0);
   /* Desenhar um polígono branco (retângulo) */
   glBegin(GL_POLYGON);
      glVertex3f (0.25 + gX, 0.25 + gY, 0.0);
      glVertex3f (0.75 + gX, 0.25 + gY, 0.0);
      glVertex3f (0.75 + gX, 0.75 + gY, 0.0);
      glVertex3f (0.25 + gX, 0.75 + gY, 0.0);
   glEnd();

   /* Desenhar no frame buffer! */
   glutSwapBuffers(); //Funcao apropriada para janela double buffer
}

void keyPress(unsigned char key, int x, int y){
   keyStatus[key] = true;
}

void keyUp(unsigned char key, int x, int y){
   keyStatus[key] = false;
}

void idle(void){
   if(keyStatus[(int)'a']) gX -= 0.001;
   if(keyStatus[(int)'d']) gX += 0.001;
   if(keyStatus[(int)'w']) gY += 0.001;
   if(keyStatus[(int)'s']) gY -= 0.001;

   glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
   y = TAMANHO_JANELA - y;

   printf("x %f - y %f\n", gX, gY);
}

void init (void) 
{
  /* selecionar cor de fundo (preto) */
  glClearColor (0.0, 0.0, 0.0, 0.0);

  /* inicializar sistema de visualizacao */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (TAMANHO_JANELA, TAMANHO_JANELA); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello world");
    init ();
    glutDisplayFunc(display);

    glutKeyboardFunc(keyPress);
    glutKeyboardUpFunc(keyUp);
    glutIdleFunc(idle);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}
