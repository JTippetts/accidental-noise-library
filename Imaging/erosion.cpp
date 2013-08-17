#include "erosion.h"
#include <list>
#include <iostream>
#include <algorithm>

struct SDrop
{
    int x,y;

    SDrop(int X, int Y) : x(X), y(Y){}
};

void shuffleDirections(SDrop *dirs, anl::CMWC4096 &rnd)
{
    for(int i=0; i<8; ++i)
    {
        int index=rnd.getRange(0,8-i)+i;
        std::swap(dirs[index], dirs[i]);
    }
}

SDrop find_lowest_neighbor(anl::CMWC4096 &rnd, anl::CArray2Dd &map, int x, int y)
{
    int w=map.width(), h=map.height();

    static SDrop dirs[8]=
    {
        SDrop(-1,-1),
        SDrop(0,-1),
        SDrop(1,-1),
        SDrop(-1,0),
        SDrop(1,0),
        SDrop(-1,1),
        SDrop(0,1),
        SDrop(1,1)

    };

    int minx=x;
    int miny=y;
    ANLFloatType minht=map.get(x,y);

    shuffleDirections(dirs,rnd);

    for(int c=0; c<8; ++c)
    {
        int i=x+dirs[c].x;
        int j=y+dirs[c].y;
        if(i>=0 && i<w && j>=0 && j<h)
        {
            ANLFloatType v=map.get(i,j);
            if(v<minht)
            {
                minht=v;
                minx=i;
                miny=j;
            }
        }
    }

    return SDrop(minx,miny);
}



void simpleErode(anl::CArray2Dd &map, unsigned int numdrops, float power)
{
    anl::CMWC4096 rnd;
    rnd.setSeedTime();

    std::list<SDrop> drops;
    int w=map.width(), h=map.height();

    if(numdrops==0) numdrops=w*h;

    for(unsigned int c=0; c<numdrops; ++c)
    {
        drops.push_back(SDrop(rnd.getRange(0,w-1), rnd.getRange(0,h-1)));
    }

    while(!drops.empty())
    {
        SDrop drop=drops.front();
        drops.pop_front();

        SDrop low=find_lowest_neighbor(rnd, map, drop.x, drop.y);
        if(low.x != drop.x || low.y!=drop.y)
        {
            ANLFloatType ht=map.get(drop.x,drop.y);
            ANLFloatType mn=map.get(low.x,low.y);

            map.set(drop.x,drop.y,ht+power*(mn-ht));
            map.set(low.x,low.y,ht+(1.0-power)*(mn-ht));
            drops.push_back(low);
        }

        //std::cout << "Drops remaining: " << drops.size() << std::endl;
    }
}

void simpleRainfall(anl::CArray2Dd &map, anl::CArray2Dd &depth, int iterations)
{
    anl::CMWC4096 rnd;
    rnd.setSeedTime();

    std::list<SDrop> drops;
    int w=map.width(), h=map.height();

    depth.copyFrom(&map);

    int numdrops=w*h;

    for(unsigned int c=0; c<numdrops; ++c)
    {
        int x=rnd.getRange(0,w-1);
        int y=rnd.getRange(0,h-1);
        drops.push_back(SDrop(x,y));
        map.set(x,y,map.get(x,y)+0.001);
    }

    while(!drops.empty())
    {
        SDrop drop=drops.front();
        drops.pop_front();
        map.set(drop.x, drop.y, map.get(drop.x,drop.y)-0.001);

        SDrop low=find_lowest_neighbor(rnd, map, drop.x, drop.y);
        if(low.x != drop.x || low.y!=drop.y)
        {
            drops.push_back(low);
        }
        else
        {
            // Hit bottom
            map.set(drop.x, drop.y, map.get(drop.x, drop.y)+0.001);
        }
    }

    for(int x=0; x<w; ++x)
    {
        for(int y=0; y<h; ++y)
        {
            depth.set(x,y,map.get(x,y)-depth.get(x,y));
        }
    }
}
