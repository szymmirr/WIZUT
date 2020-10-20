//SO2 IS1 221B LAB08
//Szymon Mirr
//smirr@wi.zut.edu.pl
#define _GNU_SOURCE
#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    struct crypt_data data[1] = {0};
    //"$6$5MfvmFOaDU"
    char salt[13] = "$6$";
    strcpy(salt, "$6$");
    strcat(salt, argv[2]);
    char *hash = crypt_r(argv[1], salt, data);
    printf("%s\n", hash);
    return 0;
}
