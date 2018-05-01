//
//  ConsoleOutput.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 01/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <iostream>
namespace mystd
{
    using namespace std;
    
    class ostream
    {
    public:
        ostream& operator<< (char *str)
        {
            printf("%s", str);
            return *this;
        }
        ostream& operator<< (char str)
        {
            printf("%c", str);
            return *this;
        }
        ostream& operator<< (int num)
        {
            printf("%d", num);
            return *this;
        }
        ostream& operator<< (double e)
        {
            printf("%g", e);
            return *this;
        }
        ostream& operator<< (ostream& (*fp)(ostream &ostm))
        {
            return fp(*this);
        }
    };
    
    ostream& endl(ostream &ostm)
    {
        ostm << '\n';
        fflush(stdout);
        return ostm;
    }
    
    ostream cout;
}

int main()
{
    using mystd::cout;
    using mystd::endl;
    cout << 3.14 << endl << 123 << endl;
    return 0;
}

