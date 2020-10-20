//SO2 IS1 221B LAB06
//Szymon Mirr
//smirr@wi.zut.edu.pl
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>

void* wyslij (void *socket_desc)
{
    int sockfd = *(int*)socket_desc;
    char buffer[2000];
    while(1)
    {
        //printf("> ");
        scanf("%s", buffer);
        if( send(3, buffer, strlen(buffer), 0) < 0)
        {
            puts("Blad wysylania");
        }
        strcpy(buffer,"");
        buffer[0] = '\0';
        memset(buffer,0,strlen(buffer));
        for(int i=0;i<2000;i++)
        {
            buffer[i]='\0';
        }
    }
}

void* odbierz (void *socket_desc)
{
    while(1)
    {
        int sockfd = *(int*)socket_desc;
        char buffer2[2000];
        if( recv(3, buffer2, 2000, 0) < 0)
        {
            puts("recv failed");
        }
        puts(buffer2);
        strcpy(buffer2,"");
        buffer2[0] = '\0';
        memset(buffer2,0,strlen(buffer2));
        for(int i=0;i<2000;i++)
        {
            buffer2[i]='\0';
        }
    }

    return 0;
}

void *connection_handler(void *socket_desc)
{
    int read_size;
    char *message, client_message[2000];
    int sock = *(int*)socket_desc;
  
    if( (read_size = recv(sock, client_message, 2000, 0)) > 0 )
    {
        printf("Podlaczony: %s\n", client_message);
        sleep(2);
    }

    while( (read_size = recv(sock, client_message, 2000, 0)) > 0 )
    {
        write(sock==4?5:4, client_message, strlen(client_message));
        strcpy(client_message,"");
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n, n2;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[2000], buffer2[2000], nazwa[8];
    char **orderedIds;

    if(argc<6)
    {
        puts("Nalezy podac adres IP, numer portu i swoja nazwe uzytkownika\n");
        return 0;
    }

    server = gethostbyname(argv[2]);
    portno = atoi(argv[4]);
    strcpy(nazwa,argv[6]);

    if(argv[1]=="-a"||argv[3]=="-a"||argv[5]=="-a")
    {
        puts("Nalezy podac numer portu");
        return 0;
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error opening socket\n");
        return 0;
    }
 
    if (server == NULL)
    {
        printf("Error, no such host\n");
        return 0;
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    {
        printf("Blad polaczenia\n");
        return 0;
    }
    puts("Nawiazano polaczenie. Wpisz !lista aby wyswietlic liste uzytkownikow");


    send(sockfd, argv[6], strlen(argv[6]), 0);

    int i=0;
    int sockfd2,*sock2;
    pthread_t sniffer_thread;
    sock2 = malloc(1);
    *sock2 = sockfd2;

    pthread_t thread_id;
    pthread_create ( &thread_id, NULL, wyslij, sock2);
    pthread_t thread_id2;
    pthread_create ( &thread_id2, NULL, odbierz, sock2);
    while (1)
    {
      
    }  

    free(sock2);
    close(sockfd);
    return 0;
}
