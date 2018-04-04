//
//  class_Assign5.c
//  Cpp
//
//  Created by MJMacBook on 2018. 3. 27..
//  Copyright © 2018년 innersme. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ReadNames(char *filename, char **theirNames);
int SearchName(char **theirNames, int n, char *keyName);

int main()
{
    char names[100][40];
    
    char *file = "/Users/innersme/Cloud/C_study/Cpp/inp/name.inp";
    int n = ReadNames(file, names);
    printf("%d\n", n);
    int res = SearchName(names, n, "Soo-Min Lee");
    printf("%d\n", res);
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
        printf("%s\n", theirNames[cnt]);
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
