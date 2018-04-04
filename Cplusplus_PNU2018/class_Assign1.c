//
//  class_Assign1.c
//  Cpp
//
//  Created by MJMac on 2018. 3. 8..
//  Copyright © 2018년 innersme. All rights reserved.
//

#include <stdio.h>

float sumRecursive(int i, float* values)
{
    float res = values[i-1];
    if (i == 0) {
        return 0;
    }
    else
    {
        return res + sumRecursive(i-1, values);
    }
}

void strcpy_arr(char a[], char b[])
{
    int cnt = 0;
    while (1) {
        if (a[cnt] == '\0') {
            break;
        }
        else
        {
            b[cnt] = a[cnt];
            cnt++;
        }
    }
}

void strcpy_pointer(char* a, char* b)
{
    while (1) {
        if (*a == '\0') {
            break;
        }
        else
        {
            *b++ = *a++;
        }
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


