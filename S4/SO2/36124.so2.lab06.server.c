//SO2 IS1 221B LAB06
//Szymon Mirr
//smirr@wi.zut.edu.pl
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

int liczbauserow;
char userzy[20][8];
int userid[20];

void *connection_handler(void *socket_desc)
{
    int sock = *(int*)socket_desc;
    int read_size;
    char *message, client_message[2000];
    int sock2;
    int sock_conn;
    char uzytkownik[8];
    int numertablicy;
  
    if( (read_size = recv(sock, client_message, 2000, 0)) > 0 )
    {
        strcpy(userzy[liczbauserow-1],client_message);
        userid[liczbauserow-1]=sock;
        strcpy(uzytkownik,userzy[liczbauserow-1]);
        numertablicy=liczbauserow-1;
        printf("Podlaczony: %s\n", client_message);
        sleep(1);
        for(int i=0;i<2000;i++)
        {
            client_message[i]='\0';
        }
    }

    while( (read_size = recv(sock, client_message, 2000, 0)) > 0 )
    {
        if(strcmp(client_message,"!lista")==0)
        {
            for (int i = 0; i < liczbauserow; i++)
            {
                if(userid[i]!=0)
                {
                    write(sock, userzy[i], strlen(userzy[i]));
                    write(sock, "\n", strlen("\n"));
                }
            }
            write(sock, "Wpisz nazwe uzytkownika, z ktorym chcesz sie polaczyc", strlen("Wpisz nazwe uzytkownika, z ktorym chcesz sie polaczyc"));
        }
        else
        {
            write(sock_conn, uzytkownik, strlen(uzytkownik));
            write(sock_conn, ": ", strlen(": "));
            write(sock_conn, client_message, strlen(client_message));
            write(sock_conn, " ", strlen(" "));
        }
        for(int i=0;i<20;i++)
        {
            if(strcmp(client_message,userzy[i])==0)
            {
                sock_conn=userid[i];
            }
        }
        strcpy(client_message,"");
        client_message[0] = '\0';
        memset(client_message,0,strlen(client_message));
        for(int i=0;i<2000;i++)
        {
            client_message[i]='\0';
        }
    }
    if(read_size == 0)
    {
        printf("Klient odlaczony\n");
        userid[numertablicy]=0;
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }
    free(socket_desc);
    return 0;
}

int main(int argc , char *argv[])
{
    daemon(0, 0);
    int socket_desc, new_socket, c, *new_sock, portno;
    struct sockaddr_in server, client;
    char *message;
    if(argc<1)
    {
        puts("Nalezy podac parametr");
        return 0;
    }
    if(strcmp(argv[1],"-p")==0)
    {
        if(argc<2)
        {
            puts("Nalezy podac numer portu");
            return 0;
        }
    }

    char buf[128];
    FILE *fp;
    if ((fp = popen("pidof serwer | wc -w", "r")) == NULL)
    {
        printf("Error opening pipe!\n");
        return -1;
    }

    while (fgets(buf, 128, fp) != NULL)
    {

    }

    int numer = buf[0] - '0';

    if(strcmp(argv[1],"-q")==0)
    {
        printf("Zakonczono dzialanie serwera\n");
        system("killall server");
        return 0;
    }

    //printf("numer%d\n",numer);
    if(numer>1)
    {
        printf("Nie mozna uruchomic wiecej niz jednej instancji serwera\n");
    }

    portno = atoi(argv[2]);
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        puts("Could not create socket");
        return 0;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(portno);

    if( bind(socket_desc,(struct sockaddr *)&server, sizeof(server)) < 0)
    {
        puts("bind failed");
        return 0;
    }
    listen(socket_desc , 3);
    puts("Oczekiwanie na podlaczenie sie klienta...");
    c = sizeof(struct sockaddr_in);
    char *users = malloc(20 * sizeof(char*));
    while((new_socket=accept(socket_desc,(struct sockaddr*)&client,(socklen_t*)&c)))
    {
        liczbauserow+=1;
        printf("Klient podlaczony\n");
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = new_socket;
      
        if(pthread_create(&sniffer_thread,NULL,connection_handler,(void*)new_sock)<0)
        {
            printf("Could not create thread");
            return 1;
        }
    }
    if (new_socket<0)
    {
        printf("Accept failed");
        return 1;
    }
    free(new_sock);
    return 0;
}
