
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

__start()
{
    printf("hello world\n");
    exit(0);
}

int main(int argc, char** argv)
{
    char    *result;
    char    str[] = "ILOVEYOU";
    char    *str1;
    char    *next = NULL;
    char    accept[] = "LO";

    char    buf[1024];
    int     clone_count = 3;
    int     i = 0;

    char    *str2 = "123456789";

    if( (result = strpbrk(str, accept)) != NULL)
        printf("%s\n", result);
    
    if( (result = strpbrk(str, "A")) != NULL)
        printf("%s\n", result);
    
    if( (result = strpbrk(str, "O")) != NULL)
        printf("%s\n", result);
    
    if( (result = strpbrk(str, "YO")) != NULL)
        printf("%s\n", result);
    
    if( (result = strpbrk(str, "IO")) != NULL)
        printf("%s\n", result);

    memcpy(buf, "0123456789ABCDEF", 16);    
    for (i = 1; i < clone_count; i++) {
            buf[i * 16 + (i-1)] = '\n';
            memcpy(buf + i * 16 + i, buf, 16);
    }

    printf("buf: %s\n\n", buf);

    printf("len: %d\n", sizeof("1970/09/28 12:00:00"));

    printf("size of buf: %d\n", sizeof(buf));
    
    str1 = (char *)malloc(128 * sizeof(char));
    //snprintf (str1, 128, "%s", "I.LOVE.YOU");
    memcpy(str1, "I.LOVE.YOU", 11);
    do {
        if ((next = strchr(str1, '.')) != NULL) {
            printf("%s\n", next);
            *next++ = '\0';
            printf("%s\n", next);
            printf("%s\n", str1);
        }
        
        str1 = next;
    } while (next != NULL);

    return 0;
}
