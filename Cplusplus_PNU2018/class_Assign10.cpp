//
//  class_Assign10.cpp
//  Cplusplus_PNU2018
//
//  Created by MJMacBook on 09/05/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student{
    char            name[20];
    unsigned int    age;
    char            dept[20];
    float           score;
    
public:
};

int readFromTextFile(char* fileName, Student **students);
void writeToBinaryFile(char* fileName, int n, Student *students);
int readFromBinaryFile(char* fileName, Student **students);
void writeToTextFile(char* fileName, int n, Student *students);

int main()
{
    Student* pStudent;
    char* fileName = "assign10.inp";
    string line;
    int NofStu = readFromTextFile(fileName, &pStudent);
    return 0;
}

int readFromTextFile(char* fileName, Student **students)
{
    int ret = 0;
    string line;
    ifstream myfile(fileName, ios::in);
    if (myfile.is_open()) {
        if (ret) {
            *students = new Student[ret];
            for (int i = 0 ; i < ret; i++) {
                
            }
            while (myfile.good()) {
                 getline(myfile, line);
            }
        }
        else{
            getline(myfile, line);
            ret = stoi(line);
        }
    }
    else return 0;
    
    return ret;
}
