#include <windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init(void);
void display(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mousemotion(int x, int y);
void balok(void);

float xrot=0.0;
float yrot=0.0;
float xdiff=0.0;
float ydiff=0.0;
bool mousedown = false;
int x;
int is_depth;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("Bondan Sasmito Aji -672018184");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(ukuran);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(2.5);
    glLineWidth(2.0);
}

void display(void) //
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//untuk mengatur penglihatan mata/penglihatan objek
    glRotatef(xrot, 1.0, 0.0, 0.0);
    glRotatef(yrot, 0.0, 1.0, 0.0);

    glPushMatrix();

    //Bagian tanah
    glBegin(GL_QUADS);
        glColor3f(1.0,178/255.0f,102/255.0f);
        glVertex3f(-45.0,-20.0,25.0);
        glVertex3f(40.0,-20.0,25.0);
        glVertex3f(40.0,-20.0,-25.0);
        glVertex3f(-45.0,-20.0,-25.0);
    glEnd();
////////////////////////////////////////////////////////////////////
    //Bagian atap
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(-10.0,10.0,5.0);
        glVertex3f(5.0,10.0,5.0);
        glVertex3f(5.0,10.0,-5.0);
        glVertex3f(-10.0,10.0,-5.0);
    glEnd();

    //Bagian atap depan (utama)
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(-10.0,10.0,5.0);
        glVertex3f(5.0,10.0,5.0);
        glVertex3f(5.0,5.0,5.0);
        glVertex3f(-10.0,5.0,5.0);
    glEnd();

    //Bagian atap belakang (utama)
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(-10.0,10.0,-5.0);
        glVertex3f(5.0,10.0,-5.0);
        glVertex3f(5.0,5.0,-5.0);
        glVertex3f(-10.0,5.0,-5.0);
    glEnd();

    //Bagian atap kiri (utama)
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(-10.0,10.0,5.0);
        glVertex3f(-10.0,5.0,5.0);
        glVertex3f(-10.0,5.0,-5.0);
        glVertex3f(-10.0,10.0,-5.0);
    glEnd();

    //Bagian atap kanan (utama)
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(5.0,10.0,5.0);
        glVertex3f(5.0,5.0,5.0);
        glVertex3f(5.0,5.0,-5.0);
        glVertex3f(5.0,10.0,-5.0);
    glEnd();

////////////////////////////////////////////////////////////////////////
    //Bagian atap kiri
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(-10.0,10.0,3.0);
        glVertex3f(-15.0,10.0,3.0);
        glVertex3f(-15.0,10.0,-3.0);
        glVertex3f(-10.0,10.0,-3.0);
    glEnd();

    //Bagian atap kiri (2)
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(10.0,5.0,-3.0);
        glVertex3f(10.0,10.0,-3.0);
        glVertex3f(-15.0,10.0,-3.0);
        glVertex3f(-15.0,5.0,-3.0);
    glEnd();

    //Bagian atap kiri (3)
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(-15.0,5.0,3.0);//
        glVertex3f(-15.0,10.0,3.0);
        glVertex3f(-15.0,10.0,-3.0);
        glVertex3f(-15.0,5.0,-3.0);//
    glEnd();

    //Bagian atap kanan
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(10.0,10.0,3.0);
        glVertex3f(5.0,10.0,3.0);
        glVertex3f(5.0,10.0,-3.0);
        glVertex3f(10.0,10.0,-3.0);
    glEnd();

    //Bagian atap kanan (2)
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(10.0,5.0,3.0);
        glVertex3f(10.0,10.0,3.0);
        glVertex3f(10.0,10.0,-3.0);
        glVertex3f(10.0,5.0,-3.0);
    glEnd();

    //Bagian atap kanan (2)
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(10.0,5.0,3.0);
        glVertex3f(10.0,10.0,3.0);
        glVertex3f(-15.0,10.0,3.0);
        glVertex3f(-15.0,5.0,3.0);
    glEnd();
/////////////////////////////////////////////////////////////////////////
    //Bagian atap dekorasi depan 1
    for (x=0; x<4; x++){
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-10.0,13.0,5.0);
        glVertex3f(-7.0,13.0,5.0);
        glVertex3f(-7.0,13.0,2.0);
        glVertex3f(-10.0,13.0,2.0);
    glEnd();}

    //Bagian atap dekorasi belakang 1
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-10.0,13.0,-5.0);
        glVertex3f(-7.0,13.0,-5.0);
        glVertex3f(-7.0,13.0,-2.0);
        glVertex3f(-10.0,13.0,-2.0);
    glEnd();

    //Bagian atap dekorasi depan 2
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(5.0,13.0,5.0);
        glVertex3f(2.0,13.0,5.0);
        glVertex3f(2.0,13.0,2.0);
        glVertex3f(5.0,13.0,2.0);
    glEnd();

    //Bagian atap dekorasi belakang 2
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(5.0,13.0,-5.0);
        glVertex3f(2.0,13.0,-5.0);
        glVertex3f(2.0,13.0,-2.0);
        glVertex3f(5.0,13.0,-2.0);
    glEnd();
////////////////////////////////////////////////////////////////////
    //Bagian paling Atas hotel sebelum atap
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-20.0,5.0,10.0);
        glVertex3f(15.0,5.0,10.0);
        glVertex3f(15.0,5.0,-10.0);
        glVertex3f(-20.0,5.0,-10.0);
    glEnd();

    //Bagian paling Atas hotel depan sebelum atao
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-20.0,0.0,-10.0);
        glVertex3f(15.0,0.0,-10.0);
        glVertex3f(15.0,5.0,-10.0);
        glVertex3f(-20.0,5.0,-10.0);
    glEnd();

    //Bagian paling Atas hotel belakang sebelum atap
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-20.0,0.0,10.0);
        glVertex3f(15.0,0.0,10.0);
        glVertex3f(15.0,5.0,10.0);
        glVertex3f(-20.0,5.0,10.0);
    glEnd();

    //Bagian Atas hotel kiri sebelum atap
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-20.0,5.0,10.0);
        glVertex3f(-20.0,0.0,10.0);
        glVertex3f(-20.0,0.0,-10.0);
        glVertex3f(-20.0,5.0,-10.0);
    glEnd();

    //Bagian Atas hotel kanan sebelum atap
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(15.0,0.0,10.0);
        glVertex3f(15.0,5.0,10.0);
        glVertex3f(15.0,5.0,-10.0);
        glVertex3f(15.0,0.0,-10.0);
    glEnd();
///////////////////////////////////////////////////////////////////////////////////
    //Bagian kedua Atas hotel
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(-25.0,0.0,12.0);
        glVertex3f(20.0,0.0,12.0);
        glVertex3f(20.0,0.0,-12.0);
        glVertex3f(-25.0,0.0,-12.0);
    glEnd();

    //Bagian kedua Atas hotel Depan
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(-25.0,-5.0,12.0);
        glVertex3f(20.0,-5.0,12.0);
        glVertex3f(20.0,0.0,12.0);
        glVertex3f(-25.0,0.0,12.0);
    glEnd();

    //Bagian kedua Atas hotel belakang
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(-25.0,-5.0,-12.0);
        glVertex3f(20.0,-5.0,-12.0);
        glVertex3f(20.0,0.0,-12.0);
        glVertex3f(-25.0,0.0,-12.0);
    glEnd();

    //Bagian kedua Atas hotel kiri
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(-25.0,0.0,12.0);
        glVertex3f(-25.0,-5.0,12.0);
        glVertex3f(-25.0,-5.0,-12.0);
        glVertex3f(-25.0,0.0,-12.0);
    glEnd();

    //Bagian kedua Atas hotel kanan
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(20.0,0.0,12.0);
        glVertex3f(20.0,-5.0,12.0);
        glVertex3f(20.0,-5.0,-12.0);
        glVertex3f(20.0,0.0,-12.0);
    glEnd();

//////////////////////////////////////////////////////////////////

    //Bagian ketiga Atas hotel
    glBegin(GL_QUADS);
        glColor3f(1.0,153/255.0f,51/255.0f);
        glVertex3f(-30.0,-5.0,14.0);
        glVertex3f(25.0,-5.0,14.0);
        glVertex3f(25.0,-5.0,-14.0);
        glVertex3f(-30.0,-5.0,-14.0);
    glEnd();

    //Bagian keempat Atas hotel
    glBegin(GL_QUADS);
        glColor3f(0.0,153/255.0f,51/255.0f);
        glVertex3f(-35.0,-10.0,16.0);
        glVertex3f(30.0,-10.0,16.0);
        glVertex3f(30.0,-10.0,-16.0);
        glVertex3f(-35.0,-10.0,-16.0);
    glEnd();




    glPopMatrix();
    glutSwapBuffers();
}

void idle()
{
    if(!mousedown)
    {
        xrot+=0.3;
        yrot+=0.4;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        mousedown=true;
        xdiff=x-yrot;
        ydiff=-y+xrot;
    }
    else
    mousedown=false;
}

void keyboard(unsigned char key, int a, int b)
{
    switch (key)
    {
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
void mousemotion(int x, int y)
{
    if(mousedown)
    {
        yrot=x-xdiff;
        xrot=y+ydiff;

        glutPostRedisplay();
    }
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
