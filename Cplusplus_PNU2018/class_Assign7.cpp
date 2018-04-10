//
//  class_Assign7.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 10/04/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include<iostream>
using namespace std;

class nMatrix {
    int **values;
    int size; //size of matrix
public:
    nMatrix(int n, int x); // construct nMatrix of size n and initialize it as x;
    ~nMatrix(); // destructor;
    nMatrix(const nMatrix& a); // copy constructor
    friend ostream& operator<<(ostream&, const nMatrix&);
    nMatrix operator+(nMatrix);
    // nMatrix addnMatrix(nMatrix a, nMatrix b);
};

/*
 1.    Complete constructor nMatrix(int n, int x), destructor ~nMatrix(), and copy constructor nMatrix(const nMatrix& a).
 2.    Program a function nMatrix addnMatrix(nMatrix a, nMatrix b) that adds two nMatrix a and b and return the result.
 */

nMatrix::nMatrix(int n, int x)
{
    size = n;
    values = new int*[size];
    for (int i = 0 ; i < size ; i++) {
        values[i] = new int[size];
    }
    for (int i = 0 ; i < size ; i++) {
        for (int j = 0; j < size ; j++) {
            values[i][j] = x;
        }
    }
}

nMatrix::~nMatrix()
{
    for (int i = 0; i < size ; i++) {
        delete[] values[i];
    }
    delete[] values;
}

nMatrix::nMatrix(const nMatrix& a)
{
    size = a.size;
    values = new int*[size];
    for (int i = 0; i < size; i++) {
        values[i] = new int[size];
    }
    for (int i = 0 ; i < size; i++) {
        for (int j = 0; j < size; j++) {
            values[i][j] = a.values[i][j];
        }
    }
}

ostream& operator<<(ostream& os, const nMatrix& m) {
    for(int i=0;i<m.size;i++) {
        for(int k=0;k<m.size;k++) os << m.values[i][k] << " ";
        os<<"\n";
    }
    return os;
}

nMatrix nMatrix::operator+(nMatrix op)
{
    nMatrix tmp(*this);
    for (int i = 0; i < op.size ; i++) {
        for (int j = 0; j < op.size ; j++) {
            tmp.values[i][j] += op.values[i][j];
        }
    }
    return tmp;
}

nMatrix addnMatrix(nMatrix a, nMatrix b);

int main()
{
    nMatrix a(3,2);
    nMatrix b(3,4);
    cout << a+b;
    return 0;
}

nMatrix addnMatrix(nMatrix a, nMatrix b)
{
    return a+b;
}
