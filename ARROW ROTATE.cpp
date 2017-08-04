#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<graphics.h>
using namespace std;

int main(void)
{
   int x1,y1,x2,y2;
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode,"C:\\TC\\BGI");
   double i=0.0;
   while(true)
   {
       arc(320,240,-180-i,495-i,20);
       arc(320,240,-180-i,495-i,30);
       int tri[8];
       tri[0]=320-10*cos(i*M_PI/180);
       tri[1]=240-10*sin(i*M_PI/180);
       tri[2]=320-42*cos(i*M_PI/180);
       tri[3]=240-42*sin(i*M_PI/180);
       tri[4]=320-30*cos(i*M_PI/180+30*M_PI/180);
       tri[5]=240-30*sin(i*M_PI/180+30*M_PI/180);
       tri[6]=tri[0];
       tri[7]=tri[1];
       drawpoly(4,tri);
       line(320-20*cos(i*M_PI/180+M_PI_4),240-20*sin(i*M_PI/180+M_PI_4),320-30*cos(i*M_PI/180+M_PI_4),240-30*sin(i*M_PI/180+M_PI_4));
       i+=0.5;
       delay(5);
       cleardevice();
   }
   getch();
   closegraph();
   return 0;
}
