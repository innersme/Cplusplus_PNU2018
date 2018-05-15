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
    void getName(char *_name){ strcpy(name, _name); }
    void getAge(unsigned int _age) { age = _age; }
    void getDept(char *_dept) {strcpy(dept, _dept); }
    void getScore(float _score) { score = _score; }
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
    Student *retStu;
    string line;
    ifstream myfile(fileName, ios::in);
    if (myfile.is_open()) {
        if (ret) {
            retStu = new Student[ret];
            int cnt = 0;
            while (myfile.good()) {
                getline(myfile, line);
                string tmpname = line.substr(0,20);
                string tmpdept = line.substr(23,20);
                retStu[cnt].getName(tmpname);
                retStu[cnt].getAge(stoi(line.substr(20,3)));
                retStu[cnt].getDept(tmpdept);
                retStu[cnt].getScore(stoi(line.substr(43,4)));
                cnt++;
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
