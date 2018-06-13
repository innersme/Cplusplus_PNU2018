//
//  Assign1.c
//  Cplusplus_PNU2018
//
//  Created by MJMac on 13/06/2018.
//  Copyright © 2018 MJMacBook. All rights reserved.
//
#include <stdio.h>

float sumRecursive(int i, float* values)
{
    if (i == 0) {
        return 0;
    }
    else
    {
        return values[i-1] + sumRecursive(i-1, values);
    }
}

void strcpy_arr(char a[], char b[])
{
    int cnt = 0;
    while (a[cnt] != '\0') {
        b[cnt] = a[cnt];
        cnt++;
    }
}

void strcpy_pointer(char* a, char* b)
{
    while ( *a != '\0')
    {
        *b++ = *a++;
    }
}

int main()
{
    char a[10] = "absrc\0";
    char b[10];
    
    char c[10] = "123345\0";
    char d[10];
    
    float values[] = {1,2,3,4,5};
    
    strcpy_arr(a,b);
    strcpy_pointer(c,d);
    float result = sumRecursive(5,values);
    
    printf("%s\n",b);
    printf("%s\n",d);
    printf("%f\n",result);
    
    return 0;
}


