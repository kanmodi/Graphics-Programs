#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>

#define PI acos(-1.0)
#define pb push_back
#define mkp make_pair
#define fst first
#define snd second

using namespace std;

double ang=5*PI/180;

void drawrect(vector< pair<double,double> >v)
{
    for(int i=4;i<v.size();i++)
    {
        setcolor(WHITE);
        if(i==7)
            line(v[i].fst,v[i].snd,v[4].fst,v[4].snd);
        else
            line(v[i].fst,v[i].snd,v[i+1].fst,v[i+1].snd);
    }
}

void drawrect_clear(vector< pair<double,double> >v)
{
    for(int i=4;i<v.size();i++)
    {
        setcolor(BLACK);
        if(i==7)
            line(v[i].fst,v[i].snd,v[4].fst,v[4].snd);
        else
            line(v[i].fst,v[i].snd,v[i+1].fst,v[i+1].snd);
    }
}

vector< pair<double,double> > lefts;
vector< pair<double,double> > rights;
vector< pair<double,double> > tops;
vector< pair<double,double> > bottoms;

void drawfan_intialize()
{
    lefts.pb(mkp(320-30,240+5));
    lefts.pb(mkp(320-40,240+5));
    lefts.pb(mkp(320-30,240-5));
    lefts.pb(mkp(320-40,240-5));
    lefts.pb(mkp(320-40,240-20));
    lefts.pb(mkp(320-40,240+20));
    lefts.pb(mkp(320-100,240+20));
    lefts.pb(mkp(320-100,240-20));

    rights.pb(mkp(320+30,240+5));
    rights.pb(mkp(320+40,240+5));
    rights.pb(mkp(320+30,240-5));
    rights.pb(mkp(320+40,240-5));
    rights.pb(mkp(320+40,240+20));
    rights.pb(mkp(320+100,240+20));
    rights.pb(mkp(320+100,240-20));
    rights.pb(mkp(320+40,240-20));

    tops.pb(mkp(320-5,240+30));
    tops.pb(mkp(320-5,240+40));
    tops.pb(mkp(320+5,240+30));
    tops.pb(mkp(320+5,240+40));
    tops.pb(mkp(320-20,240+40));
    tops.pb(mkp(320-20,240+100));
    tops.pb(mkp(320+20,240+100));
    tops.pb(mkp(320+20,240+40));

    bottoms.pb(mkp(320-5,240-30));
    bottoms.pb(mkp(320-5,240-40));
    bottoms.pb(mkp(320+5,240-30));
    bottoms.pb(mkp(320+5,240-40));
    bottoms.pb(mkp(320-20,240-40));
    bottoms.pb(mkp(320-20,240-100));
    bottoms.pb(mkp(320+20,240-100));
    bottoms.pb(mkp(320+20,240-40));
}

void newpoints()
{
    for(int i=0;i<lefts.size();i++)
    {
        double x=lefts[i].fst-320;
        double y=lefts[i].snd-240;
        lefts[i].fst=x*cos(ang)-y*sin(ang)+320;
        lefts[i].snd=x*sin(ang)+y*cos(ang)+240;

        x=rights[i].fst-320;
        y=rights[i].snd-240;
        rights[i].fst=x*cos(ang)-y*sin(ang)+320;
        rights[i].snd=x*sin(ang)+y*cos(ang)+240;

        x=tops[i].fst-320;
        y=tops[i].snd-240;
        tops[i].fst=x*cos(ang)-y*sin(ang)+320;
        tops[i].snd=x*sin(ang)+y*cos(ang)+240;

        x=bottoms[i].fst-320;
        y=bottoms[i].snd-240;
        bottoms[i].fst=x*cos(ang)-y*sin(ang)+320;
        bottoms[i].snd=x*sin(ang)+y*cos(ang)+240;
    }
}

void drawfan()
{
    setcolor(WHITE);
    circle(320,240,5);
    circle(320,240,30);

    for(int i=0;i<(lefts.size()-4);i+=2)
    {   setcolor(WHITE);
        line(lefts[i].fst,lefts[i].snd,lefts[i+1].fst,lefts[i+1].snd);
        line(rights[i].fst,rights[i].snd,rights[i+1].fst,rights[i+1].snd);
        line(tops[i].fst,tops[i].snd,tops[i+1].fst,tops[i+1].snd);
        line(bottoms[i].fst,bottoms[i].snd,bottoms[i+1].fst,bottoms[i+1].snd);
    }

    for(int i=4;i<(lefts.size());i+=2)
    { setcolor(WHITE);
        drawrect(lefts);
        drawrect(rights);
        drawrect(tops);
        drawrect(bottoms);
    }

}

void drawfan_clear()
{
    for(int i=0;i<(lefts.size()-4);i+=2)
    {
        setcolor(BLACK);
        line(lefts[i].fst,lefts[i].snd,lefts[i+1].fst,lefts[i+1].snd);
        line(rights[i].fst,rights[i].snd,rights[i+1].fst,rights[i+1].snd);
        line(tops[i].fst,tops[i].snd,tops[i+1].fst,tops[i+1].snd);
        line(bottoms[i].fst,bottoms[i].snd,bottoms[i+1].fst,bottoms[i+1].snd);
    }

    for(int i=4;i<(lefts.size());i+=2)
    {
        drawrect_clear(lefts);
        drawrect_clear(rights);
        drawrect_clear(tops);
        drawrect_clear(bottoms);
    }

}

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode,"C:\\TC\\BGI");
    drawfan_intialize();
    while(1)
    {
        newpoints();
        drawfan();

        delay(20);
        drawfan_clear();
    }
    getch();
    closegraph();
    return 0;
}
