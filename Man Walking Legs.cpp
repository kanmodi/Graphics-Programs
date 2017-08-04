#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LINEFUNC.h"
#include "CIRCLEFUNC.h"
#include <dos.h>
#include <bits/stdc++.h>
#define PI acos(-1.0)

using namespace std;

struct hermitepoints
{
    double x,y,z,dx,dy;
};

struct point
{
    double x,y,z;
};

hermitepoints hl[6],hr[6];
point pl[14],pr[14];

void hermite(hermitepoints p1,hermitepoints p2,int color,int counter)
{
    for(double t=0;t<=1.0;t+=0.01)
    {
        double x=(2*t*t*t-3*t*t+1)*(p1.x+counter)+(-2*t*t*t+3*t*t)*(p2.x+counter)+(t*t*t-2*t*t+t)*p1.dx+(t*t*t-t*t)*p2.dx;
        double y=(2*t*t*t-3*t*t+1)*p1.y+(-2*t*t*t+3*t*t)*p2.y+(t*t*t-2*t*t+t)*p1.dy+(t*t*t-t*t)*p2.dy;
        putpixel(320+x,240-y,color);
    }
}

void newpointsz(double ang)
{
    for(int i=0;i<6;i++)
    {
        double x=hl[i].x;
        double y=hl[i].y;
        double z=hl[i].z;

        hl[i].x=x*cos(ang)-y*sin(ang);
        hl[i].y=x*sin(ang)+y*cos(ang);
    }

    for(int i=0;i<6;i++)
    {
        double x=hr[i].x;
        double y=hr[i].y;
        double z=hr[i].z;

        hr[i].x=x*cos(ang)+y*sin(ang);
        hr[i].y=-x*sin(ang)+y*cos(ang);
    }

    for(int i=0;i<14;i++)
    {
        double x=pl[i].x;
        double y=pl[i].y;
        double z=pl[i].z;

        pl[i].x=x*cos(ang)-y*sin(ang);
        pl[i].y=x*sin(ang)+y*cos(ang);
    }

    for(int i=0;i<14;i++)
    {
        double x=pr[i].x;
        double y=pr[i].y;
        double z=pr[i].z;

        pr[i].x=x*cos(ang)+y*sin(ang);
        pr[i].y=-x*sin(ang)+y*cos(ang);
    }

}

void initialize()
{
    hl[0].x=-10,hl[0].y=-10,hl[0].z=0,hl[0].dx=-5,hl[0].dy=20;
    hl[1].x=8,hl[1].y=-8,hl[1].z=0,hl[1].dx=5,hl[1].dy=-20;
    hl[2].x=22,hl[2].y=-50,hl[2].z=0,hl[2].dx=5,hl[2].dy=-20;
    hl[3].x=20,hl[3].y=-70,hl[3].z=0,hl[3].dx=-5,hl[3].dy=-20;
    hl[4].x=5,hl[4].y=-60,hl[4].z=0,hl[4].dx=5,hl[4].dy=-20;
    hl[5].x=2,hl[5].y=-80,hl[5].z=0,hl[5].dx=-5,hl[5].dy=-20;

    hr[0].x=-10,hr[0].y=-10,hr[0].z=0,hr[0].dx=-5,hr[0].dy=20;
    hr[1].x=8,hr[1].y=-8,hr[1].z=0,hr[1].dx=5,hr[1].dy=-20;
    hr[2].x=22,hr[2].y=-50,hr[2].z=0,hr[2].dx=5,hr[2].dy=-20;
    hr[3].x=20,hr[3].y=-70,hr[3].z=0,hr[3].dx=-5,hr[3].dy=-20;
    hr[4].x=5,hr[4].y=-60,hr[4].z=0,hr[4].dx=5,hr[4].dy=-20;
    hr[5].x=2,hr[5].y=-80,hr[5].z=0,hr[5].dx=-5,hr[5].dy=-20;

    pl[0].x=-10,pl[0].y=-10,pl[0].z=0;
    pl[1].x=5,pl[1].y=-60,pl[1].z=0;
    pl[2].x=8,pl[2].y=-8,pl[2].z=0;
    pl[3].x=22,pl[3].y=-50,pl[3].z=0;
    pl[4].x=20,pl[4].y=-70,pl[4].z=0;
    pl[5].x=10,pl[5].y=-110,pl[5].z=0;
    pl[6].x=2,pl[6].y=-80,pl[6].z=0;
    pl[7].x=-8,pl[7].y=-120,pl[7].z=0;
    pl[8]=pl[7];
    pl[9].x=-13,pl[9].y=-128,pl[9].z=0;
    pl[10]=pl[9];
    pl[11].x=20,pl[11].y=-128,pl[11].z=0;
    pl[12]=pl[5];
    pl[13]=pl[11];

    pr[0].x=-10,pr[0].y=-10,pr[0].z=0;
    pr[1].x=5,pr[1].y=-60,pr[1].z=0;
    pr[2].x=8,pr[2].y=-8,pr[2].z=0;
    pr[3].x=22,pr[3].y=-50,pr[3].z=0;
    pr[4].x=20,pr[4].y=-70,pr[4].z=0;
    pr[5].x=10,pr[5].y=-110,pr[5].z=0;
    pr[6].x=2,pr[6].y=-80,pr[6].z=0;
    pr[7].x=-8,pr[7].y=-120,pr[7].z=0;
    pr[8]=pr[7];
    pr[9].x=-13,pr[9].y=-128,pr[9].z=0;
    pr[10]=pr[9];
    pr[11].x=20,pr[11].y=-128,pr[11].z=0;
    pr[12]=pr[5];
    pr[13]=pr[11];
}

void drawleftleg(int color,int counter)
{
    hermite(hl[0],hl[1],color,counter);
    makeline(pl[0].x+counter,pl[0].y,pl[1].x+counter,pl[1].y,color);
    makeline(pl[2].x+counter,pl[2].y,pl[3].x+counter,pl[3].y,color);
    hermite(hl[2],hl[3],color,counter);
    hermite(hl[4],hl[5],color,counter);
    makeline(pl[4].x+counter,pl[4].y,pl[5].x+counter,pl[5].y,color);
    makeline(pl[6].x+counter,pl[6].y,pl[7].x+counter,pl[7].y,color);
    makeline(pl[8].x+counter,pl[8].y,pl[9].x+counter,pl[9].y,color);
    makeline(pl[10].x+counter,pl[10].y,pl[11].x+counter,pl[11].y,color);
    makeline(pl[12].x+counter,pl[12].y,pl[13].x+counter,pl[13].y,color);
}

void drawrightleg(int color,int counter)
{
    hermite(hr[0],hr[1],color,counter);
    makeline(pr[0].x+counter,pr[0].y,pr[1].x+counter,pr[1].y,color);
    makeline(pr[2].x+counter,pr[2].y,pr[3].x+counter,pr[3].y,color);
    hermite(hr[2],hr[3],color,counter);
    hermite(hr[4],hr[5],color,counter);
    makeline(pr[4].x+counter,pr[4].y,pr[5].x+counter,pr[5].y,color);
    makeline(pr[6].x+counter,pr[6].y,pr[7].x+counter,pr[7].y,color);
    makeline(pr[8].x+counter,pr[8].y,pr[9].x+counter,pr[9].y,color);
    makeline(pr[10].x+counter,pr[10].y,pr[11].x+counter,pr[11].y,color);
    makeline(pr[12].x+counter,pr[12].y,pr[13].x+counter,pr[13].y,color);
}

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode,"C:\\TC\\BGI");
    initialize();
    double ang=0,angle;
    int flag=0;
    int counter=0;
    while(1)
    {
        drawleftleg(15,counter);
        drawrightleg(15,counter);
        if(ang>=20.0)flag=1;
        else if(ang<=-20.0)flag=0;
        if(flag)
        {
            angle=-2*PI/180;
            ang-=2;
        }
        else if(!flag)
        {
            angle=2*PI/180;
            ang+=2;
        }
        getch();
        drawleftleg(0,counter);
        drawrightleg(0,counter);
        newpointsz(angle);
        counter+=3;
    }
    getch();
    closegraph();
    return 0;
}
