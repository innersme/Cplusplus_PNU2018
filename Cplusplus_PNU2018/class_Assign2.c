/* HACK : To use printf, scanf on Visual Studio Environment */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/* the BUFSIZE constant is defined in standard library */
/* But you can define it by #define e.g. "#define BUFSIZ 1024" */


int llength(char* a);
int ilength(int a);
int letter(char* inp);
char* revlet(int inp);
int power (int a, int num);
int StrangeMultiplication(char* m, char* n) {
    printf("%s",revlet(letter(m)*letter(n)));
    return letter(m)*letter(n);
}

int main(int argc, char** argv) {
    char m[BUFSIZ];
    char n[BUFSIZ];
    
    scanf("%s", m);
    scanf("%s", n);
    
    StrangeMultiplication(m, n);
    return 0;
}
/* char 변환 */
int llength(char* a)
{
    int cnt = 0;
    while(a[cnt] != '\0')
    {
        cnt ++;
    }
    return cnt;
}

/* int 변환  */
int ilength(int a)
{
    int cnt = 0;
    while(a > 10)
    {
        a /= 10;
        cnt++;
    }
    return cnt;
}

/* inp: char* -> output: int */
int letter(char* inp)
{
    int length = llength(inp);
    // count;
    int cnt = 0;
    // result;
    int res = 0;
    while(inp[cnt] != '\0')
    {
        res += ( 9 - (inp[cnt]-'a') ) * (power(10,length-cnt-1));
        cnt++;
        //printf("%d %d \n", ares, cnt);
    }
    return res;
}

/* inp: int -> output: char */
char* revlet(int inp)
{
    int cnt = 0;
    /* 변환 */
    int length = ilength(inp);
    
    char *res;
    res = (char*) malloc(sizeof(char) *length);
    
    
    while(cnt != (length+1))
    {
        res[cnt] = 'a' + ( 9 -  inp / power(10, length-cnt) );
        //printf("%d %c\n",inp / power(10, length-cnt),res[cnt]);
        inp %= power(10, length-cnt);
        cnt++;
    }
    
    return res;
}

/* 거듭제곱  */
int power (int a, int num)
{
    if(num == 0)
        return 1;
    return a * power (a, num-1);
}

