//
//  Assign10_binary.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 16/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char *filename = (char*)"data.bin";
    ofstream output(filename, ios::out | ios::binary);
    
    
    char c1 = 'U';
    char c2 = 'V';
    char c3 = 'W';
    char str[] = "apbak";
    
    output.write(&c1, sizeof(char));
    output.write(str, sizeof(str)-1);
    output.write(&c2, sizeof(c2));
    output << "anim" << ' ';
    output.put('5');
    output.write(&c3, 1);
    
    output.close();
    return 0;
}

