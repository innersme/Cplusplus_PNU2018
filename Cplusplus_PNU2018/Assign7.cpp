//
//  Assign7.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMac on 13/06/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <iostream>
using namespace std;

class nMatrix {
    int **values;
    int size;
public:
    nMatrix(int, int);
    ~nMatrix();
    nMatrix(const nMatrix& a);
    nMatrix operator+(nMatrix);
    nMatrix addnMatrix(nMatrix a, nMatrix b);
    friend ostream& operator<<(ostream&, const nMatrix&);
};

nMatrix::nMatrix(int n, int x)
:size(n){
    cout << "hi\n";
    values = new int*[size];
    for (int i = 0; i < size; i++) {
        values[i] = new int[size];
    }
    for (int i = 0 ; i < size; i ++ ) {
        for (int k = 0 ; k < size ; k++) {
            values[i][k] = x;
        }
    }
}

nMatrix::~nMatrix()
{
    cout << "bye\n";
    for (int i = 0 ; i < size; i++ ) {
        delete[] values[i];
    }
    delete[] values;
}

nMatrix::nMatrix(const nMatrix& a){
    size = a.size;
    values = new int*[size];
    for (int i = 0 ; i < size ; i++) {
        values[i] = new int[size];
    }
    for (int i = 0 ; i < size; i ++ ) {
        for (int k = 0 ; k < size ; k++) {
            values[i][k] = a.values[i][k];
        }
    }
}

nMatrix nMatrix::operator+(nMatrix b)
{
    nMatrix tmp(*this);
    for (int i = 0 ; i < size; i ++ ) {
        for (int k = 0 ; k < size ; k++) {
            tmp.values[i][k] += b.values[i][k];
        }
    }
    return tmp;
}

ostream& operator<<(ostream &os, const nMatrix &m){
    for (int i = 0 ; i < m.size ; i++) {
        for (int k = 0 ; k < m.size; k++) {
            os << m.values[i][k] << " ";
        }
        os << "\n";
    }
    return os;
}

int main()
{
    nMatrix a(5,3);
    cout << a;

    nMatrix b(5,1);
    cout << b;
    
    nMatrix c(3,5);
    cout << c;
    
    return 0;
}
