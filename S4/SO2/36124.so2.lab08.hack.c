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
#include <errno.h>
#include <err.h>
#include <pthread.h>
#include <linux/limits.h>

struct readThreadParams
{
    const char * hash;
    char * buf;
    char * buf_end;
};

struct timespec start, finish;
struct readThreadParams readParams[128];
double elapsed;
int zlamane = 0;

int print_line(const char* begin, const char* end, const char* hash1)
{
        int dlug = end-begin,hm;
        char *haslo;
        asprintf(&haslo,"%.*s",dlug,begin);
        struct crypt_data data[1] = {0};
        struct crypt_data data2[1] = {0};
        char *res;
		
        char *hash = crypt_r(haslo, "$6$5MfvmFOaDU", data);

		//printf("%s %s \n",haslo,hash);
        if(strcmp(hash,hash1)==0)
        {
			zlamane = 1;
            printf("Zlamano! Haslo to: %.*s\n",dlug,begin);
            return 2;
        }
        free (haslo);
        return 3;
}

void* read_lines(void *ii)
{
		int i = (intptr_t)ii;
		//printf("numer: %ld",pthread_self());
        const char *hash = readParams[i].hash;
        char *buf = readParams[i].buf;
        char *buf_end = readParams[i].buf_end;
        char *begin, *end, c;
        begin = end = buf;
        int zlamano;
        while (1)
		{
				if(zlamane==1)
				{
					break;
				}
                if (! (*end == '\r' || *end == '\n')) {
                        if (++end < buf_end) continue;
                } else if (1 + end < buf_end) {
                        c = *(1 + end);
                        if ( (c == '\r' || c == '\n') && c != *end)
                                ++end;
                }
                int dlug = (long int)end;
                zlamano=print_line(begin, end, hash);
                if (zlamano==2) {
                        break;
                }
 
                if ((begin = ++end) >= buf_end)
                        break;
        }
}

int main(int argc, char *argv[])
{
    printf ("\nTrwa lamanie hasla, prosze czekac...\n");
    int proc = sysconf(_SC_NPROCESSORS_ONLN);
    if (argc > 3)
    {
		if(atoi(argv[3]) < proc)
		{
        	proc = atoi(argv[3]);
		}
    }

    char file[PATH_MAX];
    strcpy(file,argv[2]);
    struct crypt_data data[1] = {0};
    struct crypt_data data2[1] = {0};
    char *res;
	char hash[100];
    if(argc > 3)
    {
        strcpy(hash,argv[1]);
    }
    else
    {
		strcpy(hash,argv[1]);
    }
    int fd;
    if(argc > 3)
    {
        fd = open(file, O_RDONLY);
    }
    else
    {
        fd = open("1kno.txt", O_RDONLY);
    }
   
    int check = 0;
    struct stat fs;
    char *buf, *buf_end, *buf_end2, *buff, *buf2, *buff2;

    if (fd == -1) {
            err(1, "open: %s", file);
            return 0;
    }

    if (fstat(fd, &fs) == -1) {
            err(1, "stat: %s", file);
            return 0;
    }

    buf = mmap(0, fs.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (buf == (void*) -1) {
            err(1, "mmap: %s", file);
            close(fd);
            return 0;
    }

    buf_end = buf + fs.st_size;
    buf2 = buf;
    if(argc > 3)
    {
		clock_gettime(CLOCK_MONOTONIC, &start);
        pthread_t threads[128];
        void * retvals[128];
        int count;
        printf("proc: %d\n",proc);

        for (count = 0; count < proc+1; ++count)
        {
			readParams[count].hash = hash;
			readParams[count].buf = buf2;
			readParams[count].buf_end = buf2+((fs.st_size)/proc);
			buf2 = buf2+((fs.st_size)/proc);
            if (pthread_create (&threads[count], NULL, read_lines, (void *)(intptr_t)count) != 0)
            {
                fprintf(stderr, "error: Cannot create thread # %d\n", count);
                break;
            }
        }
        for (int i = 0; i < count; ++i)
        {
            if (pthread_join(threads[i], &retvals[i]) != 0)
            {
                fprintf(stderr, "error: Cannot join thread # %d\n", i);
            }
        }
		clock_gettime(CLOCK_MONOTONIC, &finish);
		elapsed = (finish.tv_sec - start.tv_sec);
		elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
		printf("Czas: %fs\n",elapsed);
    }
    else
    {
        for(int j=1;j<proc+1;j++)
        {
			clock_gettime(CLOCK_MONOTONIC, &start);
            pthread_t threads[128];
            void * retvals[128];
            int count;
            printf("proc: %d\n",j);
			buf_end = buf + fs.st_size;
    		buf2 = buf;
            for (count = 0; count < j+1; ++count)
            {
                readParams[count].hash = hash;
				readParams[count].buf = buf2;
				readParams[count].buf_end = buf2+((fs.st_size)/j);
				buf2 = buf2+((fs.st_size)/j);
		        if (pthread_create (&threads[count], NULL, read_lines, (void *)(intptr_t)count) != 0)
		        {
		            fprintf(stderr, "error: Cannot create thread # %d\n", count);
		            break;
		        }
            }
            for (int i = 0; i < count; ++i)
            {
                if (pthread_join(threads[i], &retvals[i]) != 0)
                {
                    fprintf(stderr, "error: Cannot join thread # %d\n", i);
                }
            }
            clock_gettime(CLOCK_MONOTONIC, &finish);
            elapsed = (finish.tv_sec - start.tv_sec);
            elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
            printf("Czas: %fs\n",elapsed);
        }
    }
	if(zlamane == 0)
	{
		printf("Nie znaleziono hasla\n");
	}

    munmap(buf, fs.st_size);
    close(fd);
    return 0;
}
