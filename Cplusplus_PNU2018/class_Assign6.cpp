#include <iostream>

using namespace std;

class Point
{
    
private:
    float x;
    float y;
    
public:
    Point();
    Point(const Point &);
    Point(float _x, float _y)
    {
        x= _x;
        y= _y;
        cout << "I like him\n";
    }
    Point operator+(Point B);
    friend ostream& operator<<(ostream&, const Point&);
};

Point::Point()
{
    cout << "I love him\n";
}

Point::Point(const Point & rhs)
{
    x = rhs.x;
    y = rhs.y;
    cout << "I hate him\n";
}

Point  Point::operator+(Point op)
{
    Point temp;
    temp.x = x + op.x;
    temp.y = y + op.y;
    return temp;
}

ostream& operator<<(ostream& os, const Point& p)
{
    os << "(" << p.x << ","<< p.y<<")\n";
    return os;
}

int main()
{
    Point A(1.0,2.0), B(3.0,4.0), C;
    C=A+B;
    // C = A.operator+(B) ;
    cout<< C;
}
