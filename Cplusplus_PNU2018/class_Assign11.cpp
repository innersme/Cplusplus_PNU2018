//
//  class_Assign11.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 27/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <iostream>
using namespace std;

class Shape;
class ShapeSet {
    Shape** shapes;
    int    numShapes;
    int    maxShapes; // maximum number of shape objects
    
public:
    ShapeSet(int n); // initialize a ShapeSet where maxShape is n
    ShapeSet(const ShapeSet&);
    ShapeSet operator+(Shape& s); //add a shape to ShapeSet.
    double totalArea(); // total area of shapes in the set};
};

class Shape {
protected:
    int  type; // POINT, CIRCLE, RECTANGLE, or
    
public:
    Shape(int ntype):type(ntype){}
    int getType() const { return type; }
    enum {POINT, CIRCLE, RECTANGLE, TRIANGLE};
    virtual double area()=0;
};

class Point : public Shape{
    double x, y;
    
public:
    Point(double, double);
    double getX() { return x; }
    double getY() { return y; }
    double area() { return 0.0;}
};

Point::Point(double _x, double _y)
:Shape(POINT),x(_x), y(_y) { }

class Rectangle : public Shape {
    Point rightUpper, leftLower;
    
public:
    Rectangle(const Point&, const Point&);
    double area();
};

Rectangle::Rectangle(const Point& r, const Point& l)
:Shape(RECTANGLE), rightUpper(r), leftLower(l) { }

double Rectangle::area()
{
    return ( rightUpper.getX() - leftLower.getX() ) * ( rightUpper.getY() - leftLower.getY() );
}

class Circle : public Shape {
    Point Center;
    double radius;
    
public:
    Circle(const Point&, double);
    double area();
};

Circle::Circle(const Point &c, double ra)
:Shape(CIRCLE), Center(c), radius(ra) { }

double Circle::area() { return 3.14 * radius * radius; }

class Triangle : public Shape {
    Point p1, p2, p3;
    
public:
    Triangle(const Point&, const Point&, const Point&);
//    bool isContaining(const Point&);
    double area();
};

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
:Shape(TRIANGLE),p1(a), p2(b), p3(c) { }

double Triangle::area(){
    return 0.5*( p1.getX()*p2.getY() + p2.getX()*p3.getY() + p3.getX()*p1.getY()
                - p1.getX()*p3.getY() - p3.getX()*p2.getY() - p2.getX()*p1.getY() );
}

/* Constructor Define */

ShapeSet::ShapeSet(int n)
:maxShapes(n), numShapes(0)
{
    shapes = new Shape*[n];
}

ShapeSet::ShapeSet(const ShapeSet& s)
{
    maxShapes = s.maxShapes;
    numShapes = s.numShapes;
    shapes = new Shape*[s.maxShapes];
    for (int i = 0 ; i < maxShapes; i++) {
        shapes[i] = s.shapes[i];
    }
}

ShapeSet ShapeSet::operator+(Shape &s)
{
    ShapeSet *retSet = new ShapeSet(*this);
    retSet->shapes[retSet->numShapes] = &s;
    retSet->numShapes++;
    return *retSet;
}

double ShapeSet::totalArea()
{
    double ret = 0.0;
    ShapeSet retSet = *this;
    for (int i = 0 ; i < retSet.numShapes; i++) {
        ret += retSet.shapes[i]->area();
    }
    return ret;
}

int main()
{
    ShapeSet mSet(5);
    Point A(3,4);
    Point B(0,0);
    Point C(9,8);
    Triangle nTr(A,B,C);
    cout << "Triangle: " << nTr.area() << endl;
    Circle nCr(A, 3.5);
    cout << "Circle: " << nCr.area() << endl;
    Rectangle nRe(B,C);
    cout << "Rectangle: " << nRe.area() << endl;
    mSet = mSet + nTr;
    mSet = mSet + nCr;
    mSet = mSet + nRe;
    cout << mSet.totalArea() << endl;
    
    return 0;
}
