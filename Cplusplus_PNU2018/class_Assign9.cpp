//
//  class_Assign9.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 01/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//
#include <iostream>
using namespace std;

class Point {
    int x, y;
    
public:
    int readX(){return x;}
    int ready(){return y;}
    void writeX(int _x){x = _x;}
    void writeY(int _y){y = _y;}
};

class Rectangle {
    Point *bottemLeft, *upperRight;
    bool  isEmpty; // true if empty rectangle, false otherwise
    
public:
    Rectangle();
    Rectangle(int, int, int, int);
    Rectangle(Point, Point);
    friend istream& operator>>(istream&, Rectangle&);
    Rectangle operator+(const Rectangle&);
    Rectangle operator-(const Rectangle&);
    // add other member functions if necessary
};

istream& operator>>(istream& os, Rectangle& a) {
    
    return os;
}
int main()
{
    Rectangle rec;
    
    rec >> 2 >> 3 >> 4 >> 5;
    return 0;
}

Rectangle::Rectangle(){
    isEmpty = true;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2){
    isEmpty = false;
    /* tall, small */
    int xt,yt,xs,ys;
    if (x1 < x2) {
        if (y1 < y2) {
            xs = x1; ys = y1; xt = x2; yt = y2;
        }
        else
            xs = x1; ys = y2; xt = x2; yt = y1;
    }
    else {
        if (y1 < y2) {
            xs = x2; ys = y1; xt = x1; yt = y2;
        }
        else
            xs = x2; ys = y2; xt = x1; yt = y1;
    }
    
    bottemLeft->writeX(xs);
    bottemLeft->writeY(ys);
    upperRight->writeX(xt);
    upperRight->writeY(yt);
}

Rectangle::Rectangle(Point a, Point b){
    isEmpty = false;
    int xt,yt,xs,ys;
    if ( a.readX() < b.readX() ) {
        if (a.ready() < b.ready()) {
            xs = a.readX(); xt = b.readX();
            ys = a.ready(); yt = b.ready();
        }
        else {
            xs = a.readX(); xt = b.readX();
            yt = a.ready(); ys = b.ready();
        }
    }
    else {
        if (a.ready() < b.ready()) {
            xt = a.readX(); xs = b.readX();
            ys = a.ready(); yt = b.ready();
        }
        else {
            xt = a.readX(); xs = b.readX();
            yt = a.ready(); ys = b.ready();
        }
    }
    
    bottemLeft->writeX(xs);
    bottemLeft->writeY(ys);
    upperRight->writeX(xt);
    upperRight->writeY(yt);
}
