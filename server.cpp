/*
    C socket server example
*/
 
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include <iostream>

int main(int argc , char *argv[])
{
    int sd = socket( AF_INET,SOCK_STREAM, 0);
    socklen_t clien;
    char buffer[256];
    struct sockaddr_in serv_addr , cli_addr;
    //memset
    
    bzero((char * ) &serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(509);
    if (bind(sd, (struct sockaddr * ) &serv_addr ,sizeof(serv_addr)  ) < 0 ) {
	perror("bind");
    }
    listen(sd,3);
    clien = sizeof (cli_addr);
    int newsockfd = accept (sd, (struct sockaddr *) &cli_addr, &clien );
    bzero(buffer,256);
    while(1)
    {
     int n = read(newsockfd,buffer , 255 );
     std::cout << buffer<< std::endl;
     //sleep 
     bzero(buffer,256);
     }
    //int response  = connect(sd, ( struct sockaddr * ) &serv_addr ,sizeof(serv_addr));
   // std::cout << response << std::endl;
    //listen(sd,3);
    //clien
    return 0;
}
