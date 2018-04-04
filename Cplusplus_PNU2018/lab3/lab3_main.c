#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void MyReadIntegers(char* fileName, int *values, int N) {
    int i;
    FILE *fp = fopen(fileName, "r");
    for (i = 0; i < N; i++) {
        if (fscanf(fp, "%d", &values[i]) == EOF)
            break;
    }
    fclose(fp);
}

void MySortIntegers(int *values, int N){
    /* cur: array's cur */
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

int MySearchInteger(int *values, int N, int keyValue){
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

int MyMaxInteger(int *values, int N) {
    /* cur: array's cur */
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
    return values[N-1];
}

int main() {
    char* file = "test1_17.txt";
    int N = 17;
    int key = 4359; // number you need to find
    int values[N];
	int max;
	int i;
	
    MyReadIntegers(file, values, N);

    printf("Unsorted array: ");
    for(i = 0;i < N; i++){
        printf("%d\t", values[i]);
    }
	printf("\n");
	
	max = MyMaxInteger(values, N);
	printf("max : %d\n", max);
	
    MySortIntegers(values, N);

    printf("\nSorted array: ");
    for(i = 0;i < N; i++){
        printf("%d\t", values[i]);
    }
	printf("\n");
	
    int index = MySearchInteger(values, N, key);
    printf("\nIndex: %d", index);

    return 0;
}
