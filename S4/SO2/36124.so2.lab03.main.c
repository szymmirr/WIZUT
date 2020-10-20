//SO2 IS1 221B LAB03
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

int main(int argc, char *argv[])
{
	printf("%d ", getpid());
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
		if (fork() == 0)
		{
			execl(argv[0], argv[0], polowa1, rodzice, (char *)NULL);
		}

		if (fork() == 0)
		{
			execl(argv[0], argv[0], polowa2, rodzice, (char *)NULL);
		}

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
	for(int i=1;i<argc;i++)
	{
		printf("%s ",argv[i]);
	}
	printf(" \n");
	return 0;
}

