#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LINEFUNC.h"
#include "CIRCLEFUNC.h"
#include <dos.h>
#define PI acos(-1.0)

using namespace std;

struct hermitepoints
{
    double x,y,z,dx,dy;
};

struct circlepoints
{
    double x,y,z,r;
};

double n[6][3];
double m[6][3];
double l[6][3];
double li[3];
int flag1,flag2,flag3,flag4,flag5,flag6;
hermitepoints f1[2],f3[2];
circlepoints c1[2],c3[2];
double a[][3]={{-50,-50,50},{50,-50,50},{50,50,50},{-50,50,50},{-50,-50,-50},{50,-50,-50},{50,50,-50},{-50,50,-50}};
double ang=5*PI/180;

void intialize()
{
    f1[0].x=-20,f1[0].y=-20,f1[0].z=50,f1[0].dx=10,f1[0].dy=-30;
    f1[1].x=20,f1[1].y=-20,f1[1].z=50,f1[1].dx=10,f1[1].dy=30;
    c1[0].x=-15,c1[0].y=30,c1[0].z=50,c1[0].r=5;
    c1[1].x=15,c1[1].y=30,c1[1].z=50,c1[1].r=5;

    f3[0].x=-20,f3[0].y=-20,f3[0].z=-50,f3[0].dx=10,f3[0].dy=30;
    f3[1].x=20,f3[1].y=-20,f3[1].z=-50,f3[1].dx=10,f3[1].dy=-30;
    c3[0].x=-15,c3[0].y=30,c3[0].z=-50,c3[0].r=5;
    c3[1].x=15,c3[1].y=30,c3[1].z=-50,c3[1].r=5;
}

void hermite(hermitepoints p1,hermitepoints p2,int color)
{
    for(double t=0;t<=1;t+=0.01)
    {
        double x=(2*t*t*t-3*t*t+1)*p1.x+(-2*t*t*t+3*t*t)*p2.x+(t*t*t-2*t*t+t)*p1.dx+(t*t*t-t*t)*p2.dx;
        double y=(2*t*t*t-3*t*t+1)*p1.y+(-2*t*t*t+3*t*t)*p2.y+(t*t*t-2*t*t+t)*p1.dy+(t*t*t-t*t)*p2.dy;
        putpixel(320+x,240-y,color);
    }
}

void newpointsx()
{
    double newpts[8][3];

    for(int i=0;i<2;i++)
    {
        double x=f1[i].x;
        double y=f1[i].y;
        double z=f1[i].z;

        f1[i].y=y*cos(ang)-z*sin(ang);
        f1[i].z=y*sin(ang)+z*cos(ang);

        x=c1[i].x;
        y=c1[i].y;
        z=c1[i].z;

        c1[i].y=y*cos(ang)-z*sin(ang);
        c1[i].z=y*sin(ang)+z*cos(ang);
    }

    for(int i=0;i<2;i++)
    {
        double x=f3[i].x;
        double y=f3[i].y;
        double z=f3[i].z;

        f3[i].y=y*cos(ang)-z*sin(ang);
        f3[i].z=y*sin(ang)+z*cos(ang);

        x=c3[i].x;
        y=c3[i].y;
        z=c3[i].z;

        c3[i].y=y*cos(ang)-z*sin(ang);
        c3[i].z=y*sin(ang)+z*cos(ang);
    }

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            switch(j)
            {
                case 0: newpts[i][j]=a[i][j];
                break;
                case 1: newpts[i][j]=(a[i][j]*cos(ang)-a[i][j+1]*sin(ang));
                break;
                case 2: newpts[i][j]=(a[i][j-1]*sin(ang)+a[i][j]*cos(ang));
                break;
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            a[i][j]=newpts[i][j];
        }
    }
}

void newpointsy()
{
    double newpts[8][3];

    for(int i=0;i<2;i++)
    {
        double x=f1[i].x;
        double y=f1[i].y;
        double z=f1[i].z;

        f1[i].x=x*cos(ang)+z*sin(ang);
        f1[i].z=z*cos(ang)-x*sin(ang);

        x=c1[i].x;
        y=c1[i].y;
        z=c1[i].z;

        c1[i].x=x*cos(ang)+z*sin(ang);
        c1[i].z=z*cos(ang)-x*sin(ang);
    }

    for(int i=0;i<2;i++)
    {
        double x=f3[i].x;
        double y=f3[i].y;
        double z=f3[i].z;

        f3[i].x=x*cos(ang)+z*sin(ang);
        f3[i].z=z*cos(ang)-x*sin(ang);

        x=c3[i].x;
        y=c3[i].y;
        z=c3[i].z;

        c3[i].x=x*cos(ang)+z*sin(ang);
        c3[i].z=z*cos(ang)-x*sin(ang);
    }

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            switch(j)
            {
                case 0: newpts[i][j]=(a[i][j]*cos(ang)+a[i][j+2]*sin(ang));
                break;
                case 1: newpts[i][j]=a[i][j];
                break;
                case 2: newpts[i][j]=((-1)*a[i][j-2]*sin(ang)+a[i][j]*cos(ang));
                break;
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            a[i][j]=newpts[i][j];
        }
    }
}

void newpointsz()
{
    double newpts[8][3];

    for(int i=0;i<2;i++)
    {
        double x=f1[i].x;
        double y=f1[i].y;
        double z=f1[i].z;

        f1[i].x=x*cos(ang)-y*sin(ang);
        f1[i].y=x*sin(ang)+y*cos(ang);

        x=c1[i].x;
        y=c1[i].y;
        z=c1[i].z;

        c1[i].x=x*cos(ang)-y*sin(ang);
        c1[i].y=x*sin(ang)+y*cos(ang);
    }

    for(int i=0;i<2;i++)
    {
        double x=f3[i].x;
        double y=f3[i].y;
        double z=f3[i].z;

        f3[i].x=x*cos(ang)-y*sin(ang);
        f3[i].y=x*sin(ang)+y*cos(ang);

        x=c3[i].x;
        y=c3[i].y;
        z=c3[i].z;

        c3[i].x=x*cos(ang)-y*sin(ang);
        c3[i].y=x*sin(ang)+y*cos(ang);
    }

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            switch(j)
            {
                case 0: newpts[i][j]=(a[i][j]*cos(ang)-a[i][j+1]*sin(ang));
                break;
                case 1: newpts[i][j]=(a[i][j-1]*sin(ang)+a[i][j]*cos(ang));
                break;
                case 2: newpts[i][j]=a[i][j];
                break;
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            a[i][j]=newpts[i][j];
        }
    }
}

void findnormals()
{
    double px=a[7][0]-a[0][0], py=a[7][1]-a[0][1],pz=a[7][2]-a[0][2],x=a[3][0]-a[0][0],y=a[3][1]-a[0][1],z=a[3][2]-a[0][2];
    double _x=a[1][0]-a[0][0],_y=a[1][1]-a[0][1],_z=a[1][2]-a[0][2];
    double temp=px*(y*_z-_y*z)+py*(_x*z-x*_z)+pz*(x*_y-_x*y);
    if(temp>0) n[0][0]=_y*z-y*_z,n[0][1]=x*_z-_x*z,n[0][2]=_x*y-x*_y;
    else n[0][0]=y*_z-_y*z,n[0][1]=_x*z-x*_z,n[0][2]=x*_y-_x*y;
    n[2][0]=(-1)*n[0][0],n[2][1]=(-1)*n[0][1],n[2][2]=(-1)*n[0][2];

    px=a[7][0]-a[0][0], py=a[7][1]-a[0][1],pz=a[7][2]-a[0][2],x=a[4][0]-a[0][0],y=a[4][1]-a[0][0],z=a[4][2]-a[0][0];
    _x=a[1][0]-a[0][0],_y=a[1][1]-a[0][1],_z=a[1][2]-a[0][2];
    temp=px*(y*_z-_y*z)+py*(_x*z-x*_z)+pz*(x*_y-_x*y);
    if(temp>0) n[1][0]=_y*z-y*_z,n[1][1]=x*_z-_x*z,n[1][2]=_x*y-x*_y;
    else n[1][0]=y*_z-_y*z,n[1][1]=_x*z-x*_z,n[1][2]=x*_y-_x*y;
    n[3][0]=(-1)*n[1][0],n[3][1]=(-1)*n[1][1],n[3][2]=(-1)*n[1][2];

    px=a[2][0]-a[0][0], py=a[2][1]-a[0][1],pz=a[2][2]-a[0][2],x=a[4][0]-a[0][0],y=a[4][1]-a[0][0],z=a[4][2]-a[0][0];
    _x=a[3][0]-a[0][0],_y=a[3][1]-a[0][1],_z=a[3][2]-a[0][2];
    temp=px*(y*_z-_y*z)+py*(_x*z-x*_z)+pz*(x*_y-_x*y);
    if(temp>0) n[4][0]=_y*z-y*_z,n[4][1]=x*_z-_x*z,n[4][2]=_x*y-x*_y;
    else n[4][0]=y*_z-_y*z,n[4][1]=_x*z-x*_z,n[4][2]=x*_y-_x*y;
    n[5][0]=(-1)*n[4][0],n[5][1]=(-1)*n[4][1],n[5][2]=(-1)*n[4][2];
}

void findmeanpts()
{
    m[0][0]=(a[0][0]+a[1][0]+a[2][0]+a[3][0])/4;
    m[0][1]=(a[0][1]+a[1][1]+a[2][1]+a[3][1])/4;
    m[0][2]=(a[0][2]+a[1][2]+a[2][2]+a[3][2])/4;
    m[1][0]=(a[0][0]+a[1][0]+a[4][0]+a[5][0])/4;
    m[1][1]=(a[0][1]+a[1][1]+a[4][1]+a[5][1])/4;
    m[1][2]=(a[0][2]+a[1][2]+a[4][2]+a[5][2])/4;
    m[2][0]=(a[4][0]+a[5][0]+a[6][0]+a[7][0])/4;
    m[2][1]=(a[4][1]+a[5][1]+a[6][1]+a[7][1])/4;
    m[2][2]=(a[4][2]+a[5][2]+a[6][2]+a[7][2])/4;
    m[3][0]=(a[2][0]+a[3][0]+a[6][0]+a[7][0])/4;
    m[3][1]=(a[2][1]+a[3][1]+a[6][1]+a[7][1])/4;
    m[3][2]=(a[2][2]+a[3][2]+a[6][2]+a[7][2])/4;
    m[4][0]=(a[0][0]+a[4][0]+a[3][0]+a[7][0])/4;
    m[4][1]=(a[0][1]+a[1][1]+a[3][1]+a[7][1])/4;
    m[4][2]=(a[0][2]+a[1][2]+a[3][2]+a[7][2])/4;
    m[5][0]=(a[1][0]+a[2][0]+a[5][0]+a[6][0])/4;
    m[5][1]=(a[1][1]+a[2][1]+a[5][1]+a[6][1])/4;
    m[5][2]=(a[1][2]+a[2][2]+a[5][2]+a[6][2])/4;
}

void findedges()
{
    l[0][0]=m[0][0]-li[0];
    l[0][1]=m[0][1]-li[1];
    l[0][2]=m[0][2]-li[2];
    l[1][0]=m[1][0]-li[0];
    l[1][1]=m[1][1]-li[1];
    l[1][2]=m[1][2]-li[2];
    l[2][0]=m[2][0]-li[0];
    l[2][1]=m[2][1]-li[1];
    l[2][2]=m[2][2]-li[2];
    l[3][0]=m[3][0]-li[0];
    l[3][1]=m[3][1]-li[1];
    l[3][2]=m[3][2]-li[2];
    l[4][0]=m[4][0]-li[0];
    l[4][1]=m[4][1]-li[1];
    l[4][2]=m[4][2]-li[2];
    l[5][0]=m[5][0]-li[0];
    l[5][1]=m[5][1]-li[1];
    l[5][2]=m[5][2]-li[2];
}

void drawedges(int color)
{
    setlinestyle(1,1,1);
    setcolor(color);
    line(320+li[0],240-li[1],320+m[0][0],240-m[0][1]);
    line(320+li[0],240-li[1],320+m[1][0],240-m[1][1]);
    line(320+li[0],240-li[1],320+m[2][0],240-m[2][1]);
    line(320+li[0],240-li[1],320+m[3][0],240-m[3][1]);
    line(320+li[0],240-li[1],320+m[4][0],240-m[4][1]);
    line(320+li[0],240-li[1],320+m[5][0],240-m[5][1]);
    setlinestyle(0,1,1);
    setcolor(15);
}

void setflags()
{
    double temp=l[0][0]*n[0][0]+l[0][1]*n[0][1]+l[0][2]*n[0][2];
    if(temp>0) flag1=1;
    else flag1=0;
    temp=l[1][0]*n[1][0]+l[1][1]*n[1][1]+l[1][2]*n[1][2];
    if(temp>0) flag2=1;
    else flag2=0;
    temp=l[2][0]*n[2][0]+l[2][1]*n[2][1]+l[2][2]*n[2][2];
    if(temp>0) flag3=1;
    else flag3=0;
    temp=l[3][0]*n[3][0]+l[3][1]*n[3][1]+l[3][2]*n[3][2];
    if(temp>0) flag4=1;
    else flag4=0;
    temp=l[4][0]*n[4][0]+l[4][1]*n[4][1]+l[4][2]*n[4][2];
    if(temp>0) flag5=1;
    else flag5=0;
    temp=l[5][0]*n[5][0]+l[5][1]*n[5][1]+l[5][2]*n[5][2];
    if(temp>0) flag6=1;
    else flag6=0;
}

void plotface1(double newpts[][3],int color)
{
    if(flag1)return;
    makeline(newpts[0][0],newpts[0][1],newpts[1][0],newpts[1][1],color);
    makeline(newpts[1][0],newpts[1][1],newpts[2][0],newpts[2][1],color);
    makeline(newpts[2][0],newpts[2][1],newpts[3][0],newpts[3][1],color);
    makeline(newpts[3][0],newpts[3][1],newpts[0][0],newpts[0][1],color);
    hermite(f1[0],f1[1],color);
    makecircle(c1[0].x,c1[0].y,c1[0].r,color);
    makecircle(c1[1].x,c1[1].y,c1[1].r,color);
}

void plotface2(double newpts[][3],int color)
{
    if(flag2)return;
    makeline(newpts[0][0],newpts[0][1],newpts[4][0],newpts[4][1],color);
    makeline(newpts[1][0],newpts[1][1],newpts[5][0],newpts[5][1],color);
    makeline(newpts[0][0],newpts[0][1],newpts[1][0],newpts[1][1],color);
    makeline(newpts[4][0],newpts[4][1],newpts[5][0],newpts[5][1],color);
}

void plotface3(double newpts[][3],int color)
{
    if(flag3)return;
    makeline(newpts[4][0],newpts[4][1],newpts[5][0],newpts[5][1],color);
    makeline(newpts[5][0],newpts[5][1],newpts[6][0],newpts[6][1],color);
    makeline(newpts[6][0],newpts[6][1],newpts[7][0],newpts[7][1],color);
    makeline(newpts[7][0],newpts[7][1],newpts[4][0],newpts[4][1],color);
    hermite(f3[0],f3[1],color);
    makecircle(c3[0].x,c3[0].y,c3[0].r,color);
    makecircle(c3[1].x,c3[1].y,c3[1].r,color);
}

void plotface4(double newpts[][3],int color)
{
    if(flag4)return;
    makeline(newpts[3][0],newpts[3][1],newpts[7][0],newpts[7][1],color);
    makeline(newpts[2][0],newpts[2][1],newpts[6][0],newpts[6][1],color);
    makeline(newpts[3][0],newpts[3][1],newpts[2][0],newpts[2][1],color);
    makeline(newpts[6][0],newpts[6][1],newpts[7][0],newpts[7][1],color);
}

void plotface5(double newpts[][3],int color)
{
    if(flag5)return;
    makeline(newpts[0][0],newpts[0][1],newpts[4][0],newpts[4][1],color);
    makeline(newpts[3][0],newpts[3][1],newpts[7][0],newpts[7][1],color);
    makeline(newpts[3][0],newpts[3][1],newpts[0][0],newpts[0][1],color);
    makeline(newpts[7][0],newpts[7][1],newpts[4][0],newpts[4][1],color);
}

void plotface6(double newpts[][3],int color)
{
    if(flag6)return;
    makeline(newpts[1][0],newpts[1][1],newpts[5][0],newpts[5][1],color);
    makeline(newpts[2][0],newpts[2][1],newpts[6][0],newpts[6][1],color);
    makeline(newpts[1][0],newpts[1][1],newpts[2][0],newpts[2][1],color);
    makeline(newpts[5][0],newpts[5][1],newpts[6][0],newpts[6][1],color);
}

void plotcube(double a[][3],int color)
{
    plotface1(a,color);
    plotface2(a,color);
    plotface3(a,color);
    plotface4(a,color);
    plotface5(a,color);
    plotface6(a,color);
}

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode,"C:\\TC\\BGI");
    intialize();
    li[0]=0;
    li[1]=-100;
    li[2]=100;
    while(1)
    {
        findnormals();
        findmeanpts();
        findedges();
        setflags();
        drawedges(15);
        plotcube(a,15);
        char key=getch();
        plotcube(a,0);
        drawedges(0);
        switch(key)
        {
            case '1': newpointsx();
            break;
            case '2': newpointsy();
            break;
            case '3': newpointsz();
            break;
        }
    }
    closegraph();
    return 0;
}
