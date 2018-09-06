//code to connect to the server, read in GPS data and write to a file
//run executable without sudo command

#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include<unistd.h>
#include <iostream>
#include <fstream>
 
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];
    
    //setup to write to a file
    ofstream.dataFile;
    dataFile.open ("dataBag.txt");
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr("192.168.1.200");
    server.sin_family = AF_INET;
    server.sin_port = htons( 24000 );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");
    int bytes;
    //keep communicating with server
    while(1)
    {
        // printf("Enter message : ");
        // scanf("%s" , message);
         
        // //Send some data
        // if( send(sock , message , strlen(message) , 0) < 0)
        // {
        //     puts("Send failed");
        //     return 1;
        // }
        
        bytes = recv(sock , server_reply , 2000 , 0);
        //Receive a reply from the server
        if( bytes < 0)
        {
            puts("recv failed");
            break;
        }
         
        puts("Server reply :");
        puts(server_reply);

        dataFile << server_reply;
    }
    dataFile.close();
    close(sock);
    return 0;
}