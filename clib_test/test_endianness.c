#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int i = 0x11223344;
    char *p;

    p = (char *) &i;
    if (*p == 0x44) return 0;
    return 1;
}
