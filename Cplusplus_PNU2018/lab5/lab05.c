#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STORAGE 100
#define MAX_NAME_LENGTH 40

int ReadNames(char* filename, char **theirNames);
int SearchName(char **theirNames, int n, char *keyName);
int countSameName(char **theirNames, int n, char *keyName);

int main(){
    char** names;
    int i = 0;
    names = (char**)malloc(sizeof(char*) * MAX_STORAGE);
    for (i = 0; i < 100; i++) {
        names[i] = (char*)malloc(sizeof(char) * MAX_NAME_LENGTH);
    }
    int number = ReadNames("input.txt", names);
    printf("The number of Names : %d\n", number);
    for (i = 0; i < number; i++) {
        printf("%s\n", names[i]);
    }
    SearchName(names, number, "Clyde Parker");

    return 0;
}


int ReadNames(char *filename, char **theirNames)
{
    FILE *fp = fopen(filename, "r");
    int cnt = 0; char tmp[40];
    while ( fscanf(fp, "%s %s", theirNames[cnt], tmp) != EOF )
    {
        // printf("%s %s\n", theirNames[cnt], tmp);
        strcat(theirNames[cnt], " ");
        strcat(theirNames[cnt], tmp);
        //printf("%s\n", theirNames[cnt]);
        cnt++;
    }
    fclose(fp);
    return cnt;
}

int SearchName(char **theirNames, int n, char *keyName)
{
    int cnt = 0;
    while (cnt != n ) {
        if (!strcmp(theirNames[cnt], keyName)) {
            break;
        }
        cnt++;
    }
    if (n == cnt) {
        printf("No name found\n");
        return 0;
    }
    return cnt+1;
}

int countSameName(char **theirNames, int n, char *keyName)
{
    int cnt = 0; int res = 1;
    while (cnt != n ) {
        if (!strcmp(theirNames[cnt], keyName)) {
            res++;
        }
        cnt++;
    }
    if (n == cnt) {
        printf("No name found\n");
        return 0;
    }
    printf("%d\n",res);
    return res;
}
