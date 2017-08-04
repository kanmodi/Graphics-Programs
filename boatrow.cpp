#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
typedef pair<int,int> mp;
#define PI acos(-1.0)
vector<mp> vb,v1b,vh,v1h,vbt,v1bt,vc,v1c;
double ang=10*PI/180;
double phi=0.0;
mp newpoints(double p,double q)
{
    //for(int i=0;i<v.size();i++)
    {
        double x=p-vc[0].first;
        double y=q-vc[0].second;
        p=(x*cos(ang)-y*sin(ang))+vc[0].first;
        q=(x*sin(ang)+y*cos(ang))+vc[0].second;
    }
    return mp(p,q);
}
void hermite(vector<mp> v,vector<mp> v1)
{
    for(int i=0;i<v.size();i+=2)
    {
        for(double t=0;t<=1;t+=0.005)
        {
            double x=(2*t*t*t-3*t*t+1)*v[i].first+(-2*t*t*t+3*t*t)*v[i+1].first+(t*t*t-2*t*t+t)*v1[i].first+(t*t*t-t*t)*v1[i+1].first;
            double y=(2*t*t*t-3*t*t+1)*v[i].second+(-2*t*t*t+3*t*t)*v[i+1].second+(t*t*t-2*t*t+t)*v1[i].second+(t*t*t-t*t)*v1[i+1].second;
            putpixel(x,y,15);
        }
    }
}

void hermiteclear(vector<mp> v,vector<mp> v1)
{
    for(int i=0;i<v.size();i+=2)
    {
        for(double t=0;t<=1;t+=0.005)
        {
            double x=(2*t*t*t-3*t*t+1)*v[i].first+(-2*t*t*t+3*t*t)*v[i+1].first+(t*t*t-2*t*t+t)*v1[i].first+(t*t*t-t*t)*v1[i+1].first;
            double y=(2*t*t*t-3*t*t+1)*v[i].second+(-2*t*t*t+3*t*t)*v[i+1].second+(t*t*t-2*t*t+t)*v1[i].second+(t*t*t-t*t)*v1[i+1].second;
            putpixel(x,y,0);
        }
    }
}

void plotpoints(int x,int y,int x1,int y1)
{
    putpixel((x+x1),(y+y1),WHITE);
    putpixel((x-x1),(y+y1),WHITE);
    putpixel((x-x1),(y-y1),WHITE);
    putpixel((x+x1),(y-y1),WHITE);
    putpixel((x+y1),(y+x1),WHITE);
    putpixel((x-y1),(y+x1),WHITE);
    putpixel((x-y1),(y-x1),WHITE);
    putpixel((x+y1),(y-x1),WHITE);
}
void plotpointse(int x,int y,int x1,int y1)
{
    x=x-30;
    putpixel((x+x1),(y+y1),BLACK);
    putpixel((x-x1),(y+y1),BLACK);
    putpixel((x-x1),(y-y1),BLACK);
    putpixel((x+x1),(y-y1),BLACK);
    putpixel((x+y1),(y+x1),BLACK);
    putpixel((x-y1),(y+x1),BLACK);
    putpixel((x-y1),(y-x1),BLACK);
    putpixel((x+y1),(y-x1),BLACK);
}

void makecircle(int xcenter,int ycenter,int r)
{
  int x=0;
  int y=r;
  int p=3-2*r;

  plotpointse(xcenter,ycenter,x,y);
  plotpoints(xcenter,ycenter,x,y);
  while(x<=y)
  {
    if(p<=0)
    {
    p+=(2*x+3)*2;
    }
    else
    {
    p+=4*(x-y)+10;
    y--;
    }
    x++;
    plotpointse(xcenter,ycenter,x,y);
   plotpoints(xcenter,ycenter,x,y);
  }
}
int main()
{
         int gdriver = DETECT , gmode ;
    initgraph(&gdriver, &gmode,"C:\\TC\\BGI");
        int k=0;
        while(1)
        {

        hermiteclear(vb,v1b);
         hermiteclear(vbt,v1bt);
          hermiteclear(vc,v1c);
           hermiteclear(vh,v1h);
         //static body of man
         makecircle(325+k,100,20);
         vb.clear();
         v1b.clear();
         vbt.clear();
         v1bt.clear();
         vc.clear();
         v1c.clear();
         vh.clear();
         v1h.clear();
        vb.push_back(mp(314+k,115));vb.push_back(mp(300+k,185));v1b.push_back(mp(-10,10));v1b.push_back(mp(10,10));
        vb.push_back(mp(334+k,120));vb.push_back(mp(330+k,185));v1b.push_back(mp(50,50));v1b.push_back(mp(-10,10));
        vb.push_back(mp(300+k,185));vb.push_back(mp(330+k,185));v1b.push_back(mp(10,0));v1b.push_back(mp(30,0));
        hermite(vb,v1b);
        vbt.push_back(mp(200+k,185));vbt.push_back(mp(500+k,185));v1bt.push_back(mp(10,0));v1bt.push_back(mp(10,0));
        vbt.push_back(mp(250+k,300));vbt.push_back(mp(450+k,300));v1bt.push_back(mp(50,0));v1bt.push_back(mp(10,0));
        vbt.push_back(mp(200+k,185));vbt.push_back(mp(250+k,300));v1bt.push_back(mp(20,10));v1bt.push_back(mp(20,10));
        vbt.push_back(mp(500+k,185));vbt.push_back(mp(450+k,300));v1bt.push_back(mp(20,-10));v1bt.push_back(mp(20,-10));
        hermite(vbt,v1bt);
        vc.push_back(mp(355+k,100));vc.push_back(mp(365+k,100));v1c.push_back(mp(10,0));v1c.push_back(mp(10,0));
        vc.push_back(mp(355+k,100));vc.push_back(mp(340+k,350));v1c.push_back(mp(50,10));v1c.push_back(mp(50,10));
        vc.push_back(mp(365+k,100));vc.push_back(mp(350+k,350));v1c.push_back(mp(50,10));v1c.push_back(mp(50,10));
        vc.push_back(mp(330+k,350));vc.push_back(mp(360+k,350));v1c.push_back(mp(50,0));v1c.push_back(mp(20,0));
        hermite(vc,v1c);
        vh.push_back(mp(325+k,130));vh.push_back(mp(365+k,130));v1h.push_back(mp(10,0));v1h.push_back(mp(10,0));
        vh.push_back(mp(325+k,135));vh.push_back(mp(360+k,135));v1h.push_back(mp(50,0));v1h.push_back(mp(10,0));
        hermite(vh,v1h);


            phi=0;
            while(phi<=(15*PI/180))
            {
            phi+=ang;
            hermiteclear(vc,v1c);
            hermiteclear(vh,v1h);
            for(int i=0;i<vc.size();i++)
                vc[i]=(newpoints(vc[i].first,vc[i].second));
            for(int i=0;i<vh.size();i++)
                vh[i]=(newpoints(vh[i].first,vh[i].second));
            hermite(vc,v1c);
            hermite(vh,v1h);
            getch();
            }
            k+=30;
        }
        getch();
        return 0;
}
