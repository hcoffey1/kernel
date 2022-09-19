/**********
 * Hayden Coffey
 * 
 **********/
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
        FILE * fd = fopen("sample.txt", "w");

        printf("Counter is : %ld\n", syscall(451));
        printf("Calling fsync once...\n");
        fsync(fileno(fd));
        printf("Counter is : %ld\n", syscall(451));
        printf("Calling fsync three times...\n");
        fsync(fileno(fd));
        fsync(fileno(fd));
        fsync(fileno(fd));
        printf("Counter is : %ld\n", syscall(451));

        fclose(fd);
        return 0;
}
