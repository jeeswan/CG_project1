
#include <windows.h>  
#include <GL/glut.h>  


char title[] = "3D Pyramid";
GLfloat anglePyramid = 0.0f; 
int refreshMills = 15;        


void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClearDepth(1.0f);                   
    glEnable(GL_DEPTH_TEST);  
    glDepthFunc(GL_LEQUAL);   
    glShadeModel(GL_SMOOTH);   
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW);    

    glLoadIdentity();                  
    glTranslatef(0.0f, 0.0f, -6.0f);  
    glRotatef(anglePyramid, 1.0f, 1.0f, 0.0f); 

    glBegin(GL_TRIANGLES);          
    // Front
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Blue
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Right
    glColor3f(1.0f, 0.0f, .0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, .0f);     // Blue
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Green
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Back
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Green
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Left
    glColor3f(1.0f, 0.0f, 0.0f);       // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);       // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);       // Green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();   

    glutSwapBuffers(); 

    anglePyramid += 0.2f;
}

void timer(int value) {
    glutPostRedisplay();      
    glutTimerFunc(refreshMills, timer, 0); 
}


void reshape(GLsizei width, GLsizei height) {  
    // Compute aspect ratio of the new window
    if (height == 0) height = 1;                
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();            
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);           
    glutInitDisplayMode(GLUT_DOUBLE); 
    glutInitWindowSize(640, 480);  
    glutInitWindowPosition(50, 50); 
    glutCreateWindow(title);          
    glutDisplayFunc(display);       
    glutReshapeFunc(reshape);       
    initGL();                       
    glutTimerFunc(0, timer, 0);     
    glutMainLoop();                
    return 0;
}