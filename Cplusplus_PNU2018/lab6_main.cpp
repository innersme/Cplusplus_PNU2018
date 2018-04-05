//
//  lab6_main.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 05/04/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <iostream>
using namespace std;

class Point3D{
private:
    float x;
    float y;
    float z;
public:
    Point3D();
    Point3D(const Point3D &);
    Point3D(float _x, float _y, float _z)
    {
        x= _x;
        y= _y;
        z= _z;
        cout << "I like him\n";
    }
    Point3D operator+(Point3D B);
    friend ostream& operator<<(ostream&, const Point3D&);
};

Point3D::Point3D()
{
    cout << "I love him\n";
}

Point3D::Point3D(const Point3D & rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    cout << "I hate him\n";
}

Point3D Point3D::operator+(Point3D op)
{
    Point3D temp;
    temp.x = x + op.x;
    temp.y = y + op.y;
    temp.z = z + op.z;
    return temp;
}

ostream& operator<<(ostream& os, const Point3D& p)
{
    os << "(" << (float)p.x << ","<< (float)p.y<< "," << (float)p.z << ")\n";
    return os;
}

int main()
{
    Point3D A(1.0,2.0,3.0), B(4.0,5.0,6.0), C;
    C=A+B;
    // C = A.operator+(B) ;
    cout<< C;
}
