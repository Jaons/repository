#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>

int main(int argc, char **argv)
{
    //struct in_addr  usr_sin_addr;
    struct sockaddr_in  sin;

    //usr_sin_addr.s_addr = (in_addr_t)atol(argv[1]);
    //usr_sin_addr.port = (in_addr_t)atol(argv[2]);
    sin.sin_addr.s_addr    = (in_addr_t) atol (argv[1]);
    sin.sin_port    = atoi (argv[2]);

    
    printf("IP：%s\n", inet_ntoa(sin.sin_addr)); 
    printf("port：%d\n", htons(sin.sin_port)); 

    printf("%d\n", sizeof(":65535"));
    
    return 0 ;  
}
