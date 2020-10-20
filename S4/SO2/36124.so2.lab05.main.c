//SO2 IS1 221B LAB05
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
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("/proc")) != NULL)
	{
		while ((ent = readdir (dir)) != NULL)
		{
			if (isdigit(ent->d_name[0]))
			{
				char path[PATH_MAX];
				char procpath[PATH_MAX];
				char dest[PATH_MAX];
				struct stat info;
				pid_t pid = getpid();
				sprintf(procpath, "/proc/%s/comm", ent->d_name);

				FILE *o;
				char x[PATH_MAX];
				if((o=fopen(procpath,"r"))!=NULL)
				{
					fscanf(o,"%s",x);
					fclose(o);
				}

				if(strcmp(argv[1], x)==0)
				{
					if(strcmp(argv[0], "./killall")==0)
					{
						pid_t pid = atoi(ent->d_name);
						kill(pid,SIGINT);
					}
					else
					{
						printf ("%s ", ent->d_name);
					}
				}
			}
		}
		closedir (dir);
	}
	else
	{
		perror ("");
		return EXIT_FAILURE;
	}
	printf(" \n");
	return 0;
}

