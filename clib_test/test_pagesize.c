#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    int     pagesize = getpagesize();
    printf("pagesize: %d\n", pagesize);
    return 0;
}
