//
//  class_Assign9.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 01/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//
#include <iostream>
#include <fstream>
using namespace std;

class Rectangle;
class Point {
    int x, y;
    
public:
    Point(int _x=0, int _y=0)
    : x(_x),y(_y){}
    Point(const Point &a){
        x = a.x;
        y = a.y;
    }
    int readX(){return x;}
    int ready(){return y;}
    void writeX(int _x){x = _x;}
    void writeY(int _y){y = _y;}
    friend istream& operator>>(istream& in, Point& a)
    {
        in >> a.x >> a.y;
        return in;
    }
};

class Rectangle {
    Point *bottemLeft, *upperRight;
    bool  isEmpty; // true if empty rectangle, false otherwise
    
public:
    Rectangle();
    Rectangle(int, int, int, int);
    Rectangle(Point, Point);
    Rectangle(const Rectangle &a){
        isEmpty = a.isEmpty;
        bottemLeft = a.bottemLeft;
        upperRight = a.upperRight;
    }
    friend istream& operator>>(istream&, Rectangle&);
    friend ostream& operator<<(ostream&, const Rectangle&);
    Rectangle& operator++(){
        int xs, ys, xt, yt;
        xs = this->bottemLeft->readX() - 1;
        ys = this->bottemLeft->ready() - 1;
        xt = this->upperRight->readX() + 1;
        yt = this->upperRight->ready() + 1;
        this->bottemLeft->writeX(xs);
        this->bottemLeft->writeY(ys);
        this->upperRight->writeX(xt);
        this->upperRight->writeY(yt);
        return *this;
    }
    Rectangle operator++(int){
        Rectangle res = *this;
        int xs, ys, xt, yt;
        xs = res.bottemLeft->readX() - 1;
        ys = res.bottemLeft->ready() - 1;
        xt = res.upperRight->readX() + 1;
        yt = res.upperRight->ready() + 1;
        res.bottemLeft->writeX(xs);
        res.bottemLeft->writeY(ys);
        res.upperRight->writeX(xt);
        res.upperRight->writeY(yt);
        return res;
    }
    
    Rectangle operator+(const Rectangle&);
    Rectangle operator-(const Rectangle&);
    // add other member functions if necessary
    Point findbLeft(Point, Point);
    Point finduRight(Point, Point);
    friend class Point;
};



int main()
{
    Rectangle rec;
    cout << rec;

    Rectangle rec1(2, 2, 5, 5);
    cout << rec1;
    Rectangle newRec = rec1++;
    cout << newRec;
    Rectangle rec2(3, 3, 7, 7);
    cout << rec2;
    
    Rectangle result = newRec + rec2;
    
    cout << result;
    
    Rectangle rec3 = rec1 + rec2;
    Rectangle rec4 = rec1 - rec2;
    
    cout << rec3;
    cout << rec4;
    
    return 0;
}

Rectangle::Rectangle(){
    isEmpty = true;
    bottemLeft = new Point;
    upperRight = new Point;
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
    
    bottemLeft = new Point(x1, y1);
    upperRight = new Point(x2, y2);
}

Rectangle::Rectangle(Point a, Point b){
    isEmpty = false;
    /* tall, small */
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
    bottemLeft = new Point(xs, ys);
    upperRight = new Point(xt, yt);
}

Point Rectangle::findbLeft(Point a, Point b){
    Point ret;
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
    ret.writeX(xs); ret.writeY(ys);
    return ret;
}

Point Rectangle::finduRight(Point a, Point b){
    Point ret;
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
    ret.writeX(xt); ret.writeY(yt);
    return ret;
}

Rectangle Rectangle::operator+(const Rectangle& a){
    Rectangle tmp(findbLeft(*this->bottemLeft, *a.bottemLeft),
                  finduRight(*this->upperRight, *a.upperRight)
                  );
    return tmp;
}

Rectangle Rectangle::operator-(const Rectangle& a){
    if (( this->upperRight->ready() < a.bottemLeft->ready() ||
          this->upperRight->readX() < a.bottemLeft->readX() ) ||
        ( this->bottemLeft->ready() > a.upperRight->ready() ||
          this->bottemLeft->readX() > a.upperRight->readX() )) {
            Rectangle retzero; return retzero;
    }
    Rectangle tmp(finduRight(*this->bottemLeft, *a.bottemLeft),
                  findbLeft(*this->upperRight, *a.upperRight)
                  );
    return tmp;
}
ostream& operator<<(ostream& os, const Rectangle& a) {
    cout << "bottomLeft = (" << a.bottemLeft->readX() << ", " << a.bottemLeft->ready() << ")" << endl;
    cout << "upperRight = (" << a.upperRight->readX() << ", " << a.upperRight->ready() << ")" << endl;
    return os;
}

istream& operator>>(istream& in, Rectangle& a) {
    in >> *a.bottemLeft;
    in >> *a.upperRight;
    return in;
}

