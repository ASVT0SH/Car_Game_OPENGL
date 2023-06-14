#include<windows.h>
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>



//Game Speed
int FPS = 50;

int start = 0;
int gv = 0;
int level = 0;


int score = 0;


int roadDivTopMost = 0;
int roadDivTop = 0;
int roadDivMdl = 0;
int roadDivBtm = 0;


int lrIndex = 0;

int car1 = 0;
int lrIndex1 = 0;



const int font1 = (int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2 = (int)GLUT_BITMAP_HELVETICA_18;
const int font3 = (int)GLUT_BITMAP_8_BY_13;

char s[30];
void renderBitmapString(float x, float y, void* font, const char* string) {
    const char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void tree(int x, int y) {
    int newx = x;
    int newy = y;
    
            //Tree Trunk
    glColor3f(0.545, 0.271, 0.075);
    glBegin(GL_TRIANGLES);
    glVertex2f(newx + 11, newy + 55);
    glVertex2f(newx + 12, newy + 55 - 10);
    glVertex2f(newx + 10, newy + 55 - 10);
    glEnd();
    //Tree Leaves
    glColor3f(0.800, 0.400, 0.000);
    glBegin(GL_TRIANGLES);
    glVertex2f(newx + 11, newy + 55 + 3);
    glVertex2f(newx + 12 + 3, newy + 55 - 3);
    glVertex2f(newx + 10 - 3, newy + 55 - 3);
    glEnd();
}


void startGame() {




    //Road
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();

    //Road Left 
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(23, 100);
    glVertex2f(23, 0);
    glEnd();

    //Road Right
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(77, 0);
    glVertex2f(77, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();

    //Road Middle Border
      //TOP
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, roadDivTop + 80);
    glVertex2f(48, roadDivTop + 100);
    glVertex2f(52, roadDivTop + 100);
    glVertex2f(52, roadDivTop + 80);
    glEnd();
    roadDivTop--;
    if (roadDivTop < -100) {
        roadDivTop = 20;
        score++;
    }
    //Middle
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, roadDivMdl + 40);
    glVertex2f(48, roadDivMdl + 60);
    glVertex2f(52, roadDivMdl + 60);
    glVertex2f(52, roadDivMdl + 40);
    glEnd();



    roadDivMdl--;
    if (roadDivMdl < -60) {
        roadDivMdl = 60;
        score++;
    }
    //Bottom
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, roadDivBtm + 0);
    glVertex2f(48, roadDivBtm + 20);
    glVertex2f(52, roadDivBtm + 20);
    glVertex2f(52, roadDivBtm + 0);
    glEnd();
    roadDivBtm--;
    if (roadDivBtm < -20) {
        roadDivBtm = 100;
        score++;
    }   

    //MAIN car
        //Front Tire
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26 - 2, 5);
    glVertex2f(lrIndex + 26 - 2, 7);
    glVertex2f(lrIndex + 30 + 2, 7);
    glVertex2f(lrIndex + 30 + 2, 5);
    glEnd();
    //Back Tire
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26 - 2, 1);
    glVertex2f(lrIndex + 26 - 2, 3);
    glVertex2f(lrIndex + 30 + 2, 3);
    glVertex2f(lrIndex + 30 + 2, 1);
    glEnd();

    //Car Body
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26, 1);
    glVertex2f(lrIndex + 26, 8);
    glVertex2f(lrIndex + 30, 8);
    glVertex2f(lrIndex + 30, 1);
    glEnd();


    ////Opposite car
    //glColor3f(0.2, 0.2, 0.2);
    //glBegin(GL_POLYGON);
    //glVertex2f(lrIndex + 26 - 2, 5);
    //glVertex2f(lrIndex + 26 - 2, 7);
    //glVertex2f(lrIndex + 30 + 2, 7);
    //glVertex2f(lrIndex + 30 + 2, 5);
    //glEnd();
    ////Back Tire
    //glColor3f(0.2, 0.2, 0.2);
    //glBegin(GL_POLYGON);
    //glVertex2f(lrIndex + 26 - 2, 1);
    //glVertex2f(lrIndex + 26 - 2, 3);
    //glVertex2f(lrIndex + 30 + 2, 3);
    //glVertex2f(lrIndex + 30 + 2, 1);
    //glEnd();

    ////Car Body
    //glColor3f(1.0f, 1.0f, 1.0f);
    //glBegin(GL_POLYGON);
    //glVertex2f(lrIndex + 26, 1);
    //glVertex2f(lrIndex + 26, 8);
    //glVertex2f(lrIndex + 30, 8);
    //glVertex2f(lrIndex + 30, 1);
    //glEnd();
    //car1--;
    //if (car1 < -100) {
    //    car1 = 0;
    //    lrIndex1 = lrIndex;
    //}
    ////KIll
    //if ((abs(lrIndex - lrIndex1) < 8) && (car1 + 100 < 10)) {
    //    start = 0;
    //    gv = 1;

    //}


}

void firstPage() {
    glColor3f(0, 0, 0);
    

    //Road Backgound
    glColor3f(1.000, 1.0, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(0, 55);
    glVertex2f(100, 55);
    glColor3f(0.604, 0.804, 0.196);
    glVertex2f(100, 50 - 50);
    glVertex2f(0, 50 - 50);
    glEnd();



    //Road Design Front Page
    glColor3f(00, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(32 - 2 + 21, 55);
    glVertex2f(32 + 58, 50 - 50);
    glVertex2f(32 - 22, 50 - 50);
    glEnd();
    //Road Middle
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(32 - 2 + 21, 55);
    glVertex2f(50 + 2, 50 - 50);
    glVertex2f(50 - 2, 50 - 50);
    glEnd();

    //Road Sky
    glColor3f(0.000, 0.000, 0.200);
    glBegin(GL_POLYGON);
    glVertex2f(100, 100);
    glVertex2f(0, 100);
    glColor3f(0.686, 0.933, 0.933);
    glVertex2f(0, 55);
    glVertex2f(100, 55);
    glEnd();

    //Hill 1
    glColor3f(0.235, 0.702, 0.443);
    glBegin(GL_TRIANGLES);
    glVertex2f(20, 55 + 10);
    glVertex2f(20 + 7, 55);
    glVertex2f(0, 55);
    glEnd();

    //Hill 2
    glColor3f(1.000, 1.0, 1.000);
    glBegin(GL_TRIANGLES);
    glVertex2f(20 + 15, 55 + 12);
    glVertex2f(20 + 20 + 10, 55);
    glVertex2f(0 + 10, 55);
    glEnd();

    //Hill 4
    glColor3f(0.235, 0.702, 0.443);
    glBegin(GL_TRIANGLES);
    glVertex2f(87, 55 + 10);
    glVertex2f(100, 55);
    glVertex2f(60, 55);
    glEnd();

    //Hill 3
    glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_TRIANGLES);
    glVertex2f(70, 70);
    glVertex2f(90, 55);
    glVertex2f(50, 55);
    glEnd();

    tree(5, -15);
    tree(9, 5);
    tree(85, 9);
    tree(75, -5);


    if (gv == 1) {
        glColor3f(0.000, 0.000, 0.000);
        renderBitmapString(35, 60 + 10, (void*)font1, "GAME OVER");
        glColor3f(0.000, 0.000, 0.000);
        char buffer2[50];
        
        sprintf_s(buffer2, "Current Score : %d", score);
        renderBitmapString(33, 60 - 4 + 10, (void*)font1, buffer2);

    }



   
   
   
    glColor3f(0, 0, 0);
    renderBitmapString(35, 60 , (void*)font1, "Be Careful, Blizzard Alert!!");

    glColor3f(0.000, 1.000, 1.000);
    renderBitmapString(30 - 5, 50 - 40, (void*)font3, "Project By:");
    renderBitmapString(30 - 5, 50 - 43, (void*)font3, "1RN20CS025 Arun S and 1RN20CS026 Asutosh Urs");


}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);
   
    if (start == 1) {
       

        glClearColor(0.000, 0.392, 0.000, 1);
        startGame();
    }

    else {
        firstPage();

    }
    glFlush();
    glutSwapBuffers();
}



void spe_key(int key, int x, int y) {
    switch (key) {

    case GLUT_KEY_LEFT:
        if (lrIndex >= 0) {
            lrIndex = lrIndex - (FPS / 10);
            if (lrIndex < 0) {
                lrIndex = -1;
            }
        }
        break;

    case GLUT_KEY_DOWN:
        start = 0;
        gv = 1;
        break;

    case GLUT_KEY_RIGHT:
        if (lrIndex <= 44) {
            lrIndex = lrIndex + (FPS / 10);
            if (lrIndex > 44) {
                lrIndex = 45;
            }
        }
        break;

    default:
        break;
    }

}

void processKeys(unsigned char key, int x, int y) {

    switch (key)
    {
    case ' ':
        PlaySound(L"backgroundSound.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        if (start == 0) {
            start = 1;
            //PlaySound(L"car.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
            gv = 0;
            FPS = 50;
            roadDivTopMost = 0;
            roadDivTop = 0;
            roadDivMdl = 0;
            roadDivBtm = 0;
            lrIndex = 0;
            car1 = 0;
            lrIndex1 = 0;
            score = 0;
            level = 0;
           
        }
        break;

    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, timer, 0);
}



int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(200, 20);
    glutCreateWindow("2d Car Game");

    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys);

    glOrtho(0, 100, 0, 100, -1, 1);
    glClearColor(0.184, 0.310, 0.310, 1);

    glutTimerFunc(1000 / FPS, timer, 0);
    glutMainLoop();

    return 0;
}
