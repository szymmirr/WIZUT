//SO2 IS1 221B LAB02
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
#include <dlfcn.h>

int call_library(char * ut_user, int opcja, void *handle)
{
	if(opcja==1)
	{
		int (*func)(char * ut_user) = dlsym(handle, "funkcja_a");
		if (func == NULL)
		{
			return 2;
		}
		func(ut_user);
	}
	if(opcja==2)
	{
		int (*func)(char * ut_user) = dlsym(handle, "funkcja_b");
		if (func == NULL)
		{
			return 2;
		}
		func(ut_user);
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int a=0, b=0, c, o=0;
	while ((c = getopt (argc, argv, "ab")) != -1)
	{
		switch (c)
		{
			case 'a':
				o=1;
				a=1;
				break;
			case 'b':
				o=1;
				b=1;
				break;
			default:
				break;
		}
	}
	int f1=1, f2=1;
	void *handle  = NULL;
	handle = dlopen("./libprog.so", RTLD_NOW | RTLD_GLOBAL);
	if(c=='a'||c=='b')
	{
		if (handle == NULL)
		{
			printf("Nie mozna otworzyc biblioteki\n");
		}
	}

	int j, ngroups, opcja, check=0;
	gid_t *groups;
	struct passwd *pw;
	struct group *gr;
	struct utmpx *e;
	while (e = getutxent())
	{
		if(e->ut_type==7)
		{
			if(a==1)
			{
				check = call_library(e->ut_user, 1, handle);
				if(check==2&&f1==1)
				{
					f1=0;
					printf("Brak wymaganej funkcji\n");
				}
			}
			if(b==1)
			{
				check = call_library(e->ut_user, 2, handle);
				if(check==2&&f2==1)
				{
					f2=0;
					printf("Brak wymaganej funkcji\n");
				}
			}
			if(o==0||check==2)
			{
				struct passwd *pw;
				pw = getpwnam(e->ut_user);
				printf("%s\n", e->ut_user);
			}
		}
	}
	return 0;
}

