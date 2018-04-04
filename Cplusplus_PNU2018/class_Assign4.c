//
//  class_Assign4.c
//  Cpp
//
//  Created by MJMacBook on 2018. 3. 20..
//  Copyright © 2018년 innersme. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define nameLength  40

typedef struct{
    int age;
    int ID;
    float score;
    char name[nameLength];
} Student;

int ReadStudents(char* filename, Student **students);
// int PrintID(Student *students, int ID);
// int SearchScore(Student *students, float minScore, float maxScore);

int main()
{
    char* file = "/Users/innersme/Cloud/C_study/Cpp/inp/class_Assign4.inp";
    Student *students;
    int cnt = 0;
    int read = ReadStudents(file, &students);
    printf("%d %d %f %s\n", students[cnt].age, students[cnt].ID,students[cnt].score, students[cnt].name);
    
    printf("%d", read);
    return 0;
}

int ReadStudents(char* filename, Student **students)
{
    FILE *fp = fopen(filename, "r");
    int cnt = 0;
    char tmp[10];
    // N; 받는 students
    int N = 100;
    *students = (Student *) malloc(sizeof(Student) * N);
    
    while( fscanf(fp, "%d %d %f %s %s", &(students[cnt])->age,&(students[cnt])->ID,&(students[cnt])->score, students[cnt]->name,tmp) != EOF)
    {
        strcat(students[cnt]->name, " ");
        strcat(students[cnt]->name, tmp);
        cnt++;
    }

    
    fclose(fp);
    return cnt;
}
