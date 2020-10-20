//SO2 IS1 221B LAB01
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

int main(int argc, char *argv[])
{
	int a = 0;
	int b = 0;
	char *cvalue = NULL;
	int index;
	int c;
	int optind=0;
	opterr = 0;
	int o=0;
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
	int j, ngroups;
	gid_t *groups;
	struct passwd *pw;
	struct group *gr;
	struct utmpx *e;
	while (e = getutxent())
	{
		if(e->ut_type==7)
		{
			pw = getpwnam(e->ut_user);
			if(a==1)
			{
				printf("%d ", pw->pw_uid);
			}
			printf("%s ", e->ut_user);
			if(o==0)
			{
				printf("\n");
			}
			if(a==1&&b==0)
			{
				printf("\n");
			}
			if(b==1)
			{
				ngroups = atoi("0");
				groups = malloc(ngroups * sizeof (gid_t));
				if (getgrouplist(e->ut_user, pw->pw_gid, groups, &ngroups) == -1)
				{
					getgrouplist(e->ut_user, pw->pw_gid, groups, &ngroups);
				}
				printf("[");
				for (j = 0; j < ngroups; j++)
				{
					gr = getgrgid(groups[j]);
					if (gr != NULL)
					{
						printf("%s", gr->gr_name);
					}
					if (j<ngroups-1)
					{
						printf(", ");
					}
				}
				printf("]");
				printf("\n");
			}
		}
	}
	free (groups);
	return 0;
}

