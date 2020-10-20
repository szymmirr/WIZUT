//SO2 IS1 221B LAB04
//Szymon Mirr
//smirr@wi.zut.edu.pl
#include <stdio.h>
#include <stdlib.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <utmpx.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int ctrlz = 0;
int ctrlc = 0;

void obslugaint(int s)
{
	if (s == SIGINT)
    {
		ctrlc = 1;
    }
	if (s == SIGTSTP)
    {
		ctrlz = 1;
    }
}

int main(int argc, char *argv[])
{
	int x = 1;
	sigset_t iset;
	struct sigaction act;
	sigemptyset(&iset);
	act.sa_handler = &obslugaint;
	act.sa_mask = iset;
	act.sa_flags = 0;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGTSTP, &act, NULL);
	printf("%d ", getpid());
	pid_t pid;
	int parent=0;
	

	if(strlen(argv[1])>=2)
	{
		int length=0;

		for(int i=1;i<argc;i++)
		{
			length=strlen(argv[i])+length+1;
		}

		char *rodzice = malloc(sizeof(char)*length + 1);
		rodzice[0]=0;

		for(int i=1;i<argc;i++)
		{
			strcat(rodzice, argv[i]);
			strcat(rodzice, " ");
		}

		char *progname = "./a.out";
		int czypotega=1;
		int rozm=strlen(argv[1]);
		char *slowo = malloc(strlen(argv[1]));
		strcpy(slowo,argv[1]);
		int potega = rozm;

		do
		{
			czypotega==1;
			rozm=strlen(slowo);
			potega = rozm;
			while(potega % 2 == 0)
			{
				potega = potega / 2;
				czypotega=1;
			}
			if(potega > 1)
			{
				czypotega=0;
				slowo[strlen(slowo)-1] = 0;
			}
		}
		while(czypotega==0);

		char polowa1[rozm/2], polowa2[rozm/2];
		strncpy(polowa1, argv[1], rozm/2);
		strncpy(polowa2, argv[1] + (rozm/2), rozm/2);
		polowa1[rozm/2]=0;
		polowa2[rozm/2]=0;
		
		pid_t pid;
		if (pid = fork() == 0)
		{
			if(-1 == setsid())
			{
				perror("");
			}
			execl(argv[0], argv[0], polowa1, rodzice, (char *)NULL);
		}
		if (fork() == 0)
		{
			if(-1 == setsid())
			{
				perror("");
			}
			else
			execl(argv[0], argv[0], polowa2, rodzice, (char *)NULL);
		}
		else
		{
			parent=1;
			while (ctrlc!=1);
		}
		
		for(int i=1;i<argc;i++)
		{
			printf("%s ",argv[i]);
		}
		printf(" \n");
		kill(pid,SIGINT);
		x=0;

		pid_t child_pid, wpid;
		int status = 0;
		while ((wpid = wait(&status)) > 0)
		{
			if(wpid==-1)
			{
				printf("BLAD");
				return 0;
			}
		}
		if(rodzice)
		{
			free(rodzice);
		}
		if(slowo)
		{
			free(slowo);
		}
	}
	
	if(parent==1)
	{
		if(ctrlz==1)
		{
			printf("W czasie dzialania programu pojawil sie sygnal Ctrl-Z\n");
		}
		else
		{
			printf("W czasie dzialania programu nie pojawil sie sygnal Ctrl-Z\n");
		}
	}
	return 0;
}

