#include <iostream>
using namespace std;

//Point class
class Point {
    int x, y;
public:
    Point(int, int);
    Point(const Point &p){
        x = p.x;
        y = p.y;
    }
    int readX();
    int readY();
    friend ostream& operator<<(ostream&, const Point&);
};
//constructor
Point :: Point(int _x, int _y){
    x = _x;
    y = _y;
}
int Point :: readX(){
    return x;
}
int Point :: readY(){
    return y;
}
ostream& operator<<(ostream& istreamPoint, const Point& p){
    cout << "(" << p.x << ", " << p.y << ")" <<endl;
    return istreamPoint;
}




//Rectangle class
class Rectangle {
    Point *bottomLeft, *upperRight;
    bool  isEmpty; // true if empty rectangle, false otherwise
public:
    Rectangle();
    Rectangle(int, int, int, int);
    Rectangle(Point, Point);
    Rectangle(const Rectangle &r){
        bottomLeft = r.bottomLeft;
        upperRight = r.upperRight;
    }
    friend istream& operator>>(istream&, Rectangle&);
    Rectangle operator+(const Rectangle&);
    Rectangle operator-(const Rectangle&);
    bool checkIsEmpty(){
        return isEmpty;
    }
    int minX(Point* a, Point* b);
    int minY(Point* a, Point* b);
    int maxX(Point* a, Point* b);
    int maxY(Point* a, Point* b);
    int secondX(Point* a, Point* b);
    int secondY(Point* a, Point* b);
    int thirdX(Point* a, Point* b);
    int thirdY(Point* a, Point* b);
    // add other member functions if necessary
};
//constructor
Rectangle :: Rectangle(){
    bottomLeft = new Point(0, 0);
    upperRight = new Point(1, 1);
}
Rectangle :: Rectangle(int x1, int y1, int x2, int y2){
    bottomLeft = new Point(x1, y1);
    upperRight = new Point(x2, y2);
}
Rectangle :: Rectangle(Point a, Point b){
    bottomLeft = &a;
    upperRight = &b;
}

//Operator
istream& operator>>(istream& istreamPoint, Rectangle& r){
    cout << "bottomLeft = " << *(r.bottomLeft);
    cout << "upperRight = " << *(r.upperRight) << endl;
    return istreamPoint;
}
Rectangle Rectangle :: operator+(const Rectangle& r){
    Rectangle temp;
    temp.bottomLeft = new Point(minX(bottomLeft, r.bottomLeft), minY(bottomLeft, r.bottomLeft));
    temp.upperRight = new Point(maxX(upperRight, r.upperRight), maxY(upperRight, r.upperRight));
    return temp;
}

Rectangle Rectangle :: operator-(const Rectangle& r){
    Rectangle temp;
    temp.bottomLeft = new Point(secondX(bottomLeft, r.bottomLeft), secondY(bottomLeft, r.bottomLeft));
    temp.upperRight = new Point(thirdX(upperRight, r.upperRight), thirdY(upperRight, r.upperRight));
    return temp;
}

int Rectangle :: minX(Point* a, Point* b){
    if((*a).readX() < (*b).readX()){
        return (*a).readX();
    }else{
        return (*b).readX();
    }
}
int Rectangle :: minY(Point* a, Point* b){
    if((*a).readY() < (*b).readY()){
        return (*a).readY();
    }else{
        return (*b).readY();
    }
}
int Rectangle :: maxX(Point* a, Point* b){
    if((*a).readX() > (*b).readX()){
        return (*a).readX();
    }else{
        return(*b).readX();
    }
}
int Rectangle :: maxY(Point* a, Point* b){
    if((*a).readY() > (*b).readY()){
        return (*a).readY();
    }else{
        return (*b).readY();
    }
}
int Rectangle :: secondX(Point* a, Point* b){
    if((*a).readX() > (*b).readX()){
        return (*a).readX();
    }else{
        return (*b).readX();
    }
}
int Rectangle :: secondY(Point* a, Point* b){
    if((*a).readY() > (*b).readY()){
        return (*a).readY();
    }else{
        return (*b).readY();
    }
}
int Rectangle :: thirdX(Point* a, Point* b){
    if((*a).readX() > (*b).readX()){
        return (*b).readX();
    }else{
        return (*a).readX();
    }
}
int Rectangle :: thirdY(Point* a, Point* b){
    if((*a).readY() > (*b).readY()){
        return (*b).readY();
    }else{
        return (*a).readY();
    }
}

int main()
{
    Rectangle r1 = Rectangle(1, 4, 9, 9);
    Rectangle r2 = Rectangle(Point(6, 2), Point(12, 5));
    Rectangle r3 = r1 + r2;
    Rectangle r4 = r1 - r2;
    cin >> r3;
    cin >> r4;
    return 0;
}
