//
//  OneOpndOverloading.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 01/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <iostream>
using namespace std;

class Point{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0)
    : xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout << '[' << xpos << ',' << ypos << ']' << endl;
    }
    Point& operator++()
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    const Point operator++(int)
    {
        const Point retobj(xpos, ypos); // const Point retobj(*this);
        xpos += 1;
        ypos += 1;
        return retobj;
    }
    
    friend Point& operator--(Point &ref);
};

Point& operator--(Point &ref){
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

int main()
{
    Point pos(1,2);
    ++pos;
    pos.ShowPosition();
    --pos;
    pos.ShowPosition();
    
    ++(++pos);
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();
    
    return 0;
}

