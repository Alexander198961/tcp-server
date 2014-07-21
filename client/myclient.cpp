#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <typeinfo>
#include <unistd.h>
#include <time.h>
using namespace std;
int main(int arg , char *argv[] )
{
   int sockfd, portno ;
   struct sockaddr_in serv_addr;
   struct hostent *server;
   char buffer[256];
   sockfd = socket(AF_INET,SOCK_STREAM,0);
   //char str[] ="127.0.0.1";
   const char *addr = "127.0.0.1";
   //portno = atoi(argv[0]);
   portno = 509;
   sockfd = socket(AF_INET,SOCK_STREAM,0);
   if(!sockfd)
   {
    printf("Error get");
   }
   //cout << typeid(*addr).name();
   server = gethostbyname(addr);
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_port = htons(portno);
   bcopy((char *)server->h_addr,
            (char *)&serv_addr.sin_addr.s_addr,
	             server->h_length);
while (1)	
   { sleep(10);
   if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
           printf("Error");
}	   
while(1)
{
   bzero(buffer,256);
   fgets(buffer,255,stdin);
   int  n = write(sockfd,buffer,strlen(buffer));
   
   if (n < 0) 
   printf("this is test");
   bzero(buffer,256);
   n = read(sockfd,buffer,255);
   if (n < 0) 
       printf("this is test");
}       
 return 0;
}
