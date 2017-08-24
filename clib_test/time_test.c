#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
    time_t          tim;

    struct tm       *tm;
    
    if (argc < 2) {
        printf ("fucking error  args\n");
        return 0;
    }
    
    tim = atol(argv[1]);
    
    tm = localtime(&tim);
    
    printf("%04d:%02d:%02d  %02d:%02d:%02d\n", tm->tm_year + 1900, tm->tm_mon, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
    
    return 0;
}
