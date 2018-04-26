//
//  lab7.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 12/04/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include<iostream>
using namespace std;


class nMatrix {
    int **values;
    int size; //size of matrix
public:
    static int count;
    nMatrix(int n, int x); // construct nMatrix of size n and initialize it as x;
    ~nMatrix(); // destructor;
    nMatrix(const nMatrix& a); // copy constructor
    friend ostream& operator<<(ostream&, const nMatrix&);
    nMatrix operator+(nMatrix);
    static int getTotalCount(void){
        return count;
    }
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
    count++;
}

nMatrix::~nMatrix()
{
    for (int i = 0; i < size ; i++) {
        delete[] values[i];
    }
    delete[] values;
    count--;
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

int nMatrix::count = 0;
nMatrix addnMatrix(nMatrix a, nMatrix b);
int main()
{
    nMatrix a(5, 3);
    cout << nMatrix::getTotalCount() << endl; // print 1
    nMatrix b(5, 1);
    nMatrix c(3, 5);
    cout << nMatrix::getTotalCount() << endl; // print 3
    //cout << a;
    //cout << b;
    //cout << addnMatrix(a, b);
    //cout << c;
}

nMatrix addnMatrix(nMatrix a, nMatrix b)
{
    return a+b;
}
