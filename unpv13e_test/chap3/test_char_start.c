#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    int     len;
    char    *tmp = NULL;
    char    *ptr;
    int     v_len;
    int     nbytes = 0;

    FILE    *fp;
    
    tmp = (char *)malloc(128 * sizeof(char));
    if (tmp == NULL)
        return 0;
    else
        len = snprintf(tmp, 128, "fuck you! I will destroy:you!");
    
    printf("%d\n", len);
    printf("%c\n", *(tmp + len - 3));
    printf("%s\n", tmp + len - 2);
    //*(tmp + len - 3) = '\0';
    printf("%s\n", tmp);

    if ((ptr = strchr(tmp, ':')) == NULL)
        return 0;
    else
    {
        v_len = len - (ptr - tmp) - 1;
        printf("%d\n", v_len);
        printf("%c\n", *(tmp + len - v_len));
        printf("%c\n", *(tmp + (ptr - tmp)));
    }

    *(tmp + len) = 1;

    if ((fp = fopen("./fuck.txt", "wb+")) == NULL)
    {
        printf("open file error[%d]: %s\n", errno, strerror(errno));
        return (0 - abs(errno));
    }
    if ((nbytes = fwrite(tmp, 1, len+1, fp)) != len + 1)
    {
        printf("fwrite file error\n");
        return 0;
    }
    
    return 0;
    
}
