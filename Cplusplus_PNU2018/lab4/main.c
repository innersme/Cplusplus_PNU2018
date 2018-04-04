#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define nameLength    40
typedef struct {
    int age;
    int ID;
    float score;
    char name[nameLength];
} Student;

int ReadStudents(char*, Student **);
int PrintID(Student *, int, int);
int SearchScore(Student *, int, float, float);

int main() {
    char* filename = "test.txt";
    int i;
    Student *students;
    int test_ID = 201322548;
    float tset_minScore = 3.0;
    float test_maxScore = 4.0;
    int num = ReadStudents(filename, &students);
    for (i = 0; i < num; i++) {
        printf("%d %d %f %s\n", students[i].age, students[i].ID, students[i].score, students[i].name);
    }
    printf("학생 수는 총 %d명입니다.\n", num);
    if (PrintID(students, num, test_ID) == 0) {
        printf("해당 학생을 찾지 못했습니다.\n");
    }
    int searched_num = SearchScore(students, num, tset_minScore, test_maxScore);
    printf("%d명의 학생이 점수 범위 내에 속합니다.\n", searched_num);
    return 0;
}

int ReadStudents(char* filename, Student **students) {
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
int PrintID(Student *students, int n, int ID) {
    int i;
    int result = 0;
    for (i = 0; i < n; i++) {
        if (students[i].ID == ID) {
            printf("해당 ID의 학생은 %s입니다.\n", students[i].name);
            result = 1;
        }
    }
    return result;
}
int SearchScore(Student *students, int n, float minScore, float maxScore){
    int i;
    int result = 0;
    for (i = 0; i < n; i++) {
        if (students[i].score >= minScore && students[i].score <= maxScore) {
            printf("%s 학생이 점수 범위 내에 속합니다.\n", students[i].name);
            result++;
        }
    }
    return result;
}
