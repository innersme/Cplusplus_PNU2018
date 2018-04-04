//
//  class_Assign3.c
//  Cpp
//
//  Created by MJMacBook on 2018. 3. 13..
//  Copyright © 2018년 innersme. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void MyReadIntegers(char* fileName, int N, int *values);
void MySortIntegers(int N, int *values);
int MySearchInteger(int *values, int N, int keyValue);

int main()
{
    int score[12] = {0, }; int i;
    MyReadIntegers("/Users/innersme/Cloud/C_study/Cpp/inp/math.txt", 12, score);
    for (i = 0 ; i < 12; i++) {
        printf("%d: %d\n",i+1,score[i] );
    }
    MySortIntegers(12, score);
    for (i = 0 ; i < 12; i++) {
        printf("%d: %d\n",i+1,score[i] );
    }
    printf("%d\n", MySearchInteger(score, 12, 45));
    
    return 0;
}

void MyReadIntegers(char* fileName, int N, int *values)
{
    int i;
    FILE *fp = fopen(fileName, "r");
    for (i = 0; i < N; i++) {
        if (fscanf(fp, "%d", &values[i]) == EOF)
            break;
    }
    fclose(fp);
}

void MySortIntegers(int N, int *values)
{/* cur: array's cur */
    int i; int j; int cur;
    int *res = (int *)malloc(sizeof(int) * N);
    // sort
    for (i = 0 ; i < N ; i++) {
        j = 0;
        while (res[j] < values[i]) j++;
        cur = i;
        while (cur > j) {
            res[cur] = res[cur-1];
            cur--;
        }
        res[cur] = values[i];
    }
    for (i = 0 ; i < N ; i++) {
        values[i] = res[i];
    }
    free(res);
}

int MySearchInteger(int *values, int N, int keyValue)
{
    int cnt = 0;
    while ( values[cnt] != keyValue ) {
        cnt++;
        if (N == cnt) {
            break;
        }
    }
    if (cnt != N) {
        // because rank = cnt+1
        return cnt+1;
    }
    return -1;
}
