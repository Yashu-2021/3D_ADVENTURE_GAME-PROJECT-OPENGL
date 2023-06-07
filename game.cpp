

#include <iostream>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<sstream>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "imageloader.h"
float message_y=-10.0f;
float wr=0.7,wg=0.9,wb=1;
int background_flag=-1,_grassId,_graveId,_gameId;
using namespace std;
int ballflag=-1,ballx=1,ballz=1;
float mouse_x,mouse_y,x_angle,y_angle;
float ct=0,bufx,bufz;
float theta=0.0;
int gameflag=1;
int upflag=1;
int mouse=-1;
int nailcount,stop=0;
float zoom=0.0,spi_count=0;
int scorecount=0;
char scoremsg[10]="Score: 1";
int sharkturn=-1;
const float FLOOR_TEXTURE_SIZE = 15.0f; //The size of each floor "tile"
int ttcnt=0,bombcnt=0;
int spi_flag=0,bhootflag=0;
float sidediff1=0.0,sidediff2=0.0;
int teleportblock=-1;
int arrowangle=0;
int dangerno=-1;
int onboat=0,onisland=0;
int bhootcount=0;
int blockdownflag=0;
int drown=0;
int turn=0,bombflag=0,bombradius=3;
int bflag=0;
int winflag=0;
int dangerbflag=0;
int waflag=0;
int sideflag=0;
float _angle = 30.0f;
float up=0;
float dr=0,db=0,dg=0;
GLfloat angle1 = 0.0f;
int shflag=0;
int _textureId;
int _dangerId;
int _islandId;
int firstView=-1;
int backView=-1;
int heliView=-1;
int tileView=-1;
int towerView=-1;
int aircamera=-1;
double posX,posY,posZ;
int camera=-1;
int jumpflag=0;
int telecount=0;
int teleflag=-1;
int jflag=0;
float jpos;
float curj=0;
int downflag=0;
int timecnt=0;
int waitcnt=0;
int waitflag=0;
int direction=0,rotang=0;
int _crateId;
float deadb=0;
int selectedtile=0;
int normalView=1;
float cangle=0.0;
float towercangle=15.0;
char message[10]="Level 2";
char message1[10]="You win!";
// actual vector representing the camera's direction
float clx=0.0f,clz=-1.0f,cly=1.0f;
float towerclx=0.1f,towerclz=0.1f;
// XZ position of the camera
float cx=0.0f,cz=5.0f;
float towerpitch=0;
int angle=0;
int fogflag=0;
int fogcount=0;
//The forward position of the guy relative to an arbitrary floor "tile"

void drawQuad2(float x,float y,float z);
void drawCylinder(float base,float top,float height){
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic,base,top,height,32,32);

}
void drawcylinder(float x,float y,float z){
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic,x,y,z,32,32);
}


class khoon{
	public:
	float x,y,z;
	void draw()
	{
		glPushMatrix();
		glTranslatef(x,y,z);
		glutSolidSphere(1,32,32);
		glPopMatrix();
	}
};

class Particle{
	public:
	float x1,y1,z1;
	float x2,y2,z2;
	
	void draw(){
		//glColor3f(0,0,0.7);
		glLineWidth(1);
		//glBegin(GL_LINE_STRIP);
		glVertex3f(x1,y1,z1);
		glVertex3f(x2,y2,z2);
		glEnd();
	}
};

class Line{
	public:
		Particle particles[1000];
};

class Rain{
	public:
		float x, y, z;
		Line lines[60][30];

		void drawRain (void) {	
			x= -15.0;
			y= 20.0;
			z= 0.0;
			glPushMatrix();
			//person
			glTranslatef(0.0f, 0.0f, -15.0f); 
			//glRotatef(30, 1.0, 0.0, 0.0); //rotate on the x axis
			//glRotatef(angle, 1.0, 1.0, 0.0); //rotate on the y axis
			//glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the z axis
			glColor3f(0.0, 0.0, 0.0);
			glPushMatrix();
			
			
			for(int k=0 ; k<60 ; k++){
				for(int i=0 ; i < 30 ; i += 2){
					for(int j =0 ; j<1000 ; j += 2){
						lines[k][i].particles[j].draw();
					}
				}
			}
			
			
			glPopMatrix();
			glPopMatrix();
		}
};




class grave{
	public:
		float x,y,z;

		void drawquad(){
			//angle++;
			glPushMatrix();
			glTranslatef(x, y, z); 
			glColor3f(1.0f, 1.0f, 1.0f);

			glBegin(GL_QUADS);
			glVertex3f(-0.8f,-0.0f,-8.0f);
			glVertex3f(-0.8f,8.0f,-8.0f);
			glVertex3f(0.8f,8.0f,-8.0f);
			glVertex3f(0.8f,-0.0f,-8.0f);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-3.0f,5.0f,-8.0f);
			glVertex3f(-3.0f,6.0f,-8.0f);
			glVertex3f(3.0f,5.0f,-8.0f);
			glVertex3f(3.0f,6.0f,-8.0f);
			glEnd();

			glColor3f(0, 0, 0);
			glBegin(GL_QUADS);

			glVertex3f(-3.0f,-0.6f,8.0f);
			glVertex3f(-3.0f,0.6f,8.0f);
			glVertex3f(3.0f,0.6f,8.0f);
			glVertex3f(3.0f,-0.6f,8.0f);
			glEnd();


			glPopMatrix();
			glPopMatrix();
		}
};



class Coin{
	public:
		float x,y,z;
		void drawcoin(){
			glPushMatrix();
			glPushMatrix();
			glPopMatrix();
			glTranslatef(x,y,z);
			GLUquadricObj *quadratic;
			quadratic = gluNewQuadric();
			glRotatef(angle,0,1,0);
			glColor3f(1,0.84,0);
			gluDisk(quadratic,0,1.5,35,1);
			glPopMatrix();
		}
};



class keel{
	public:
		float x,y,z;

		void drawrow(){
			glPushMatrix();
			drawcylinder(0.2,0.05,9.0);
			glPushMatrix();
			glTranslatef(1.5,0,0);
			drawcylinder(0.2,0.05,9.0);
			glTranslatef(1.5,0,0);
			drawcylinder(0.2,0.05,9.0);
			glTranslatef(1.5,0,0);
			drawcylinder(0.2,0.05,9.0);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-1.5,0,0);
			drawcylinder(0.2,0.05,9.0);
			glTranslatef(-1.5,0,0);
			drawcylinder(0.2,0.05,9.0);
			glTranslatef(-1.5,0,0);
			drawcylinder(0.2,0.05,9.0);
			glPopMatrix();
			glPopMatrix();
		}
		void kaante(){
			glPushMatrix();
			drawrow();
			glPushMatrix();
			glTranslatef(0,1.5,0);
			drawrow();
			glTranslatef(0,1.5,0);
			drawrow();
			glTranslatef(0,1.5,0);
			drawrow();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0,-1.5,0);
			drawrow();
			glTranslatef(0,-1.5,0);
			drawrow();
			glTranslatef(0,-1.5,0);
			drawrow();
			glPopMatrix();
			glPopMatrix();
		}		

		void drawkeel (void) {	
			glPushMatrix();
			//person
			glTranslatef(x,y,z); 
			glRotatef(-90, 1.0, 0.0, 0.0); //rotate on the x axis
			//glRotatef(angle, 1.0, 1.0, 0.0); //rotate on the y axis
			//glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the z axis
			glColor3f(0.1, 0.1, 0.1);
			glPushMatrix();
			kaante();
			glPopMatrix();
			glPopMatrix();
		}
};




class aag{
	public:
		float x,y,z,a1,a2,a3,a4,a5,a6,a7,a8,a9,ang;
		
		void drawaag (void) {	
			glPushMatrix();
			//person
			glTranslatef(x, y, z);
			glScalef(0.5,0.5,0.5);
			//glRotatef(30, 1.0, 0.0, 0.0); //rotate on the x axis
			//glRotatef(angle, 0.0, 1.0, 0.0); //rotate on the y axis
			//glRotatef(angle, 1.0, 0.0, 0.0); //rotate on the y axis
			//glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the y axis
			glColor3f(1, float((rand()%120)/255.0), 0.0);
			glutSolidSphere(2,32,32);
			glRotatef(-90, 1.0, 0.0, 0.0); //rotate on the y axis
			//glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the z axis
			glColor3f(1, float((rand()%120)/255.0), 0.0);
			drawCylinder(2,0.1,5);
			glPushMatrix();
			glColor3f(1, float((rand()%120)/255.0), 0.0);
			glRotatef(20, 1.0, 1.0, 0.0); //rotate on the y axis
			drawCylinder(2,0.1,5);
			glPopMatrix();

			glPushMatrix();
			glColor3f(1, float((rand()%120)/255.0), 0.0);
			glRotatef(a1, 2.0, 1.0, 0.0); //rotate on the y axis
			drawCylinder(1.7,0.1,4);
			glPopMatrix();

			glPushMatrix();
			glColor3f(1, float((rand()%120)/255.0), 0.0);
			glRotatef(a2, 2.0, 3.0, 0.0); //rotate on the y axis
			drawCylinder(1.7,0.1,4);
			glPopMatrix();


			glPushMatrix();
			glColor3f(1, float((rand()%120)/255.0), 0.0);
			glRotatef(-25, 0.0, 2.0, 0.0); //rotate on the y axis
			drawCylinder(1.7,0.1,4);
			glPopMatrix();

			glPushMatrix();
			glColor3f(1, float((rand()%120)/255.0), 0.0);
			glRotatef(a3, -2.0, -2.5, 0.0); //rotate on the y axis
			drawCylinder(1.7,0.1,4);
			glPopMatrix();

			glPushMatrix();
			glColor3f(1, float((rand()%120)/255.0), 0.0);
			glRotatef(a4, -2.0, -2.5, 0.0); //rotate on the y axis
			drawCylinder(1.7,0.1,4);
			glPopMatrix();


			glPushMatrix();
			glColor3f(1, float((rand()%120)/255.0), 0.0);
			glRotatef(a5, -2.0, 0, 0.0); //rotate on the y axis
			drawCylinder(1.7,0.1,4);
			glPopMatrix();

			glPushMatrix();
			glColor3f(1, float((rand()%120)/255.0), 0.0);
			glRotatef(a6, -2.0, 0, 0.0); //rotate on the y axis
			drawCylinder(1.7,0.1,4);
			glPopMatrix();

			glPushMatrix();
			glColor3f(1, float((rand()%120)/255.0), 0.0);
			glRotatef(a7, 0.0, 1, 0.0); //rotate on the y axis
			drawCylinder(1.7,0.1,4);
			glPopMatrix();

			glPushMatrix();
			glColor3f(1, float((rand()%120)/255.0), 0.0);
			glRotatef(a8, 0.0, -1, 0.0); //rotate on the y axis
			drawCylinder(1.7,0.1,4);
			glPopMatrix();


			glPopMatrix();
		}

		void move()
		{
			ang*=-1;
			a1+=ang;
			a2-=ang;
			a3+=ang;
			a4-=ang;
			a5+=ang;
			a6-=ang;
			a7+=ang;
			a8-=ang;
		}

	
};




class Ball{
	public:
	float x,y,z;
	void drawBall()
	{
			glPushMatrix();
			glTranslatef(x,y,z);
			glColor3f(1,0,0);
			glutSolidSphere(1,10,10);
			glPopMatrix();
	}
};

aag ball;


class Tr{
	public:
		float x,y,z;
		void drawleaf2(){
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			glRotatef(45,1.0,0.0,0.0);			
			drawcylinder(0.1,0.1,2.0);
			glTranslatef(0,0,1);
			glRotatef(45,1,0,0);
			drawcylinder(0.1,0.1,4.0);

			glPopMatrix();
		}
		void drawleaf(){
			glPushMatrix();
			glRotatef(-45,1.0,0.0,0.0);			
			drawcylinder(0.1,0.1,2.0);
			glTranslatef(0,0,1);
			glRotatef(275,1,0,0);
			drawcylinder(0.1,0.1,4.0);

			glPopMatrix();
		}

		void drawbranch(){
			glPushMatrix();

			glColor3f(0.3, 0.1, 0.0);		//first part of leaf
			drawcylinder(0.15,0.15,4.0);


			glPushMatrix();					//leaves
			glTranslatef(0.0,0.0,2);		//go the place on the branch to draw the leaf
			drawleaf();
			glPopMatrix();


			glPushMatrix();	//second part of leaf

			glTranslatef(0.0,0.0,4.0);
			glRotatef(-40,0.0,1.0,0.0);
			drawcylinder(0.15,0.15,5.0);

			glPushMatrix();					//leaves
			glTranslatef(0.0,0.0,2);		//go the place on the branch to draw the leaf
			drawleaf2();
			glPopMatrix();

			glPopMatrix();


			glPopMatrix(); // for one branch
		}
		void drawbranch2(){
			glPushMatrix();

			glColor3f(0.3, 0.1, 0.0);		//first part of leaf
			drawcylinder(0.15,0.15,4.0);


			glPushMatrix();					//leaves
			glTranslatef(0.0,0.0,2);		//go the place on the branch to draw the leaf
			drawleaf2();
			glPopMatrix();


			glPushMatrix();	//second part of leaf

			glTranslatef(0.0,0.0,4.0);
			glRotatef(-40,0.0,1.0,0.0);
			drawcylinder(0.15,0.15,5.0);

			glPushMatrix();					//leaves
			glTranslatef(0.0,0.0,2);		//go the place on the branch to draw the leaf
			drawleaf();
			glPopMatrix();

			glPopMatrix();


			glPopMatrix(); // for one branch
		}


		void drawTr (void) {	
			glPushMatrix();
			//person
			glTranslatef(x, y, z); 
			glRotatef(90, 1.0, 0.0, 0.0); //rotate on the x axis
			//glRotatef(angle, 1.0, 1.0, 0.0); //rotate on the y axis
			//glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the z axis
			glColor3f(0.3, 0.1, 0.0);

			//for trunk
			//glTranslatef(0,0,5.4); 
			GLUquadricObj *quadratic1;
			quadratic1 = gluNewQuadric();
			gluCylinder(quadratic1,0.5f,1.2f,14.0f,32,32);


			glPushMatrix();			//start branches
			glRotatef(135,0,1.0,0.0); 	//rotate for branches
			drawbranch();
			glPopMatrix();			

			glPushMatrix();			//start branches
			glRotatef(90,0.0,0.0,1.0); 	//rotate for branches
			glRotatef(130,0,1.0,0.0); 	//rotate for branches	
			drawbranch2();
			glPopMatrix();

			glPushMatrix();			//start branches
			glRotatef(170,0.0,0.0,1.0); 	//rotate for branches
			glRotatef(120,0,1.0,0.0); 	//rotate for branches	
			drawbranch();
			glPopMatrix();

			glPushMatrix();			//start branches
			glRotatef(290,0.0,0.0,1.0); 	//rotate for branches
			glRotatef(160,0,1.0,0.0); 	//rotate for branches	
			drawbranch2();
			glPopMatrix();



			glPopMatrix();	//final pop
		}
};

class Heart{
	public:
		float x,y,z,r,g,b;
		void drawHeart () {	
			glPushMatrix();
			glColor3f(r,g,b);
			glTranslatef(x,y,z);
			glScalef(1.4,1.4,1.4);
			glRotatef(angle, 0.0, 1.0, 0.0); //rotate on the y axis

			glRotatef(180,0,1,0);
			glRotatef(90,1,0,0);
			glPushMatrix();
			glRotatef(13,0,1,0);
			glutSolidCone(1 ,2.3, 10, 10); 

			glPushMatrix();
			glTranslatef(0.0f, 0.0f, 0.0f); 
			glutSolidSphere(0.95,10,10);
			glPopMatrix();
			glPopMatrix();


			glTranslatef(1.0f,0.0f, 0.0f);
			glRotatef(-13,0,1,0);
			glutSolidCone(1 ,2.3, 10, 10); 

			glRotatef(-180.0f,1.0f, 0.0f, 0.0f);

			glPushMatrix();
			glTranslatef(0.0f, 0.0f, 0.0f); 
			glutSolidSphere(0.95,10,10);
			glPopMatrix();
			glPopMatrix();

		}
};


class Bomb{
	public:
		float x,y,z;

		void drawpoint(){
			glPushMatrix();			
			glutSolidCone(1.0,2.5,32,32);
			glRotatef(30,1,0,0);
			glutSolidCone(1.0,2.5,32,32);
			glRotatef(30,1,0,0);
			glutSolidCone(1.0,2.5,32,32);
			glRotatef(30,1,0,0);
			glutSolidCone(1.0,2.5,32,32);
			glRotatef(30,1,0,0);
			glutSolidCone(1.0,2.5,32,32);
			glRotatef(30,1,0,0);
			glutSolidCone(1.0,2.5,32,32);
			glRotatef(30,1,0,0);
			glutSolidCone(1.0,2.5,32,32);
			glRotatef(30,1,0,0);
			glutSolidCone(1.0,2.5,32,32);
			glRotatef(30,1,0,0);
			glutSolidCone(1.0,2.5,32,32);
			glRotatef(30,1,0,0);
			glutSolidCone(1.0,2.5,32,32);
			glRotatef(30,1,0,0);
			glutSolidCone(1.0,2.5,32,32);
			glRotatef(30,1,0,0);
			glutSolidCone(1.0,2.5,32,32);
			glPopMatrix();

		}
		void drawBomb (void) {	
			glPushMatrix();
			//person
			glTranslatef(x, y, z); 
			//glRotatef(30, 1.0, 0.0, 0.0); //rotate on the x axis
			//glRotatef(angle, 1.0, 1.0, 0.0); //rotate on the y axis
			//glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the z axis
			glColor3f(0.0, 0.0, 0.0);

			//for trunk
			glTranslatef(0,0,5.4); 
			glutSolidSphere(1.9,32,32);			

			glPushMatrix();
			drawpoint();
			glRotatef(30,0,1,0);
			drawpoint();
			glRotatef(30,0,1,0);
			drawpoint();
			glRotatef(30,0,1,0);
			drawpoint();
			glRotatef(30,0,1,0);
			drawpoint();
			glRotatef(30,0,1,0);
			drawpoint();

			glPopMatrix();
			glPopMatrix();	//final pop
		}
};

class Blast{
	public: 
		float x,y,z;
		void drawBlast(){
			glPushMatrix();
			glTranslatef(x,y,z);
			glColor4f(1.0, 0.0, 0.0,0.6);
			glutSolidSphere(bombradius,32,32);			
			glPopMatrix();
		}
};




class Tree{
	public:
		float x,y,z;
		void drawleaf(){
			glPushMatrix();
			glRotatef(-45,1.0,0.0,0.0);	
			drawcylinder(0.2,0.4,2.0);
			glTranslatef(0.0,0.0,2.0);
			drawcylinder(0.4,0.1,1.0);
			//opposite side leaf
			glTranslatef(0.0,0.0,-2.0);
			glRotatef(90,1.0,0.0,0);	
			drawcylinder(0.2,0.4,2.0);
			glTranslatef(0.0,0.0,2.0);
			drawcylinder(0.4,0.1,1.0);
			glPopMatrix();
		}

		void drawendleaf(){
			glPushMatrix();	
			drawcylinder(0.2,0.5,2.5);
			glTranslatef(0.0,0.0,2.5);
			drawcylinder(0.5,0.1,1.5);
			glPopMatrix();
		}
		void drawbranch(){
			glPushMatrix();
			glColor3f(0.3, 0.1, 0.0);	//first part of leaf
			drawcylinder(0.2,0.2,4.0);
			glPushMatrix();	//leaves
			glTranslatef(0.0,0.0,1);	//go the place on the branch to draw the leaf
			glColor3f(0.0,0.3,0.0);	
			drawleaf();
			glPopMatrix();
			glPushMatrix();	//leaves
			glTranslatef(0.0,0.0,3.0);	//go the place on the branch to draw the leaf
			glColor3f(0.0,0.3,0.0);	
			drawleaf();
			glPopMatrix();
			glPushMatrix();	
			glColor3f(0.3, 0.1, 0.0);	//second part of leaf
			glTranslatef(0.0,0.0,4.0);
			glRotatef(-80,0.0,1.0,0.0);
			drawcylinder(0.2,0.2,5.0);
			glPushMatrix();	//leaves
			glTranslatef(0.0,0.0,1);	//go the place on the branch to draw the leaf
			glColor3f(0.0,0.3,0.0);	
			drawleaf();
			glPopMatrix();
			glPushMatrix();	//leaves
			glTranslatef(0.0,0.0,3.0);	//go the place on the branch to draw the leaf
			glColor3f(0.0,0.3,0.0);	
			drawleaf();
			glPopMatrix();
			glPushMatrix();	//leaves
			glTranslatef(0.0,0.0,5.0);	//go the place on the branch to draw the leaf
			glColor3f(0.0,0.3,0.0);	
			drawendleaf();
			glPopMatrix();
			glPopMatrix();
			glPopMatrix(); // for one branch
		}
		void drawTree () {	
			glPushMatrix();
			//person
			glTranslatef(x,y,z); 
			//glRotatef(30, 1.0, 0.0, 0.0); //rotate on the x axis
			glRotatef(90, 1.0, 0.0, 0.0); //rotate on the y axis
			//glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the z axis
			glColor3f(0.3, 0.1, 0.0);
			//for trunk
			//glTranslatef(0,0,5.4); 
			GLUquadricObj *quadratic1;
			quadratic1 = gluNewQuadric();
			gluCylinder(quadratic1,0.8f,2.5f,13.0f,32,32);
			glPushMatrix();	//start branches
			glRotatef(135,0,1.0,0.0); //rotate for branches
			drawbranch();
			glPopMatrix();	
			glPushMatrix();	//start branches
			glRotatef(60,0.0,0.0,1.0); //rotate for branches
			glRotatef(132,0,1.0,0.0); //rotate for branches	
			drawbranch();
			glPopMatrix();
			glPushMatrix();	//start branches
			glRotatef(120,0.0,0.0,1.0); //rotate for branches
			glRotatef(140,0,1.0,0.0); //rotate for branches	
			drawbranch();
			glPopMatrix();
			glPushMatrix();	//start branches
			glRotatef(180,0.0,0.0,1.0); //rotate for branches
			glRotatef(136,0,1.0,0.0); //rotate for branches	
			drawbranch();
			glPopMatrix();
			glPushMatrix();	//start branches
			glRotatef(240,0.0,0.0,1.0); //rotate for branches
			glRotatef(130,0,1.0,0.0); //rotate for branches	
			drawbranch();
			glPopMatrix();
			glPushMatrix();	//start branches
			glRotatef(300,0.0,0.0,1.0); //rotate for branches
			glRotatef(142,0,1.0,0.0); //rotate for branches	
			drawbranch();
			glPopMatrix();
			glPopMatrix();	//final pop
		}
};





class Boat{
	public:
		float x,y,z;
		void drawBoat (void) {	
			glPushMatrix();
			//person
			glTranslatef(x,y,z);
			//glutSolidSphere(1,32,32);
			glRotatef(90,0,1,0);
			glRotatef(-90,0,0,1);
			//glRotatef(30, 1.0, 0.0, 0.0); //rotate on the x axis
			//glRotatef(angle, 1.0, 1.0, 0.0); //rotate on the y axis
			//glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the z axis
			glColor3f(0.3, 0.1, 0.0);
			glPushMatrix();
			//glTranslatef(0,0,5.4); 
			drawCylinder(0.5,0.5,11);
			glPushMatrix();
			glTranslatef(0,1.5,0); 
			drawCylinder(0.5,0.5,11);
			glTranslatef(0,1.5,0); 
			drawCylinder(0.5,0.5,11);
			glTranslatef(0,1.5,0); 
			drawCylinder(0.5,0.5,11);
			glTranslatef(0,1.5,0); 
			drawCylinder(0.5,0.5,11);
			glTranslatef(0,1.5,0); 
			drawCylinder(0.5,0.5,11);

			glPopMatrix();
			//black 
			glPushMatrix();
			glColor3f(0.0, 0.0, 0.0);
			glRotatef(-90,1,0,0);
			glTranslatef(0.0,0.0,-2.0);	//for x  axis: shifts above the brown 
			glTranslatef(0.0,-2.0,0.0);
			drawCylinder(0.3,0.3,12);
			glTranslatef(0,-1.5,0); 
			drawCylinder(0.3,0.3,12);
			glTranslatef(0,-1.5,0); 
			drawCylinder(0.3,0.3,12);
			glTranslatef(0,-1.5,0); 
			drawCylinder(0.3,0.3,12);
			glTranslatef(0,-1.5,0); 
			drawCylinder(0.3,0.3,12);
			glTranslatef(0,-1.5,0); 
			drawCylinder(0.3,0.3,12);
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
			glColor3f(0.3, 0.1, 0.0);
		}
};

class DeadPerson{
	public:
		float x,y,z;
		float leg_angle,arm_2nd,arm_angle,leg_2nd;
	void drawPerson (void) {	
		glPushMatrix();
		//person
		glTranslatef(x,y,z);
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glRotatef(90.0f,1.0f, 0.0f, 0.0f);
		glTranslatef(0,0,-3);
		drawCylinder(0.08,0.08,3);
		glPopMatrix();
		glRotatef(rotang,0.0,1.0,0.0);
		arm_2nd=-30.0;
		glColor3f(0, 1, 0.0);
		//head
		glutSolidSphere( 1.0, 20.0, 20.0); 


		//eyes
		glPushMatrix();
		glRotatef(90.0f,1.0f, 0.0f, 0.0f);
		glTranslatef(-0.4f,0.7f,-0.4f); // eyes coming closer by changing y axis and up/down by changing z-axis
		glColor3f(0.0, 0.0, 0.0);
		glutSolidSphere( 0.2, 20.0, 20.0); 
		glTranslatef(0.8,0.0,0.0);
		glutSolidSphere( 0.2, 20.0, 20.0); 
		glTranslatef(0.0f,0.0f,0.8f);
		glBegin(GL_LINES);
		glVertex3f(-0.8f,0.2f,0.0f);
		glVertex3f(0.0f,0.2f,0.0f);
		glEnd();
		glPopMatrix();
		
		
		//body
		glPushMatrix();
		glTranslatef(-0.1f,-0.7f, -0.4f);   
		glRotatef(90.0f,1.0f, 0.0f, 0.0f);
		glEnable(GL_TEXTURE_2D);
	   
		
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glColor3f(0.0f,0.0f,0.0f);
		gluCylinder(quadratic,0.8f,1.1f,3.5f,32,32);
        
		//right hand up
		glPushMatrix();
		glTranslatef(-0.3f,0.2f, 0.4f); // z-axis for up & down  
		glRotatef(-50.0f,0.0f, 1.0f, 0.0f);


		GLUquadricObj *quadratic1;
		quadratic1 = gluNewQuadric();
		glColor3f(0,1,0.0f);
		gluCylinder(quadratic1,0.35f,0.25f,1.8f,32,32);
		
		//right hand down
		glPushMatrix();
		glTranslatef(-0.05f,0.0f,1.5f);//y axis for moving close and far && x-axis for left(-ve)-right(+ve)
		
		glRotatef(35.0,0.0f, 1.0f, 0.0f);
		glRotatef(arm_angle+arm_2nd,1.0f, 0.0f, 0.0f);
		
		
		GLUquadricObj *quadratic2;
		quadratic2 = gluNewQuadric();
		gluCylinder(quadratic2,0.25f,0.15f,1.5f,32,32);
		
	
		glPopMatrix();
		glPopMatrix();
		
		
		//left hand up
		
		glPushMatrix();
		glTranslatef(0.3f,0.2f, 0.4f);  
		glRotatef(50.0f,0.0f, 1.0f, 0.0f);
		glColor3f(0,1,0.0f);
		GLUquadricObj *quadratic3;
		quadratic3 = gluNewQuadric();
		gluCylinder(quadratic3,0.35f,0.25f,1.8f,32,32);
		
		//left hand down
		glPushMatrix();
		glTranslatef(0.05f,0.0f,1.5);
		
		glRotatef(-35.0,0.0f, 1.0f, 0.0f);
		glRotatef(-arm_angle,1.0f, 0.0f, 0.0f);

		GLUquadricObj *quadratic7;
		quadratic7 = gluNewQuadric();
		gluCylinder(quadratic7,0.25f,0.15f,1.5f,32,32);
	
		glPopMatrix();
		glPopMatrix();
		
		
		

		
		//right leg up
		glPushMatrix();
		glTranslatef(0.6f,-0.0f, 2.7f);  
		glRotatef(leg_angle,1.0f,0.0f,0.0f);
		glColor3f(0,1,0.0f);
		GLUquadricObj *quadratic11;
		quadratic11 = gluNewQuadric();
		gluCylinder(quadratic11,0.4f,0.25f,2.0f,32,32);
		
		//right knee
		glPushMatrix();
		glTranslatef(-0.0f,-0.0f, 2.1f); 
		glutSolidSphere( 0.35, 20.0, 20.0);
		
		
		//right leg down
		glPushMatrix();
		glTranslatef(-0.0f,-0.0f, 0.21f);  
		glRotatef(leg_2nd,0,1,0.0f);
		//glRotatef(60.0f,0.0f, 1.0f, 0.0f);
		GLUquadricObj *quadratic12;
		quadratic12 = gluNewQuadric();
		gluCylinder(quadratic12,0.3f,0.2f,1.3f,32,32);
		
		
		
		//right foot
		glPushMatrix();
		glTranslatef(0.0f,-0.0f, 1.3f);
		glColor3f(0.0, 0.0, 0.0);  
		glBegin(GL_TRIANGLES);
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.0f);
		glEnd();
		
		
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		
		
		
		//left leg up
		glPushMatrix();
		glTranslatef(-0.6f,-0.0f, 2.7f);  
		glRotatef(-leg_angle,1.0f,0.0f,0.0f);
		glColor3f(0,1,0.0f);
		GLUquadricObj *quadratic5;
		quadratic5 = gluNewQuadric();
		gluCylinder(quadratic5,0.4f,0.25f,2.0f,32,32);
		
		//left knee
		glPushMatrix();
		glTranslatef(-0.0f,-0.0f, 2.1f); 
		glutSolidSphere( 0.35, 20.0, 20.0);
		
		
		//left leg down
		glPushMatrix();
		glTranslatef(-0.0f,-0.0f, 0.21f);  
		glRotatef(-leg_2nd,0.0f,1.0f,0.0f);
		//glRotatef(60.0f,0.0f, 1.0f, 0.0f);
		GLUquadricObj *quadratic8;
		quadratic8 = gluNewQuadric();
		gluCylinder(quadratic8,0.3f,0.2f,1.3f,32,32);
		
		
		
		//left foot
		glPushMatrix();
		glTranslatef(0.0f,-0.0f, 1.3f); 
		glColor3f(0.0, 0.0, 0.0); 
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.0f);
		glEnd();
		
		
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		glPopMatrix();
		glPopMatrix();
	}
	
};




class Bhoot{
	public:
		float x,y,z,ban;
	void drawBhoot (void) {	
		glPushMatrix();
		//person
		glTranslatef(x, y, z); 
		//glRotatef(angle, 1.0, 0.0, 0.0); //rotate on the x axis
		//glRotatef(180, 0.0, 1.0, 0.0); //rotate on the y axis
		//glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the z axis
		glColor4f(1.0, 1.0, 1.0,1);
		glPushMatrix();
		glRotatef(90, 1.0, 0.0, 0.0);

		glutSolidSphere(1.0,32,32);

		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		
		glTranslatef(0.6,0.6,-0.2);
		glutSolidSphere(0.1,32,32);
		glTranslatef(-1.2,0,0);
		glutSolidSphere(0.1,32,32);
		glPopMatrix();

		glColor4f(1.0, 1.0, 1.0,1);
		
		glPushMatrix();
		glTranslatef(0,0,1);
		glRotatef(30,0,1,0);
		glRotatef(ban,1,0,0);
		drawCylinder(1,2,3);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0,0,1);
		glRotatef(-30,0,1,0);
		glRotatef(-ban,1,0,0);
		drawCylinder(1,2,3);
		glPopMatrix();

		glPushMatrix();
		drawCylinder(1,2,6);
		glPopMatrix();
		
		glPopMatrix();
		glPopMatrix();

	}

	void turn()
	{
		ban*=-1;
	}
};

class Spider{
	public:
		float x,y,z;
		int a1,a2,a3,a4,a5,a6,a7,a8,ang;
		void leg(int angle){

			glPushMatrix();
			glRotatef(angle,1,0,0);
			GLUquadricObj *quadratic1;
			quadratic1 = gluNewQuadric();
			gluCylinder(quadratic1,0.15f,0.15f,4.0f,32,32);


			glPushMatrix();
			glTranslatef(0.0f, 0.0f, 4.0f); 
			glRotatef(-100, 1.0, 0.0, 0.0);
			GLUquadricObj *quadratic2;
			quadratic2 = gluNewQuadric();
			gluCylinder(quadratic2,0.15f,0.05f,3.0f,32,32);
			//glPopMatrix();
			glPopMatrix();
			glPopMatrix();

		}

		void drawSpider () {	
			glPushMatrix();
			//person
			glTranslatef(x,y,z); 
			//glRotatef(angle, 1.0, 0.0, 0.0); //rotate on the x axis
			//glRotatef(angle, 0.0, 1.0, 0.0); //rotate on the y axis
			//glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the z axis
			glColor3f(0.0, 0.0, 0.0);
			glPushMatrix();
			glRotatef(90, 1.0, 0.0, 0.0);
			glTranslatef(0,0,5.4); 
			glutSolidSphere(0.5,32,32);
			
			
			glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			glTranslatef(0.2,0.2,-0.1); 
			glutSolidSphere(0.1,32,32);
			glTranslatef(-0.4,0.2,0); 
			glutSolidSphere(0.1,32,32);
			glPopMatrix();


			glColor3f(0.0, 0.0, 0.0);
			glTranslatef(0,0,0.2); 
			//glRotatef(20, 0.0, 0.0, 1.0);
			leg(a1);
			glRotatef(45, 0.0, 0.0, 1.0);
			leg(a2);
			glRotatef(90, 0.0, 0.0, 1.0);
			leg(a3);
			glRotatef(135, 0.0, 0.0, 1.0);
			leg(a4);
			glRotatef(180, 0.0, 0.0, 1.0);
			leg(a5);
			glRotatef(225, 0.0, 0.0, 1.0);
			leg(a6);
			glRotatef(270, 0.0, 0.0, 1.0);
			leg(a7);
			glRotatef(315, 0.0, 0.0, 1.0);
			leg(a8);
			glPopMatrix();
			glPopMatrix();

		}

		void move()
		{
			ang*=-1;
			a1+=ang;
			a2-=ang;
			a3+=ang;
			a4-=ang;
			a5+=ang;
			a6-=ang;
			a7+=ang;
			a8-=ang;
		}
};


class Shark{
	public:
		float x,y,z;
	void drawShark (void) {	
		glPushMatrix();
		glTranslatef(x, y, z); 
		//glRotatef(angle, 1.0, 0.0, 0.0); //rotate on the x axis
		//glRotatef(-angle1, 0.0, 1.0, 0.0); //rotate on the y axis
		glTranslatef(30.0f,0,0);
		//glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the z axis
		glColor3f(0.0, 0.0, 0.0);
		glRotatef(-90,0,0,1);
		if(sharkturn==1)
			glRotatef(180,1,0,0);
		
		glPushMatrix();
		glBegin(GL_TRIANGLES);		// Drawing Using Triangles
		glVertex3f(0.0f, 0.0f, 0.0f);		// Top
		glVertex3f(2.0f,0.5f, 0.0f);		// Bottom Left
		glVertex3f(2.0f,2.0f, 0.0f);		// Bottom Right
		glEnd();
		glBegin(GL_QUADS);		// Drawing Using Triangles
		glVertex3f(2.0f, 0.5f, 0.0f);		// Top
		glVertex3f(4.0f, 0.5f, 0.0f);		// Top
		glVertex3f(4.0f, 3.0f, 0.0f);		// Top
		glVertex3f(2.0f, 2.0f, 0.0f);		// Top
		glEnd();

		
		glPopMatrix();
		glPopMatrix();

	}
};

class Person{
	public:
		float x,y,z,shoulder_angle,arm_angle;
		void drawPerson () {	
			glPushMatrix();
			//person
			glTranslatef(x,y,z);
			if(turn==1)
				glRotatef(90, 0.0, 1.0, 0.0); 
			else if(turn==2)
				glRotatef(-90, 0.0, 1.0, 0.0); 
			else if(turn==3)
				glRotatef(180, 0.0, 1.0, 0.0); 
		//	glRotatef(angle1, 1.0, 0.0, 0.0); //rotate on the x axis
		//	glRotatef(angle1, 0.0, 1.0, 0.0); //rotate on the y axis
		//	glRotatef(angle1, 0.0, 0.0, 1.0); //rotate on the z axis
			//head
			glColor3f(0.9, 0.42, 0.28);
			//pagdi
			glPushMatrix();
			glTranslatef(0.0f,0.48f, 0.0f);   
			glRotatef(90.0f,1.0f, 0.0f, 0.0f);
			glColor3f(0.9, 0.0, 0.0);
			glutSolidTorus(0.6, 0.72, 10, 10);
			glPushMatrix();
			glRotatef(180.0f,1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f,0.0f, 0.5f);   
			glutSolidCone(0.5 ,1, 10, 10); 
			glPopMatrix();
			glPopMatrix();


			glColor3f(0.9, 0.42, 0.28);
			glutSolidSphere( 1.0, 20.0, 20.0);
			glPushMatrix();
			glColor3f(0.0, 0.0,0.0);
			if(turn==1||turn==2)
			glRotatef(-90.0f,1.0f, 0.0f, 0.0f);
			else
			glRotatef(90.0f,1.0f, 0.0f, 0.0f);
			glTranslatef(0.48f,-0.6f, 0.0f);   
			glutSolidSphere(0.26, 20.0, 20.0);
			glTranslatef(-0.96f,0.0, 0.0f);   
			glutSolidSphere(0.26, 20.0, 20.0);
			glTranslatef(0.48f,+1.2f, 0.0f);
			glutSolidSphere(0.5, 20.0, 20.0);
			glTranslatef(0.0f,0.0f,+0.2f);
			glutSolidSphere(0.43, 20.0, 20.0);
			glTranslatef(0.0f,0.0f,+0.4f);
			glutSolidSphere(0.29, 20.0, 20.0);

			glPopMatrix();
			glColor3f(0.9, 0.42, 0.28);


			//body
			glPushMatrix();
			glTranslatef(0.0f,-1.4f, 0.0f);   
			glRotatef(90.0f,1.0f, 0.0f, 0.0f);
			glColor3f(1.0, 0.27, 0.0);
			glutSolidSphere( 1.0, 20.0, 20.0); 
			drawCylinder(1.1f,1.0f,2.7f);

			//frock
			glPushMatrix();
			glRotatef(180.0f,1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f,0.0f, -3.3f);   
			glColor3f(1.0, 0.27, 0.0);
			glutSolidCone(1.7 ,5.5, 10, 10); 
			glPopMatrix();
			glColor3f(0.9, 0.42, 0.28);

			//right shoulder
			glPushMatrix();
			glTranslatef(0.0f,0.0f, -0.8f); 
			glRotatef(-50.0f,0.0f, 1.0f, 0.0f);
			if((turn==1||turn==2) && firstView!=1 && backView!=1)
			glRotatef(+shoulder_angle,0.0f, 0.0f, 1.0f);
			else
			glRotatef(shoulder_angle,1.0f, 0.0f, 0.0f);
			glColor3f(1.0, 0.27, 0.0);
			drawCylinder(0.4f,0.2f,2.2f);
			glColor3f(0.9, 0.42, 0.28);

			//right arm
			glPushMatrix();
			glTranslatef(0.0f,0.0f, 2.1f);  
			glRotatef(30.0f,0.0f, 1.0f, 0.0f);
			drawCylinder(0.2f,0.2f,1.2f);

			//right hand
			glPushMatrix();
			glTranslatef(0.0f,0.0f, 1.2f);  
			glutSolidCube(0.35); 


			//fingers	
			glPushMatrix();
			glLineWidth(2.5f);
			glBegin(GL_LINES);
			glVertex3f(0.0f,0.0f,0.0f);
			glVertex3f(0.0f,0.0f,0.5f);
			glEnd();
			glBegin(GL_LINES);
			glVertex3f(0.1f,0.0f,0.0f);
			glVertex3f(0.1f,0.0f,0.5f);
			glEnd();
			glBegin(GL_LINES);
			glVertex3f(-0.1f,0.0f,0.0f);
			glVertex3f(-0.1f,0.0f,0.5f);
			glEnd();
			glBegin(GL_LINES);
			glVertex3f(0.15f,0.0f,0.0f);
			glVertex3f(0.15f,0.0f,0.5f);
			glEnd();
			glLineWidth(4.5f);
			glBegin(GL_LINES);
			glVertex3f(0.0f,0.0f,0.0f);
			glVertex3f(-0.3f,0.0f,0.3f);
			glEnd();
			glPopMatrix();






			glPopMatrix();
			glPopMatrix();
			glPopMatrix();

			//left shoulder
			glPushMatrix();
			glTranslatef(0.0f,0.1f, -0.8f);  
			glRotatef(50.0f,0.0f, 1.0f, 0.0f);
			if((turn==1||turn==2) && firstView!=1 && backView!=1)
			glRotatef(-shoulder_angle,0.0f, 0.0f, 1.0f);
			else
			glRotatef(-shoulder_angle,1.0f, 0.0f, 0.0f);
			glColor3f(1.0, 0.27, 0.0);
			drawCylinder(0.2f,0.2f,2.2f);
			glColor3f(0.9, 0.42, 0.28);

			//left arm
			glPushMatrix();
			glTranslatef(0.0f,0.0f, 2.1f);  
			glRotatef(-30.0f,0.0f, 1.0f, 0.0f);
			drawCylinder(0.2f,0.2f,1.2f);

			//left hand
			glPushMatrix();
			glTranslatef(0.0f,0.0f, 1.2f);  
			glutSolidCube(0.35); 

			//fingers
			glPushMatrix();
			glLineWidth(2.5f);
			glBegin(GL_LINES);
			glVertex3f(0.0f,0.0f,0.0f);
			glVertex3f(0.0f,0.0f,0.5f);
			glEnd();
			glBegin(GL_LINES);
			glVertex3f(0.1f,0.0f,0.0f);
			glVertex3f(0.1f,0.0f,0.5f);
			glEnd();
			glBegin(GL_LINES);
			glVertex3f(-0.1f,0.0f,0.0f);
			glVertex3f(-0.1f,0.0f,0.5f);
			glEnd();
			glBegin(GL_LINES);
			glVertex3f(0.15f,0.0f,0.0f);
			glVertex3f(0.15f,0.0f,0.5f);
			glEnd();
			glLineWidth(4.5f);
			glBegin(GL_LINES);
			glVertex3f(0.0f,0.0f,0.0f);
			glVertex3f(0.3f,0.0f,0.3f);
			glEnd();
			glPopMatrix();



			glPopMatrix();
			glPopMatrix();
			glPopMatrix();

			//right leg
			glPushMatrix();
			glTranslatef(0.5f,-0.0f, 2.7f);
			if(turn!=1 && turn!=2)
			glRotatef(arm_angle,1.0f, 0.0f, 0.0f);
			glRotatef(10.0f,0.0f, 1.0f, 0.0f);
			if(turn==1 || turn==2)
				glRotatef(arm_angle+30,0.0f, 0.0f, 1.0f);
			drawCylinder(0.4f,0.2f,1.5f);

			//right knee
			glPushMatrix();
			glTranslatef(0.0f,0.0f, 1.5f);  
			glRotatef(-19.0f,0.0f, 1.0f, 0.0f);
			drawCylinder(0.2f,0.16f,1.2f);

			//right foot
			glPushMatrix();
			glTranslatef(0.0f,0.0f, 1.2f);  
			glColor3f(0.0, 0.0, 0.0);
			glutSolidCube(0.5); 
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
			glColor3f(0.9, 0.42, 0.28);

			//left leg
			glPushMatrix();
			glTranslatef(-0.5f,-0.0f, 2.7f);  
			if(turn!=1 && turn!=2)
			glRotatef(-arm_angle,1.0f, 0.0f, 0.0f);
			glRotatef(-10.0f,0.0f, 1.0f, 0.0f);
			if(turn==1 || turn==2)
				glRotatef(arm_angle+30,0.0f, 0.0f, 1.0f);
			drawCylinder(0.4f,0.2f,1.5f);

			//left knee
			glPushMatrix();
			glTranslatef(0.0f,0.0f, 1.5f);  
			glRotatef(19.0f,0.0f, 1.0f, 0.0f);
			drawCylinder(0.2f,0.16f,1.2f);

			//left foot
			glPushMatrix();
			glTranslatef(0.0f,0.0f, 1.2f);  
			glColor3f(0.0, 0.0, 0.0);
			glutSolidCube(0.5); 
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();


			//glPopMatrix();
			glPopMatrix();
			glPopMatrix();
		}

		void move(){
			shoulder_angle*=-1;
			arm_angle*=-1;
			//cout<<"dir"<<endl;
			if(direction==0)
				z-=1.0f;
			else if(direction==1)
				x+=1.0f;
			else if(direction==2)
				z+=1.0f;
			else
				x-=1.0f;


		}

		void moveForward(){
			z-=1.0f;
			shoulder_angle*=-1;
			arm_angle*=-1;
		}


		void moveBack(){
			z+=1.0f;
			shoulder_angle*=-1;
			arm_angle*=-1;
		}

		void moveRight(){
			x+=1.0f;
			shoulder_angle*=-1;
			arm_angle*=-1;
			
		}

		void moveLeft(){
			x-=1.0f;
			shoulder_angle*=-1;
			arm_angle*=-1;
		}



};

class Arrow{
	public:
		float x,y,z;
	void drawArrow (void) {	
		glPushMatrix();
		//person
		glTranslatef(x,y,z); 
		glRotatef(arrowangle, 0.0, 1.0, 0.0); //rotate on the y axis
		glColor3f(1.0, 0.0, 0.0);
		glPushMatrix();
		glRotatef(90, 1.0, 0.0, 0.0);


		glPushMatrix();
		drawCylinder(0.4f,0.4f,6.0f);
		
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, 5.8f); 
		glRotatef(140, 1.0, 0.0, 0.0);
		drawCylinder(0.4f,0.4f,3.0f);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(0.0f, 0.0f, 5.8f); 
		glRotatef(-140, 1.0, 0.0, 0.0);
		drawCylinder(0.4f,0.4f,3.0f);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

	}
};


class Tower{
	public:
		float x,y,z;
	void drawTower (void) {	
		glPushMatrix();
		glTranslatef(x,y,z); 
		glColor3f(1.0, 0.0, 0.0);

		glRotatef(270.0f,1.0f, 0.0f, 0.0f);
		glutSolidCone(1.6 ,1.0, 10, 10); 

		glRotatef(-180.0f,1.0f, 0.0f, 0.0f);

		glPushMatrix();
		glColor3f(1.0, 1.0, 0.0);
		glTranslatef(0.0f, 0.0f, 0.0f); 
		drawCylinder(0.6f,0.6f,1.5f);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.54, 0.27, 0.07);
		glTranslatef(0.0f, 0.0f, 1.0f); 
		drawCylinder(1.7f,1.0f,1.0f);
		
		glPushMatrix();
		
		glPushMatrix();
		glColor3f(0.0,0.0,0.0);
		glTranslatef(0.2f, 0.7f, 4.0f); 
		glutSolidCube(1);
		glTranslatef(0.2f, 0.7f, 6.0f); 
		glutSolidCube(1);
		glTranslatef(0.2f, 0.7f, 8.0f); 
		glutSolidCube(1);
		glPopMatrix();
		

		glTranslatef(0.0f, 0.0f, 1.0f); 
		glColor3f(0.95, 0.95, 0.93);
		drawCylinder(1.0f,1.8f,18.0f);

		glPushMatrix();
		glColor3f(0.0, 0.39, 0.0);
		glTranslatef(0.0f, 0.0f, 26.0f); 
		glutSolidSphere( 10.0, 20.0, 20.0); 


		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	}
};

Arrow arrow;
Arrow arrow1;
Tower t1;
Person p1;
Shark s1;
Shark s2;
Spider spi,spi1;
Bhoot b1,b2,b3,b4;
DeadPerson d1;
Boat boat;
Tree tree[10];
Bomb bomb;
Blast blast;
Coin coins[10];
int sikke[10]={9,16,36,40,53,68,79,61,88,94};
int sflag[10];
int di[5]={9,27,51,78,93};
grave graves[10];
float c1_r[5],c1_g[5],c1_b[5];
khoon k1;


static void drawBox(GLfloat size, GLenum type,int fflag)
{
	static GLfloat n[6][3] =
	{
		{-1.0, 0.0, 0.0},
		{0.0, 1.0, 0.0},
		{1.0, 0.0, 0.0},
		{0.0, -1.0, 0.0},
		{0.0, 0.0, 1.0},
		{0.0, 0.0, -1.0}
	};
	static GLint faces[6][4] =
	{
		{0, 1, 2, 3},
		{3, 2, 6, 7},
		{7, 6, 5, 4},
		{4, 5, 1, 0},
		{5, 6, 2, 1},
		{7, 4, 0, 3}
	};
	glEnable(GL_TEXTURE_2D);
	if(fflag==1)
	glBindTexture(GL_TEXTURE_2D, _crateId);
	else if(fflag==2)
	glBindTexture(GL_TEXTURE_2D, _textureId);
	else
	glBindTexture(GL_TEXTURE_2D, _islandId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	GLfloat v[8][3];
	GLint i;

	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

	for (i = 5; i >= 0; i--) {
		glBegin(type);
		glNormal3fv(&n[i][0]);
	glTexCoord2f(0,0);
		glVertex3fv(&v[faces[i][0]][0]);
	glTexCoord2f(1,0);
		glVertex3fv(&v[faces[i][1]][0]);
	glTexCoord2f(0,1);
		glVertex3fv(&v[faces[i][2]][0]);
	glTexCoord2f(1,1);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);
}


void APIENTRY
glutSolidCube1(GLdouble size,int fflag)
{
	  drawBox(size, GL_QUADS,fflag);
}


class Block{
	public:
		float x,y,z,r,g,b,wangle;
		void drawBlock(){
			glPushMatrix();
			//glColor3f(r,g,b);
			glTranslatef(x,y,z); 
			glRotatef(wangle,1.0f, 1.0f, 1.0f);
			glColor3f(1.0, 1.0, 1.0);
			glutSolidCube1(10,1);
			glPopMatrix();
		}

};

class Block2{
	public:
		float x,y,z,r,g,b,wangle;
		void drawBlock(){
			glPushMatrix();
		//	glColor3f(0.48,0.98,0);
			//glColor3f(0.98,0.98,0);
			glColor3f(1.0,1.0,1.0);
			glTranslatef(x,y,z); 
			glRotatef(wangle,1.0f, 1.0f, 1.0f);
			//glColor3f(1.0, 1.0, 1.0);
			glutSolidCube1(10,3);
			glPopMatrix();
		}
};



class Block1{
	public:
		float x,y,z,r,g,b,wangle;
		void drawBlock(){
			glPushMatrix();
			glColor3f(r,g,b);
			glTranslatef(x,y,z); 
			glRotatef(wangle,1.0f, 1.0f, 1.0f);
			glColor3f(0.11, 0.56,1.0);
			glutSolidCube1(10,2);
			glPopMatrix();
		}

};
int randomb[15]={3,7,15,23,34,37,39,41,46,55,61,67,70,81,89};
int dangerb[13]={6,11,27,33,36,45,49,50,66,75,83,93,98};
int teleporta[13]={16,35,67,71,85};
int teleportb[13]={41,1,28,82,18};
int sideblocks[6]={14,28,69,72,88,41};
int upblocks[2]={13,26};
int flagdr[10];
Heart ht[10];
int hearts[10]={2,17,24,39,41,55,69,75,90,93};
Block newblocks[2];


void handleKeypress(unsigned char key, int x, int y) {
	float fraction = 0.6f;
	switch (key) {
		case 'y':
			p1.x=70,p1.y=4,p1.z=-250;
			winflag=1;
			break;
		case 27: //Escape key

			exit(0);
			break;
		case 'f':
			normalView=-1;
			camera=-1;
			backView=-1;
			heliView=-1;
			tileView=-1;
			towerView=-1;
			aircamera=-1;
			firstView = firstView*(-1);
			//cout<<firstView<<endl;
			glutPostRedisplay();
			break;
		case 'b':
			normalView=-1;
			firstView=-1;
			camera=-1;
			heliView=-1;
			tileView=-1;
			towerView=-1;
			aircamera=-1;
			backView = backView*(-1);
			glutPostRedisplay();
			break;
		case 'c':
			normalView=1;
			firstView=-1;
			backView=-1;
			tileView=-1;
			heliView=-1;
			towerView=-1;
			aircamera=-1;
			camera=camera*(-1);
			break;
		case 'v':
			normalView=1;
			firstView=-1;
			backView=-1;
			tileView=-1;
			heliView=-1;
			towerView=-1;
			camera=-1;
			aircamera=aircamera*(-1);
			break;
		case 'h':
			normalView=1;
			firstView=-1;
			backView=-1;
			camera=-1;
			tileView=-1;
			towerView=-1;
			aircamera=-1;
			heliView=heliView*(-1);
			break;
		case 't':
			normalView=1;
			firstView=-1;
			backView=-1;
			camera=-1;
			heliView=-1;
			towerView=-1;
			aircamera=-1;
			tileView=tileView*(-1);
			break;
		case 'p':
			normalView=1;
			firstView=-1;
			backView=-1;
			camera=-1;
			heliView=-1;
			tileView=-1;
			aircamera=-1;
			towerView=towerView*(-1);
			break;
		case 'a':
			if(onboat==1)
			{
				if(boat.z<-190 && boat.x<85){
				boat.z+=0.05;
				boat.x+=0.05;
				}
				else{
				boat.x-=0.1;
				p1.x-=0.1;
				}
			}
			else
			{
				cangle -= 0.01f;
				towercangle -= 0.01f;
				clx = sin(cangle);
				clz = -cos(cangle);
				if(towerView==1){
					towerclx= sin(towercangle);
					towerclz= -cos(towercangle);
				}
			}
			break;
		case 'd':
			if(onboat==1)
			{
				if(boat.z<-190 && boat.x<85){
				boat.z+=0.05;
				boat.x+=0.05;
				}
				else{
				boat.x+=0.1;
				p1.x+=0.1;
				}
			}
			else{
				cangle += 0.01f;
				towercangle += 0.01f;
				clx = sin(cangle);
				clz = -cos(cangle);
				if(towerView==1){
					towerclx= sin(towercangle);
					towerclz= -cos(towercangle);
				}
			}
			break;
		case 'w':
			if(onboat==1)
			{
				if(boat.z<-190 && boat.x<85){
				boat.z+=0.05;
				boat.x+=0.05;
				}
				else{
				boat.z-=0.1;
				p1.z-=0.1;
				}
			}
			else
			{
			if(towerView==1)
			towerpitch+=0.02;
			cx += clx * fraction;
			if(camera==1)
				cz -= clz * fraction;
			else
				cz += clz * fraction;
			}
			break;
		case 's':
			if(onboat==1)
			{
				if(boat.z<-190 && boat.x<85){
				boat.z+=0.05;
				boat.x+=0.05;
				}
				else{
				boat.z+=0.1;
				p1.z+=0.1;
				}
			}
			else
			{
			if(towerView==1)
			towerpitch-=0.02;
			cx -= clx * fraction;
			if(camera==1)
				cz += clz * fraction;
			else
				cz -= clz * fraction;
			}
			break;
		case 'e':
			cly-=0.1;
			break;
		case 'q':
			cly+=0.1;
			break;
		case 'n':
			up+=0.05;
			break;
		case 'm':
			up-=0.05;
			break;
		case 'j':
			if(jumpflag!=1){
			curj=p1.y;
			jpos=p1.y;
			}
			jumpflag=1;
			jflag=0;
			break;
		case 'l':
			normalView=1;
			firstView=-1;
			backView=-1;
			camera=-1;
			heliView=-1;
			tileView=-1;
			aircamera=-1;
			towerView=-1;
			mouse*=-1;
			cout<<"helo"<<endl;
			break;

		glutPostRedisplay();
	}
}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image *image) {
	GLuint textureId;
	glGenTextures(1, &textureId);//first argument is no. of texture we are making room for.      Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId);//Tells opengl which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB,  //let opengl know the format of this "pixels" array
				 image->width, image->height,
				 0,      // border of the image
				 GL_RGB,
				 GL_UNSIGNED_BYTE,
				 image->pixels);
	return textureId; //return the id of the texture
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_BLEND); //Enable alpha blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set the blend function
	glClearColor(wr,wb,wg, 1.0f); //Change the background to sky blue

	
	//Load the floor texture
	Image* image = loadBMP("vtr.bmp");
	Image* image1 = loadBMP("skull.bmp");
	Image* image2 = loadBMP("crate.bmp");
	Image* image3 = loadBMP("grass.bmp");
	Image* image4 = loadBMP("grass1.bmp");
	Image* image5 = loadBMP("soil.bmp");
	Image* image6 = loadBMP("game.bmp");
	_textureId = loadTexture(image);
	_dangerId = loadTexture(image1);
	_crateId = loadTexture(image2);
	_islandId = loadTexture(image3);
	_grassId = loadTexture(image4);
	_graveId = loadTexture(image5);
	_gameId = loadTexture(image6);
	delete image;  //as opengl makes the copy of the pixel array
	delete image1;
	delete image2;
	delete image3;
	delete image4;
	delete image5;
	delete image6;
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 300.0);
}

void chk_turn(){
	if(direction==0)
		turn=0;
	else if(direction==1)
		turn=1;
	else if(direction==2)
		turn=3;
	else
		turn=2;
}



void handleKeypress2(int key, int x, int y) {

	if (key == GLUT_KEY_LEFT){
		if(jumpflag==0 && tileView!=1){
			if(normalView==-1){
			direction--;
			if(direction<0)
				direction=3;
			chk_turn();
			}
			else{
				turn=2;
				direction=3;
				p1.moveLeft();
			}
		}
		if(tileView==1)
			if(selectedtile>0)
				selectedtile-=1;

	}

	if (key == GLUT_KEY_RIGHT){
		if(jumpflag==0 && tileView!=1){
			if(normalView==-1){
			direction++;
			if(direction>3)
				direction=0;
			chk_turn();
			}
			else{
				turn=1;
				direction=1;
				p1.moveRight();
			}
		}
		if(tileView==1)
			selectedtile+=1;

	}

	if (key == GLUT_KEY_UP){
		if(jumpflag==0 && tileView!=1){
			if(normalView==-1)
			p1.move();
			else{
				turn=0;
				direction=0;
				p1.moveForward();
			}
		}
		if(tileView==1)
			if(selectedtile<91)
				selectedtile+=10;
	}

	if (key == GLUT_KEY_DOWN){
		if(jumpflag==0 && tileView!=1)
		{
			if(normalView==-1)
			{
			if(direction+2>3)
				direction-=2;
			else
				direction+=2;
			chk_turn();
			}
			else{
				turn=3;
				direction=2;
				p1.moveBack();
			}
		}
		if(tileView==1)
			if(selectedtile>10)
				selectedtile-=10;

	}

	glutPostRedisplay();

}
Block blocks[100];
Block1 water[1000];
Block2 island[100];
Tr trees[10];
Tr sidet[5];
int kaate[10]={15,42,99,65,77};
keel nails[10];
void drawQuad(float x,float y,float z){

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _dangerId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS); 
	glNormal3f(0.0, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x-5.1,y-0.93,z-5.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x-5.1, y-0.93, z+5.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+5.1, y-0.93, z+5.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+5.1,y-0.93,z-5.1);
	glEnd(); 
	glDisable(GL_TEXTURE_2D);
	//glutPostRedisplay();

}



void gameover(){

	glColor3f(1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _gameId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS); 
	glNormal3f(0.0, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-4,-2.6,-5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(4,-2.6,-5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(4,2.6,-5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-4,2.6,-5);
	glEnd(); 
	glDisable(GL_TEXTURE_2D);
	//glutPostRedisplay();

}


void drawQuad1(float x,float y,float z){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _grassId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPushMatrix();
	glBegin(GL_QUADS); 
	glNormal3f(0.0, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x-3.1,y-0.93,z-3.1);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x-3.1, y-0.93, z+3.1);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+3.1, y-0.93, z+3.1);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+3.1,y-0.93,z-3.1);
	glEnd(); 
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//glutPostRedisplay();
}


void changeblockcolor(){
	int i;
			for(i=0;i<13;i++)
			{
				glPushMatrix();
				glColor3f(blocks[dangerb[i]].r,blocks[dangerb[i]].g,blocks[dangerb[i]].b);
				drawQuad(blocks[dangerb[i]].x,blocks[dangerb[i]].y,blocks[dangerb[i]].z);
				glPopMatrix();
				dangerbflag=1;
			}
}

void drawteleportation(float x,float y,float z,float ta,float tb,float tc){
	glColor4f(0.7,0.9,1,0.6);
	glTranslatef(x,y+4,z);
	glRotatef(arrowangle, 0.0, 1.0, 0.0); //rotate on the y axis
	glRotatef(90,1,0,0);
	glPushMatrix();
	glTranslatef(1,0,0);
	glColor4f(1.0,0.0,0.0,0.3);
	glutSolidSphere(0.15,20,20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2,0,1);
	glColor4f(0.0,0.9,0,0.6);
	glutSolidSphere(0.23,20,20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1,-1,3);
	glColor4f(0.0,0.0,1,0.6);
	glutSolidSphere(0.1,20,20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-1,3);
	glColor4f(1,1,0,0.6);
	glutSolidSphere(0.2,20,20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.5,-1,-0.0);
	glColor4f(0.7,0.9,1,0.6);
	glutSolidSphere(0.21,20,20);
	glPopMatrix();
	glColor4f(ta,tb,tc,0.6);
	drawCylinder(4,4,7);	

}

void teleblocks(){
	int i;
			for(i=0;i<5;i++)
			{
				if(i!=teleportblock)
				{
				glPushMatrix();
				drawteleportation(blocks[teleporta[i]].x,blocks[teleporta[i]].y,blocks[teleporta[i]].z,0,0.74,1);
				glPopMatrix();
				}
			}
}

void handleMouseclick(int button, int state, int x, int y) {

	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			mouse_x=x;
			mouse_y=y;
		}
		else if (button == GLUT_RIGHT_BUTTON)
		{
			theta -= 15;
		}
		else if(button == 3 && zoom <= 3)
		{
			zoom+=0.1;
		}
		else if(button == 4 && zoom >=0)
		{
			zoom-=0.1;
		}
	}
	else{
		mouse_x=0;
		mouse_y=0;

	}
}

void motion1(int x,int y)
{

	float dx = x-mouse_x;
	float dy = y-mouse_y;
	mouse_x=x;
	mouse_y=y;
	x_angle += dx;
	y_angle += dy;

}

void drawgrass(){
		glColor3f(1,1,0);
		drawQuad1(-12,4,-198);
		drawQuad1(-9,4,-198);
		drawQuad1(-6,4,-198);
		drawQuad1(-3,4,-198);
		drawQuad1(0,4,-198);
		drawQuad1(3,4,-198);
		drawQuad1(6,4,-198);
		drawQuad1(9,4,-198);
		drawQuad1(12,4,-198);
		drawQuad1(-12,4,-204);
		drawQuad1(-9,4,-204);
		drawQuad1(-6,4,-204);
		drawQuad1(-3,4,-204);
		drawQuad1(0,4,-204);
		drawQuad1(-12,4,-210);
		drawQuad1(-9,4,-210);
		drawQuad1(-6,4,-210);
		drawQuad1(-3,4,-210);
		drawQuad1(0,4,-210);
		drawQuad1(-12,4,-216);
		drawQuad1(-9,4,-216);
		drawQuad1(-6,4,-216);
		drawQuad1(-3,4,-216);
		drawQuad1(-12,4,-222);
		drawQuad1(-9,4,-222);
		drawQuad1(-6,4,-222);
		drawQuad1(4,4,-203);
}

Rain r1;

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int i;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(gameflag==0)
	{	
		//k1.y-=0.1;
		//k1.draw();
		gameover();
	}


	
	stringstream ss2 (stringstream::in | stringstream::out);
	ss2<<"Score: ";
	ss2<<scorecount;
	//cout<<ss2.str().c_str()<<endl;
	strcpy(scoremsg,ss2.str().c_str());
	
	for(i=0;i<10;i++){
		glPushMatrix();
		if(winflag>=1)
			glColor3f(1,1,1);
		else
			glColor3f((rand()%10)/10.0,(rand()%10)/10.0,(rand()%10)/10.0);
		glTranslatef(-116+i*5,54,-155);
		glScalef(0.06,0.06,0.06);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,scoremsg[i]);
		glPopMatrix();
	}

	if(p1.y<-3)
	{
		gameflag=0;
		cout<<"Game Over"<<endl;
		//exit(0);
	}
	if(bomb.x > p1.x-3 && bomb.x < p1.x+ 3 && bomb.z > p1.z-3 && bomb.z < p1.z+3 && bomb.y < p1.y )
	{
		gameflag=0;
		cout<<"Game Over"<<endl;
		//exit(0);
	}
	if(spi.x > p1.x-5 && spi.x < p1.x+ 5 && spi.z > p1.z-5 && spi.z < p1.z+5 )
	{
		gameflag=0;
		cout<<"Game Over"<<endl;
		//exit(0);
	}


	if(spi1.x > p1.x-5 && spi1.x < p1.x+ 5 && spi1.z > p1.z-5 && spi1.z < p1.z+5 )
	{
		gameflag=0;
		cout<<"Game Over"<<endl;
		//exit(0);
	}

	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, -20.0f);
	//glPopMatrix();
	if(camera==1)
	{
		glTranslatef(cx-20.0f, -20.0f, cz-45.0f);
		glRotatef(x_angle,0,1,0);
		glRotatef(y_angle,1,0,0);
	}
	else if(mouse==1)
	{
		glTranslatef(cx-p1.x, p1.y-20, cz-p1.z);
		glRotatef(x_angle,0,1,0);
		glRotatef(y_angle,1,0,0);
	}

	else if(aircamera==1)
	{
		gluLookAt(	cx,30.0f+up, cz,
				cx+clx,29+cly+up, cz+clz,
				0.0f, 1.0f,  0.0f);
	}
	else if(towerView==1){
		gluLookAt(	t1.x,t1.y+2,t1.z,
				t1.x+towerclx,t1.y+2+towerpitch,t1.z+towerclz,
				0.0f, 1.0f,  0.0f);

	}
	else if(firstView == 1){
		//gluLookAt (p1.x, p1.y+2, p1.z, posX, posY, posZ,0.0,1.0,0.0);
		if(turn==0)
		gluLookAt (p1.x, p1.y+2, p1.z, p1.x, p1.y+1.9, p1.z-5.0, 0.0, 1.0, 0.0);
		else if(turn==1)
		gluLookAt (p1.x, p1.y+2, p1.z, p1.x+5, p1.y+1.9, p1.z, 0.0, 1.0, 0.0);
		else if(turn==2)
		gluLookAt (p1.x, p1.y+2, p1.z, p1.x-5, p1.y+1.9,p1.z, 0.0, 1.0, 0.0);
		else
		gluLookAt (p1.x, p1.y+2, p1.z, p1.x, p1.y+1.9, p1.z+5.0, 0.0, 1.0, 0.0);
	}
	else if(backView==1){
		if(turn==0)
		gluLookAt (p1.x, p1.y, p1.z+15, p1.x, p1.y-1, p1.z-5.0, 0.0, 1.0, 0.0);
		else if(turn==1)
		gluLookAt (p1.x-15, p1.y, p1.z, p1.x, p1.y-1, p1.z, 0.0, 1.0, 0.0);
		else if(turn==2)
		gluLookAt (p1.x+15, p1.y, p1.z, p1.x, p1.y-1, p1.z, 0.0, 1.0, 0.0);
		else
		gluLookAt (p1.x, p1.y, p1.z-15, p1.x, p1.y-1, p1.z+5.0, 0.0, 1.0, 0.0);
	}
	else if(heliView==1){
		gluLookAt (0.0,90.0,-70.0, p1.x, p1.y, p1.z, 0.0, 1.0, 0.0);
	}
	else if(tileView==1){
		gluLookAt (blocks[selectedtile].x,blocks[selectedtile].y-1,blocks[selectedtile].z,p1.x,p1.y,p1.z, 1.0, 0.0, 0.0);
	}
	else
		glTranslatef(-10.0f, -10.0f, -30.0f);
	//glRotatef(-angle1, 0.0f, 1.0f, 0.0f);

	if(fogflag==1)
	{
		GLfloat fogColor[] = {0.05f, 0.05f, 0.05f, 0.2};
		glFogfv(GL_FOG_COLOR, fogColor);
		glFogi(GL_FOG_MODE, GL_EXP);
		glFogf(GL_FOG_DENSITY, 0.05f);
	}


	GLfloat ambientLight[] = {0.6f-dr, 0.4f-dg, 0.2f-db, 0.8f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	
	GLfloat lightColor[] = {1.0f, 0.25f, 0.0f, 1.0f};
	GLfloat lightPos[] = {t1.x, t1.y+2, t1.z, 1.0f};//positioned light source
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	
	GLfloat lightColor1[] = {1.0f, 0.4f, 0.0f, 1.0f};
	GLfloat lightPos1[] = {arrow.x, arrow.y, arrow.z, 1.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	GLfloat lightColor4[] = {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat lightPos4[] = {arrow1.x, arrow1.y, arrow1.z, 1.0f};
	glLightfv(GL_LIGHT4, GL_DIFFUSE, lightColor4);
	glLightfv(GL_LIGHT4, GL_POSITION, lightPos4);
	
	GLfloat lightColor5[] = {1.0f, 1.0f, 0.0f, 1.0f};
	GLfloat lightPos5[] = {ball.x, ball.y, ball.z, 1.0f};
	glLightfv(GL_LIGHT5, GL_DIFFUSE, lightColor5);
	glLightfv(GL_LIGHT5, GL_POSITION, lightPos5);

	if(winflag==0 || winflag==2){
		float ambient[] = {1, 1, 0, 1};
		float position[] = {t1.x,t1.y+10,t1.z, 1};
		float direction[] = {p1.x-t1.x,p1.y-t1.y-5,p1.z-t1.z};

		glLightfv(GL_LIGHT2, GL_AMBIENT, ambient);
		glLightfv(GL_LIGHT2, GL_POSITION, position);
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, direction);
		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 20.0f);
		glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 100.0);

	}


/*	
	GLfloat lightColor2[] = {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat lightPos2[] = {30, 80, -200, 1.0f};
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor2);
	glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);
	*/

	glTranslatef(0.0f, -6.0f, 0.0f);

/*	
	for(int k=0 ; k<60 ; k++){
		for(int i = 0 ; i< 30 ; i++){
			for(int j=0 ; j< 1000 ; j++){
				r1.lines[k][i].particles[j].y1 -= 2;
				r1.lines[k][i].particles[j].y2 -= 2;
			}
		}
	}
	r1.drawRain();
*/


	
	if(winflag==0){
	for(i=0;i<100;i++)
		blocks[i].drawBlock();

	for(i=0;i<10;i++){
		ht[i].y=blocks[hearts[i]].y+10;
		ht[i].x=blocks[hearts[i]].x;
		if(flagdr[i]==1)
			ht[i].drawHeart();
	}

	}


	if(winflag>=1)
	{
		for(i=0;i<100;i++)
			island[i].drawBlock();

		for(i=0;i<10;i++)
			trees[i].drawTr();

		for(i=0;i<5;i++)
			nails[i].drawkeel();
	
		for(i=0;i<6;i++)
			tree[i].drawTree();

		for(i=0;i<8;i++)
			graves[i].drawquad();

		sidet[0].drawTr();
		sidet[1].drawTr();
		sidet[2].drawTr();
		ball.drawaag();
		ball.move();


		for(i=0;i<10;i++)
		{
			if(p1.x>coins[i].x-2 && p1.x<coins[i].x+2 && p1.z>coins[i].z-2 && p1.z<coins[i].x+2)
			{
				if(sflag[i]==1)
					scorecount++;
				sflag[i]=0;
			}
		}


		for(i=0;i<10;i++)
			if(sflag[i]==1)
				coins[i].drawcoin();

		for(i=0;i<5;i++)
		{
			//cout<<"island---> "<<island[kaate[i]].x<<"    "<<island[kaate[i]].z<<endl;
			//cout<<"person--->"<<p1.x<<"    "<<p1.z<<endl;
			if(p1.x>island[kaate[i]].x-5 && p1.x<island[kaate[i]].x+5 && p1.z>island[kaate[i]].z-5 && p1.z<island[kaate[i]].z+5 && upflag==1){
				cout<<"Game is actually over!"<<endl;
				gameflag=0;
			//	exit(0);
			}

		}


		for(i=0;i<5;i++)
		{
			glColor3f(c1_r[i],c1_g[i],c1_b[i]);
			drawQuad(island[di[i]].x,island[di[i]].y+6,island[di[i]].z);
			if(p1.x > island[di[i]].x-5 && p1.x<island[di[i]].x+5 && p1.z>island[di[i]].z-5 && p1.z<island[di[i]].z+5)
			{
				fogflag=1;
				glEnable(GL_FOG);
				fogcount=0;
			}
		}

		if(fogflag==1)
		{
			fogcount++;
			if(fogcount>100)
				glDisable(GL_FOG);
		}
		drawgrass();


	}


	//cout<<p1.y<<"  y  "<<ball.y<<endl;
	//	cout<<p1.x<<"  x  "<<ball.x<<endl;
	//	cout<<p1.z<<"  z  "<<ball.z<<endl;
	if(ball.x > p1.x-5 && ball.x<p1.x+5 && ball.z>p1.z-5 && ball.z<p1.z+5 && ball.y<p1.y+4){
		cout<<"Game Over"<<endl;
		gameflag=0;
		//exit(0);
	}

	if(winflag==0){
	for(i=0;i<2;i++)
		newblocks[i].drawBlock();
	}


	for(i=0;i<1000;i++)
		water[i].drawBlock();
	
	glTranslatef(0.0f, +6.0f, 0.0f);
	if(winflag==0)
	{
		if(timecnt>=20){
			changeblockcolor();
			if(timecnt==40)
				timecnt=0;
		}
	}
	if(winflag==0)
		teleblocks();
	timecnt++;

	//if(turn==1)
	//Draw Person
	//glRotatef(90, 0.0, 1.0, 0.0); 
	boat.drawBoat();
	bomb.drawBomb();
//	tree[0].drawTree();
//	tree[1].drawTree();
//	tree[2].drawTree();
	//tree[2].drawTree();
	//
	if(winflag==0)
	{
		if(bombflag==1)
		{

			blast.x=bufx;
			blast.z=bufz;
			blast.y=-1;
			if(bombcnt<30)
			{
				bombcnt++;
				blast.drawBlast();
			}
			else
				bombflag=0;
		}
	}
	p1.drawPerson();
	s1.drawShark();
	t1.drawTower();
	if(winflag==0)
		arrow.drawArrow();
	else
		arrow1.drawArrow();

	if(winflag>=1)
	{
	spi.drawSpider();
	spi1.drawSpider();
	b1.drawBhoot();
	b2.drawBhoot();
	d1.drawPerson();
	}
	boat.y=water[0].y-1;
	int onblock=0;
//	cout<<"winflag is "<<winflag<<endl;
	if(p1.x>arrow1.x-3 && p1.x < arrow1.x+3 && p1.z>arrow1.z-3 && p1.z<arrow1.z+3)
	{
		cout<<"Win!!"<<endl;
		winflag=2;
	}

	if(p1.x>=-15 && p1.x<85 && p1.z<=-190 && p1.z>=-305)
	{
		onisland=1;
		onboat=0;
		wr=0.05,wg=0.05,wb=0.05;
		if(background_flag==-1){
			background_flag=1;
			initRendering();
		}
		if(jumpflag==0)
			p1.y=4;
			
		onblock=1;
		downflag=0;
	}


	if(winflag==1 && onisland==0)
	{
		for(i=0;i<7;i++)
		{
			glPushMatrix();
			glColor3f((rand()%10)/10.0,(rand()%10)/10.0,(rand()%10)/10.0);
			glTranslatef(0+i*10,message_y,-200);
			glScalef(0.1,0.1,0.1);
			glutStrokeCharacter(GLUT_STROKE_ROMAN,message[i]);
			glPopMatrix();
		}
		if(message_y<5)
		message_y+=0.3;
	}


	if(winflag==2)
	{
		for(i=0;i<8;i++)
		{
			glPushMatrix();
			glColor3f((rand()%10)/10.0,(rand()%10)/10.0,(rand()%10)/10.0);
			if(message1[i]=='n')
				glTranslatef(56,message_y,-300);
			else
				glTranslatef(0+i*10,message_y,-300);
			glScalef(0.1,0.1,0.1);
			glutStrokeCharacter(GLUT_STROKE_ROMAN,message1[i]);
			glPopMatrix();
		}
		if(message_y<5)
			message_y+=0.3;
	}





	//cout<<"x is "<<boat.x<<"   "<<boat.x+12<<endl;
	//cout<<"z is "<<boat.z<<"   "<<boat.z-12<<endl;
	//cout<<"p1 is "<<p1.x<<"    "<<p1.z<<endl;
	if(p1.x>boat.x-1 && p1.x < boat.x+13 && p1.z<boat.z+1 && p1.z> boat.z-13)
	{
		//cout<<"hello"<<endl;
		onblock=1;
		onboat=1;
		p1.y=water[0].y+7;
	}
	else
		onboat=0;
	ttcnt=0;
	for(i=0;i<5;i++)
	{
		if((p1.x > blocks[teleporta[i]].x - 5) && (p1.x<blocks[teleporta[i]].x + 5) && (p1.z>blocks[teleporta[i]].z -5) && (p1.z<blocks[teleporta[i]].z +5) &&(jumpflag==0)){
			if(teleflag!=i)
				telecount=0;
			teleportblock=i;
			ttcnt++;
	//cout<<teleportblock<<endl;
			telecount++;
			ct+=0.03;
			glPushMatrix();
			drawteleportation(blocks[teleporta[i]].x,blocks[teleporta[i]].y,blocks[teleporta[i]].z,0+ct*4,0.74+ct,1+ct);
			glPopMatrix();
			teleflag=i;
			if(telecount==50)
			{
			ct=0.0;
			teleportblock=-1;
			p1.x=blocks[teleportb[i]].x;
			p1.z=blocks[teleportb[i]].z;
			telecount=0;
			}
		}
	}
	if(ttcnt==0)
		teleportblock=-1;
	//cout<<teleportblock<<endl;


	for(i=0;i<100;i++)
	{
		if((p1.x > blocks[i].x - 5) && (p1.x<blocks[i].x + 5) && (p1.z>blocks[i].z -5) && (p1.z<blocks[i].z +5) &&(jumpflag==0)){
			if(drown==0)
				p1.y=blocks[i].y+5.7;
			onblock=1;
			downflag=0;
			if(i==99)
				winflag=1;
			int j;
			for(j=0;j<10;j++)
			{
				if(ht[j].x==blocks[i].x && ht[j].z==blocks[i].z)
				{
					if(flagdr[j]==1)
						scorecount++;
					flagdr[j]=0;
				}
			}
		}
	}


	for(i=0;i<13;i++)
	{
		if((p1.x > blocks[dangerb[i]].x - 5) && (p1.x<blocks[dangerb[i]].x + 5) && (p1.z>blocks[dangerb[i]].z -5) && (p1.z<blocks[dangerb[i]].z +5) &&(jumpflag==0)){
			if(waitflag!=i)
				waitcnt=0;
			waitcnt++;
			waitflag=i;
			if(waitcnt==50){
				drown=1;
				dangerno=dangerb[i];
			}
		}

	}

	if(drown==1)
	{
		if(dangerno!=-1){
		blockdownflag=1;
		blocks[dangerno].y-=0.4f;
		p1.y-=0.4f;
		}
		if(jumpflag==1)
		{
			drown=0;
		}
	}

	if(blockdownflag==1 && drown==0)
		blocks[dangerno].y-=0.4f;





	if(onblock==0 && jumpflag==0)
	{
		downflag=1;
	}

	glEnd();
	glutSwapBuffers();
}

void bhoot_motion(){

	if(bhootflag==0)
	{
		b1.z-=0.5;
		b2.z+=0.5;
	}
	else{
		b2.z-=0.5;
		b1.z+=0.5;
	}

	if(b1.z<-310)
		bhootflag=1;
	if(b1.z>-190)
		bhootflag=0;
	bhootcount++;
	if(bhootcount==20)
	{
		bhootcount=0;
		b1.turn();
		b2.turn();
	}

}

void balls(){
//	cout<<ball.y<<endl;
	if(ball.y<0)
	{
		//deadb=1;
		ball.x=d1.x,ball.y=d1.y+7,ball.z=d1.z;
		int no=rand()%4;
		if(no==0)
			ballflag=0;
		else if(no==1)
			ballflag=1;
		else if(no==2)
			ballflag=2;
		else
			ballflag=3;
		ballx=rand()%6;
		ballz=rand()%6;
	}
	else
	{
	//	cout<<"flag is "<<ballflag<<endl;
		ball.y-=0.5;
		if(ballflag==0)
		{
			ball.x+=ballx;
			ball.z+=ballz;
		}
		else if(ballflag==1)
		{
			ball.x-=ballx;
			ball.z-=ballz;
		}
		else if(ballflag==2)
		{
			ball.x+=ballx;
			ball.z-=ballz;
		}
		else
		{
			ball.x+=ballx;
			ball.z-=ballz;
		}
	}
}


void kaata_laga(){
	int i;
	if(stop==1)
	{
		if(nailcount==15)
		{
		for(i=0;i<5;i++)
			nails[i].y=island[kaate[i]].y-7;
		}
		nailcount+=1;
		if(nailcount==30)
			stop=0;
		if(nailcount>15)
			upflag=0;
	}


	//cout<<"nailcount is "<<nailcount<<endl;
	if(stop==0)
	{
		for(i=0;i<5;i++){
			nails[i].y+=0.5;
			if(nails[i].y>-5)
				upflag=1;
			if(nails[i].y>2)
				stop=1;
			nailcount=0;
		}
	}



}




void update(int value) {
	if(winflag>=1)
	{
	balls();
	kaata_laga();
	}

	angle+=4;
	bomb.y-=1;
	if(bomb.y<-3){
		int i;
		for(i=0;i<100;i++)
			if((bomb.x > blocks[i].x - 6) && (bomb.x<blocks[i].x + 6) && (bomb.z>blocks[i].z -6) && (bomb.z<blocks[i].z +6)){
				cout<<"bomb"<<endl;
				bombflag=1;
				bombcnt=0;
				bufx=bomb.x;
				bufz=bomb.z;
			}
		bomb.y=70;
		bomb.x=rand()%50;
		if(rand()%2==1)
			bomb.x*=-1;
		bomb.z=-1*(rand()%200);
	}


	rotang++;
	bhoot_motion();
	spi_count++;
	if(spi_flag==0)
	{
		spi.x+=0.1;
		spi1.x-=0.1;
	}
	else
	{
		spi.x-=0.1;
		spi1.x+=0.1;
	}
	if(spi_count==4)
	{
		spi.move();
		spi1.move();
		spi_count=0;
	}
	if(spi.x>40)
		spi_flag=1;
	if(spi.x<5)
		spi_flag=0;



	if(shflag==0)
		s1.x++;
	if(s1.x>80)
	{
		s1.z=-35;
		shflag=1;
		sharkturn*=-1;
	}
	if(shflag==1)
		s1.x--;
	if(s1.x<-80)
	{	
		s1.z=-70;
		shflag=0;
		sharkturn*=-1;
	}

	arrowangle+=4;
	int i;
	if(bflag==0){
		for(i=0;i<15;i++)
		{
			if(randomb[i]!=dangerno){
			if(blocks[randomb[i]].y<=3.0)
				blocks[randomb[i]].y+=0.07;
			if(blocks[randomb[i]].y>=3.0)
				bflag=1;
			}
		}
	}
	else{
		for(i=0;i<15;i++){
			if(randomb[i]!=dangerno){
			if(blocks[randomb[i]].y>=-3.0)
				blocks[randomb[i]].y-=0.07;
			if(blocks[randomb[i]].y<=-3.0)
				bflag=0;
			}
		}
	}

	if(sideflag==0){
		for(i=0;i<6;i++)
		{
			sidediff1+=0.01;
			blocks[sideblocks[i]].x+=sidediff1;
			if((p1.x > blocks[sideblocks[i]].x - 5) && (p1.x<blocks[sideblocks[i]].x + 5) && (p1.z>blocks[sideblocks[i]].z -5) && (p1.z<blocks[sideblocks[i]].z +5))
				p1.x+=sidediff1;
			if(sidediff1>=0.5){
				sideflag=1;
				sidediff1=0;
			}
		}
	}
	else{
		for(i=0;i<6;i++){
			sidediff2-=0.01;
			if((p1.x > blocks[sideblocks[i]].x - 5) && (p1.x<blocks[sideblocks[i]].x + 5) && (p1.z>blocks[sideblocks[i]].z -5) && (p1.z<blocks[sideblocks[i]].z +5))
				p1.x+=sidediff2;
			blocks[sideblocks[i]].x+=sidediff2;
			if(sidediff2<=-0.5){
				sideflag=0;
				sidediff2=0;
			}
		}
	}


	if(waflag==0){
		for(i=0;i<1000;i++)
		{
			if(water[i].y<=-4.0)
				water[i].y+=0.02;
			if(water[i].y>=-4.0)
				waflag=1;
		}
	}
	else{
		for(i=0;i<1000;i++){
			if(water[i].y>=-6.0)
				water[i].y-=0.02;
			if(water[i].y<=-6.0)
				waflag=0;
		}
	}




	if(jumpflag==1)
	{
		if(jflag==0){
			//cout<<"a"<<endl;

			if(curj<=jpos+4){
				p1.y+=0.24;
				p1.shoulder_angle-=0.3;
				p1.arm_angle+=1;
				for(i=0;i<100;i++){
					int k,upvalue=0;
					if((p1.x > blocks[i].x - 5) && (p1.x<blocks[i].x + 5) && (p1.z>blocks[i].z -5) && (p1.z<blocks[i].z +5)){
						for(k=0;k<2;k++)
							if(upblocks[k]==i)
								upvalue=20;
						if(p1.y<blocks[i].y+5.7+upvalue)
						{
							if(upvalue!=0)
							{
								if(turn==0)
									p1.z+=0.75;
								else if(turn==1)
									p1.x-=0.75;
								else if(turn==2)
									p1.x+=0.75;
								else
									p1.z-=0.75;

							}
							else
							{
								if(turn==0)
									p1.z+=0.35;
								else if(turn==1)
									p1.x-=0.35;
								else if(turn==2)
									p1.x+=0.35;
								else
									p1.z-=0.35;
							}
							jumpflag=0;
							p1.arm_angle=-30.0f;
							p1.shoulder_angle=-20.0f;
						}
					}
				}
				if(turn==0)
					p1.z-=0.35;
				else if(turn==1)
					p1.x+=0.35;
				else if(turn==2)
					p1.x-=0.35;
				else
				p1.z+=0.35;
				curj+=0.17;
			}
			else
				jflag=1;
			glutPostRedisplay();
		}

		if(jflag==1)
		{
			//cout<<"b"<<endl;
			p1.y-=0.24;
			if(p1.x>=-15 && p1.x<85 && p1.z<=-195 && p1.z>=-305)
			{
			//	cout<<p1.y<<endl;
				if(p1.y<4)
				jumpflag=0;
			}

			if(p1.x>boat.x-1 && p1.x < boat.x+13 && p1.z<boat.z+1 && p1.z> boat.z-13)
			{
				if(p1.y<4.5)
				jumpflag=0;
			}
			//p1.shoulder_angle+=1;
			p1.arm_angle-=1;
			p1.shoulder_angle+=0.3;
				if(turn==0)
				p1.z-=0.25;
				else if(turn==1)
				p1.x+=0.25;
				else if(turn==2)
				p1.x-=0.25;
				else
				p1.z+=0.25;
				for(i=0;i<100;i++){
					int k,upvalue=0;
					if((p1.x > blocks[i].x - 5.8) && (p1.x<blocks[i].x + 5.8) && (p1.z>blocks[i].z -5.8) && (p1.z<blocks[i].z +5.8))
					{
						for(k=0;k<2;k++)
							if(upblocks[k]==i)
								upvalue=20;
						if(p1.y<blocks[i].y+6.9+upvalue)
						{
							if(upvalue!=0)
							{
								if(turn==0)
									p1.z+=0.75;
								else if(turn==1)
									p1.x-=0.75;
								else if(turn==2)
									p1.x+=0.75;
								else
									p1.z-=0.75;


							}
							else{
								if(turn==0)
									p1.z+=0.35;
								else if(turn==1)
									p1.x-=0.35;
								else if(turn==2)
									p1.x+=0.35;
								else
									p1.z-=0.35;
							}
							//p1.z-=0.1;
							jumpflag=0;
							p1.arm_angle=-30.0f;
							p1.shoulder_angle=-20.0f;
						}
					}
				}
				glutPostRedisplay();
		}




	}

	if(downflag==1 && jumpflag==0)
		p1.y-=1.5;

	angle1++;
	glutPostRedisplay();
	glutTimerFunc(10, update, 0);

}


void mypassive(int x, int y)
{
	GLint viewport[4];                  // Where The Viewport Values Will Be Stored
	glGetIntegerv(GL_VIEWPORT, viewport);           // Retrieves The Viewport Values (X, Y, Width, Height)
	GLdouble modelview[16];                 // Where The 16 Doubles Of The Modelview Matrix Are To Be Stored
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);       // Retrieve The Modelview Matrix
	GLdouble projection[16];                // Where The 16 Doubles Of The Projection Matrix Are To Be Stored
	glGetDoublev(GL_PROJECTION_MATRIX, projection);     // Retrieve The Projection Matrix

	GLfloat winX, winY, winZ;               // Holds Our X, Y and Z Coordinates

	winX = x;                  // Holds The Mouse X Coordinate
	winY = y;                  // Holds The Mouse Y Coordinate
	winY = (float)viewport[3] - winY;           // Subtract The Current Mouse Y Coordinate From The Screen Height.
	glReadPixels(winX, winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
	//cout<<posX<<"   "<<posY<<" "<<posZ<<endl;
}


int main(int argc, char** argv) {
//	winflag=1;
	k1.x=0;
	k1.y=3;
	k1.z=-2;
	boat.x=100,boat.y=-5.7,boat.z=-173;
	int i,j,k;
	d1.x=30,d1.y=10,d1.z=-250;
	ball.x=d1.x,ball.y=d1.y+7,ball.z=d1.z;
	ball.a1=40,ball.a2=-50,ball.a3=40,ball.a4=-80,ball.a5=-80,ball.a6=50,ball.a7=50,ball.a8=50;
	ball.ang=10;
	d1.leg_angle=8,d1.arm_2nd=30,d1.arm_angle=40,d1.leg_2nd=-12;
	s1.x=-40.0f;
	s1.y=-2.2f;
	s1.z=-70.0f;
	p1.x=18.0f,p1.y=5.0f,p1.z=-10.0f;
	bomb.x=9,bomb.y=50,bomb.z=-10;
//	p1.x=70,p1.y=4,p1.z=-250;
	//coin.x=p1.x,coin.y=p1.y+10,coin.z=p1.z;
	b1.x=-20,b1.y=5,b1.z=-210;
	b2.x=90,b2.y=5,b2.z=-310;
	b1.ban=3,b2.ban=3,b3.ban=3,b4.ban=3;
	spi.x=20;
	spi.y=4;
	spi.z=-270;
	spi1.x=50;
	spi1.y=4;
	spi1.z=-220;
	spi.ang=3;
	spi1.ang=3;
	spi.a1=120,spi.a2=122,spi.a3=117,spi.a4=124,spi.a5=118,spi.a6=123,spi.a7=115,spi.a8=120;
	spi1.a1=120,spi1.a2=122,spi1.a3=117,spi1.a4=124,spi1.a5=118,spi1.a6=123,spi1.a7=115,spi1.a8=120;
	t1.x=-65.0f;
	t1.y=15.0f;
	t1.z=-170.0f;
	arrow.x=100.0f;
	arrow.y=7.0f;
	arrow.z=-163.0f;
	arrow1.x=-12.0f;
	arrow1.y=7.0f;
	arrow1.z=-290.0f;
	p1.shoulder_angle=-20.0f;
	p1.arm_angle=-30.0f;
	for(i=0;i<10;i++)
	{

		for(j=0;j<10;j++)
		{
			blocks[j+10*i].y=-1.0f;
			blocks[j+10*i].x=-50+j*17;
			blocks[j+10*i].z=-10-i*17;
			blocks[j+10*i].r= (rand()%10)/10.0;
			blocks[j+10*i].g= (rand()%10)/10.0;
			blocks[j+10*i].b= (rand()%10)/10.0;
			blocks[j+10*i].wangle=0.0;
			int vv=0;
			for(k=0;k<2;k++){
				if(upblocks[k]==j+10*i)
				{
					newblocks[k].y=9.0f;
					newblocks[k].x=-50+j*17-vv;
					newblocks[k].z=-10-i*17-vv;
				
				}
			}
		}
	}
	i=0,j=0;

	for(i=0;i<10;i++)
	{
		flagdr[i]=1;
		ht[i].x=blocks[hearts[i]].x;
		ht[i].y=blocks[hearts[i]].y+10;
		ht[i].z=blocks[hearts[i]].z;
		ht[i].r=(rand()%10)/10.0;
		ht[i].g=(rand()%7)/10.0;
		ht[i].b=(rand()%7)/10.0;
	}
	
	for(k=0;k<10;k++)
	{
		trees[k].x=-15+rand()%25;
		trees[k].z=-220+rand()%25;
		trees[k].y=rand()%8+8;
		j++;
	//	if(j==10){
	//		j=0;
	//		i++;
	//	}
	}


	tree[0].x=-16,tree[0].y=11,tree[0].z=-201;
	tree[1].x=12,tree[1].y=12,tree[1].z=-198;
	tree[2].x=-15,tree[2].y=14,tree[2].z=-224;
	tree[3].x=73,tree[3].y=13,tree[3].z=-300;
	tree[4].x=80,tree[4].y=16,tree[4].z=-296;
	tree[5].x=87,tree[5].y=14,tree[5].z=-288;
	graves[0].x=40,graves[0].y=1.8,graves[0].z=-281;
	graves[1].x=48,graves[1].y=1.8,graves[1].z=-281;
	graves[2].x=56,graves[2].y=1.8,graves[2].z=-281;
	graves[3].x=64,graves[3].y=1.8,graves[3].z=-281;
	graves[4].x=38,graves[4].y=1.8,graves[4].z=-275;
	graves[5].x=46,graves[5].y=1.8,graves[5].z=-275;
	graves[6].x=54,graves[6].y=1.8,graves[6].z=-275;
	graves[7].x=62,graves[7].y=1.8,graves[7].z=-275;
	sidet[0].x=-10,sidet[0].y=10,sidet[0].z=-302;
	sidet[1].x=-19,sidet[1].y=10,sidet[1].z=-296;
	sidet[2].x=-14,sidet[2].y=10,sidet[2].z=-277;
//	boat.x=87,boat.y=-5.7,boat.z=-200;

	i=0,j=0;


	for(k=0;k<1000;k++)
	{
			water[k].y=-7.0f;
			water[k].x=-100+j*10;
			water[k].z=20-i*10;
			water[k].r=1.0;
			water[k].g=1.0;
			water[k].b=1.0;
			water[k].wangle=0.0;
			j++;
			if(j==25){
				j=0;
				i++;
			}

	}

	i=0,j=0;

	for(k=0;k<100;k++)
	{
			island[k].y=-2.0f;
			island[k].x=-10+j*10;
			island[k].z=-200-i*10;
			island[k].r=1.0;
			island[k].g=1.0;
			island[k].b=1.0;
			island[k].wangle=0.0;
			j++;
			if(j==10){
				j=0;
				i++;
			}

	}
/*
	r1.x = -35.0;
	r1.y = 200.0;
	r1.z = -50.0;
	for(int k=0 ; k<60 ; k += 2){	
		for(int i=0 ; i < 30 ; i += 2){
			for(int j =0 ; j<1000 ; j += 2){
				int r=rand() % 2;
				if(r%2==0){
					r1.lines[k][i].particles[j].x1 = r1.x + 5*k;
					r1.lines[k][i].particles[j].y1 = r1.y - 10*j;
					r1.lines[k][i].particles[j].z1 = r1.z + 5*i;
					r1.lines[k][i].particles[j].x2 = r1.x + 5*k;
					r1.lines[k][i].particles[j].y2 = r1.y - 10*j - 1.0;
					r1.lines[k][i].particles[j].z2 = r1.z + 5*i;
				}
				else if(r%2==1){
					r1.lines[k][i].particles[j].x1 = r1.x + 10*k;
					r1.lines[k][i].particles[j].y1 = r1.y - 5*j;
					r1.lines[k][i].particles[j].z1 = r1.z + 10*i;
					r1.lines[k][i].particles[j].x2 = r1.x + 10*k;
					r1.lines[k][i].particles[j].y2 = r1.y - 5*j - 1.0;
					r1.lines[k][i].particles[j].z2 = r1.z + 10*i;
				}
			}
		}
	}
*/
	for(k=0;k<5;k++)
	{
		nails[k].x=island[kaate[k]].x;
		nails[k].z=island[kaate[k]].z;
		nails[k].y=island[kaate[k]].y-7;
	}

	for(k=0;k<10;k++)
	{
		c1_r[k]=(rand()%255)/255.0;
		c1_g[k]=(rand()%255)/255.0;
		c1_b[k]=(rand()%255)/255.0;
		sflag[k]=1;
		coins[k].x=island[sikke[k]].x;
		coins[k].z=island[sikke[k]].z;
		coins[k].y=island[sikke[k]].y+7;
	}



	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 900);
	
	glutCreateWindow("CG Project");
	initRendering();
	
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutSpecialFunc(handleKeypress2);
	glutReshapeFunc(handleResize);
	glutPassiveMotionFunc(mypassive);
	glutMouseFunc(handleMouseclick);
	glutMotionFunc(motion1);
	glutTimerFunc(15, update, 0);
	
	glutMainLoop();
	return 0;
}









