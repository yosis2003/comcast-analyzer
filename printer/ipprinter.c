#define _POSIX_C_SOURCE 200112L
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#define PORT 8080 





int main (int argc, char *argv[]){

    int status;
    struct addrinfo hints, *p, *servinfo;
    char ipstr[INET6_ADDRSTRLEN];
    memset(&hints, 0, sizeof hints); // make sure the struct is empty
    hints.ai_family = AF_UNSPEC; // don't care IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
    hints.ai_flags = AI_PASSIVE; 


    printf("argument passed in %s \n", argv[1]);


    status = getaddrinfo(argv[1], "http", &hints, &servinfo);



    if (status == 0  && servinfo->ai_addr != NULL){
        for (p = servinfo; p != NULL; p = p->ai_next){
        void *addr;
        char *ipver;

        struct sockaddr_in *ipv4;
        struct sockaddr_in *ipv6;

        if (p->ai_family == AF_INET)
        {
            ipv4 = (struct sockraddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);

        }
        else{
            ipv6 = (struct sockraddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin_addr);
        }

        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);

        printf("%s \n", ipstr);


        }

    }





    // printf("canonical name: %s \n", servinfo->ai_canonname);

    






    


}



