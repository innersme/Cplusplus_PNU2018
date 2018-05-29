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
    Student();
    Student(char _name[20], unsigned int, char _dept[20], float);
    Student(const Student&);
    char* getName(){return name;}
    unsigned int getAge() { return age; }
    char* getDept() { return dept; }
    float getScore() { return score; }
    void setName(string _name){
        const char *tmp = _name.c_str();
        for (int i = 0 ; i < 20 ; i++) {
            name[i] = tmp[i];
        }
    }
    void setAge(unsigned int _age) { age = _age; }
    void setDept(string _dept) {
        const char *tmp = _dept.c_str();
        for (int i = 0 ; i < 20 ; i++) {
            dept[i] = tmp[i];
        }
    }
    void setScore(float _score) { score = _score; }
    friend ostream& operator <<(ostream&, const Student&);
};
Student::Student()
{
    strcpy(name, "");
    age = 0;
    strcpy(dept, "");
    score = 0;
}

Student::Student(char _name[20], unsigned int _age, char _dept[20], float _score){
    strcpy (name , _name);
    age = _age;
    strcpy (dept , _dept);
    score = _score;
    // cout << "Constructor2" << endl;
}

Student::Student(const Student& a)
{
    strcpy(name, a.name);
    age = a.age;
    strcpy(dept, a.dept);
    score = a.score;
}

ostream& operator<<(ostream& os, const Student& stud)
{
    for(int i = 0; i <20; i++){
        os << *(stud.name + i);
    }
    os << stud.age;
    for(int i = 0; i <20; i++){
        os << *(stud.dept + i);
    }
    os << stud.score;
    return os;
}

int readFromTextFile(char* fileName, Student **students);
void writeToBinaryFile(char* fileName, int n, Student *students);
int readFromBinaryFile(char* fileName, Student **students);
void writeToTextFile(char* fileName, int n, Student *students);

int main()
{
    Student* pStudent;
    char* fileName = "assign10.inp";
    char* outbin = "bin10.bin";
    char* outtext = "text10.txt";
    int NofStu = readFromTextFile(fileName, &pStudent);
    for (int i = 0 ; i < NofStu; i++) {
        cout << pStudent[i] << endl;
    }
    Student* bStudent;
    writeToBinaryFile(outbin, NofStu, pStudent);
    int NofStu2 = readFromBinaryFile(outbin, &bStudent);
    for (int i = 0 ; i < NofStu2; i++) {
        cout << bStudent[i] << endl;
    }
    writeToTextFile(outtext,NofStu2,bStudent);
    return 0;
}

int readFromTextFile(char* fileName, Student **students)
{
    Student *retStu;
    string line;
    ifstream myfile(fileName, ios::in);
    getline(myfile, line);
    int ret = stoi(line);
    if (myfile.is_open()) {
        retStu = new Student[ret];
        for (int i = 0 ; i < ret; i++) {
            getline(myfile, line);
            retStu[i].setName(line.substr(0,20));
            retStu[i].setAge(stoi(line.substr(20,3)));
            retStu[i].setDept(line.substr(23,20));
            retStu[i].setScore(stof(line.substr(43,4)));
        }
    }
    else return -1;
    *students = retStu;
    // delete []retStu;
    return ret;
}

void writeToBinaryFile(char* fileName, int n, Student *students)
{
    ofstream myfile(fileName, ios::out | ios::binary);
    if (myfile.is_open()) {
        myfile.write((char*)(&n), sizeof(int));
        for (int i = 0 ; i < n ; i ++) {
            myfile.write((char*)(students+i), sizeof(Student));
        }
    }
    myfile.close();
}

int readFromBinaryFile(char* fileName, Student **students)
{
    ifstream in(fileName,ios::in | ios::binary);
    Student *retStub;
    int n;
    if(in.is_open()){
        in.read((char*)(&n),sizeof(int));
        retStub = new Student[n];
        // cout <<"<out.dat> opened, \nn = "<< n << endl <<endl;
        
        for(int i = 0; i < n; i++){
            in.read((char*)(retStub+i), sizeof(Student));
            // cout << retStu[i] << endl;
        }
    }
    else{
        cout<<"can not find file"<<endl;
        return -1;
    }
    in.close();
    *students = retStub;
    // delete []retStub;
    return n;
}

void writeToTextFile(char* fileName, int n, Student *students)
{
    // cout << "Start4point" << endl;
    ofstream myfile(fileName);
    if (myfile.is_open()) {
        myfile << n <<endl;
        for (int i = 0; i < n ; i++) {
            myfile << *(students+i) << endl;
        }
    }
    myfile.close();
}
