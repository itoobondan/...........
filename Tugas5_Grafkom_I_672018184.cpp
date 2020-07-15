//
#include <windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

int is_depth;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("Bondan Sasmito Aji - 672018184");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(3.0);
}

void display(void)
{
    if(is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    //depan
    glBegin(GL_QUADS);
        glColor3f(94/255.0f,125/255.0f,255/255.0f);
        glVertex3f(-15.0,-10.0,10.0);
        glVertex3f(-15.0,5.0,10.0);
        glVertex3f(10.0,5.0,10.0);
        glVertex3f(10.0,-10.0,10.0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
        glColor3f(125/255.0f,20/255.0f,30/255.0f);
        glVertex3f(-15.0,-10.0,-10.0);
        glVertex3f(-15.0,5.0,-10.0);
        glVertex3f(10.0,5.0,-10.0);
        glVertex3f(10.0,-10.0,-10.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
        glColor3f(0.0,1.0,1.0);
        glVertex3f(10.0,5.0,10.0);
        glVertex3f(10.0,-10.0,10.0);
        glVertex3f(10.0,-10.0,-10.0);
        glVertex3f(10.0,5.0,-10.0);
    glEnd();

    //jendela kanan
    glBegin(GL_QUADS);
        glColor3f(1.0,1.0,1.0);
        glVertex3f(10.5,0.0,9.0);
        glVertex3f(10.5,-5.0,9.0);
        glVertex3f(10.5,-5.0,-9.0);
        glVertex3f(10.5,0.0,-9.0);
    glEnd();

    //garis jendela kanan
    glBegin(GL_LINE_STRIP);
        glColor3f(211/255.0f,122/255.0f,1.0);
        glVertex3f(10.5,0.0,9.0);
        glVertex3f(10.5,-5.0,9.0);
        glVertex3f(10.5,-5.0,-9.0);
        glVertex3f(10.5,0.0,-9.0);
        glVertex3f(10.5,0.0,9.0);
        glEnd();

    //kiri
    glBegin(GL_QUADS);
        glColor3f(0.0,1.0,1.0);
        glVertex3f(-15.0,5.0,10.0);
        glVertex3f(-15.0,-10.0,10.0);
        glVertex3f(-15.0,-10.0,-10.0);
        glVertex3f(-15.0,5.0,-10.0);
    glEnd();

        //jendela kiri
    glBegin(GL_QUADS);
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-15.5,0.0,9.0);
        glVertex3f(-15.5,-5.0,9.0);
        glVertex3f(-15.5,-5.0,-9.0);
        glVertex3f(-15.5,0.0,-9.0);
    glEnd();

    //jendela kiri garis tambahan
    glBegin(GL_LINE_STRIP);
        glColor3f(211/255.0f,122/255.0f,1.0);
        glVertex3f(-15.5,0.0,9.0);
        glVertex3f(-15.5,-5.0,9.0);
        glVertex3f(-15.5,-5.0,-9.0);
        glVertex3f(-15.5,0.0,-9.0);
        glVertex3f(-15.5,0.0,9.0);
    glEnd();

    //atas
    glBegin(GL_TRIANGLES);
        glColor3f(0.0,0.5,1.0);
        glVertex3f(10.0,0.0+20.0,0.0);
        glVertex3f(10.0,5.0+0.0,10.0);
        glVertex3f(10.0,5.0+0,-10.0);
        glVertex3f(0.0,0.0+0,0.0);
    glEnd();
    //atas juga
    glBegin(GL_TRIANGLES);
        glColor3f(0.0,0.5,1.0);
        glVertex3f(-15.0,0.0+20.0,0.0);
        glVertex3f(-15.0,5.0+0.0,10.0);
        glVertex3f(-15.0,5.0+0,-10.0);
        glVertex3f(0.0,0.0+0,0.0);
    glEnd();

    //genteng depam
    glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-15.0,5.0,10.0);
        glVertex3f(-15.0,20.0,0.0);
        glVertex3f(10.0,20.0,0.0);
        glVertex3f(10.0,5.0,10.0);
    glEnd();

    //genteng belakang
    glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-15.0,5.0,-10.0);
        glVertex3f(-15.0,20.0,0.0);
        glVertex3f(10.0,20.0,0.0);
        glVertex3f(10.0,5.0,-10.0);
    glEnd();

    //pintu
    glBegin(GL_QUADS);
        glColor3f(10/255.0f,22/255.0f,66/255.0f);
        glVertex3f(-5.0,-10.0,11.0);
        glVertex3f(-5.0,0.0,11.0);
        glVertex3f(2.0,0.0,11.0);
        glVertex3f(2.0,-10.0,11.0);
    glEnd();

    //pintu tambahan
    glBegin(GL_LINES);
        glColor3f(1.0,1.0,1.0);
        glVertex3f(-1.5,0.0,11.5);
        glVertex3f(-1.5,-10.0,11.5);
    glEnd();

    //pintu juga
    glBegin(GL_LINE_STRIP);
    glLineWidth(-5.0);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-5.0,-10.0,10.5);
    glVertex3f(-5.0,0.0,10.5);
    glVertex3f(2.0,0.0,10.5);
    glVertex3f(2.0,-10.0,10.5);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
        glColor3f(0.0,0.5,0.0);
        glVertex3f(-15.0,-10.0,10.0);
        glVertex3f(10.0,-10.0,10.0);
        glVertex3f(10.0,-10.0,-10.0);
        glVertex3f(-15.0,-10.0,-10.0);
    glEnd();

    //dekor
    glBegin(GL_QUADS);
        glColor3f(0.0,1.0,1.0);
        glVertex3f(-15.0,5.0,10.0);
        glVertex3f(-15.0,4.5,25.0);
        glVertex3f(10.0,4.5,25.0);
        glVertex3f(10.0,5.0,10.0);
    glEnd();

    //pilar
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-15.0,4.5,25.0);
    glVertex3f(-10.0,-5.0,0.0);
    glEnd();

    //pilar juga
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(7.0,-5,0.0);
    glVertex3f(10.0,4.5,25.0);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-10.0,-5.0,-11.0);
        glVertex3f(-10.0,0.0,-11.0);
        glVertex3f(5.0,0.0,-11.0);
        glVertex3f(5.0,-5.0,-11.0);
    glEnd();

    //tambahan jendela
    //belakang
    glBegin(GL_LINES);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-10.0,-5.0,-11.0);
        glVertex3f(-10.0,0.0,-11.0);
        glVertex3f(5.0,0.0,-11.0);
        glVertex3f(5.0,-5.0,-11.0);
    glEnd();



    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0,0.0,3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0,0.0,0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0,0.0,-3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0,0.0,0.0);
        break;
    case '7':
        glTranslatef(0.0,3.0,0.0);//geser atas
        break;
    case '9':
        glTranslatef(0.0,-3.0,0.0);//geser bawah
        break;
    case '2':
        glRotatef(2.0,1.0,0.0,0.0);//rotate bawah
        break;
    case '8':
        glRotatef(-2.0,1.0,0.0,0.0);//rotate atas
        break;
    case '6':
        glRotatef(2.0,0.0,1.0,0.0);//rotate kanan x
        break;
    case '4':
        glRotatef(-2.0,0.0,1.0,0.0);//rotate kiri x
        break;
    case '1':
        glRotatef(2.0,0.0,0.0,1.0);//rotate kiri y
        break;
    case '3':
        glRotatef(-2.0,0.0,0.0,1.0);//rotate kanan y
        break;
    case '5':
        if(is_depth)
        {
            is_depth=0;
            glDisable(GL_DEPTH_TEST);
        }else
        {
            is_depth=1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();
}

void ukuran(int lebar, int tinggi)
{
    if(tinggi==0) tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0,lebar/tinggi,5.0,500.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
