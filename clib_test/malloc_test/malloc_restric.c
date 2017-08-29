#include <stdio.h>
#include <malloc.h>

int main(int argc, char **argv)
{
    int                 ret = 0;
    char                *ptr;
    int                 g = 1;
    int                 m = 1;
    int                 k = 1;
    int                 b = 1;
    long                num = 0;

    while ((ptr = (char*)malloc(g * 1024*1024*1024)) != NULL) {
        g++;
        free(ptr);
    }
    g--;
    while ((ptr = (char*)malloc(g*1024*1024*1024 + m*1024*1024)) != NULL) {
        m++;
        free(ptr);
    }
    m--;
    while ((ptr = (char*)malloc(g*1024*1024*1024 + m*1024*1024 + k*1024)) != NULL) {
        k++;
        free(ptr);
    }
    k--;
    while ((ptr = (char*)malloc(g*1024*1024*1024 + m*1024*1024 + k*1024 + b)) != NULL) {
        b++;
        free(ptr);
    }
    b--;
    printf("%dG%dM%dK%dB\n", g, m, k,b);
    printf("total: %ld bytes\n", g*1024*1024*1024+m*1024*1024+k*1024+b);
    
    num = 1024*1024*1024;
    printf("2GB: %ld bytes\n", 2*num);
    return 0;
}
