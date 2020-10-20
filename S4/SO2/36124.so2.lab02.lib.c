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

int funkcja_a(char * ut_user)
{
	struct passwd *pw;
	pw = getpwnam(ut_user);
	printf("%d ", pw->pw_uid);
	printf("%s\n", ut_user);
    return 0;
}

int funkcja_b(char * ut_user)
{
	int j, ngroups, opcja;
	gid_t *groups;
	struct passwd *pw;
	struct group *gr;
	struct utmpx *e;
	pw = getpwnam(ut_user);
	printf("%s ", ut_user);
	ngroups = atoi("0");
	if (getgrouplist(e->ut_user, pw->pw_gid, groups, &ngroups) == -1)
	{
		groups = malloc(ngroups * sizeof (gid_t));
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
	if(groups!=NULL)
	{
		free (groups);
	}
	return 0;
}

