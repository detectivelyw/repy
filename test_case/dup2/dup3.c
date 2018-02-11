#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
 
int main(void)
{
    int retval = 0;

    int filedesc = open("./test_case/files/testfile01.txt", O_WRONLY | O_APPEND);

    printf("fd = %i \n", filedesc);
 
    if (filedesc < 0) {
        printf("Couldn't open file! \n");
        return -1;
    }

    retval = dup3(filedesc, 1, 0);

    if (retval == -1) {
        printf("dup3 failed! \n");
        return -1;
    }
 
    printf("[Test][Dup3] Write to testfile. Redirected from the stdout. \n");

    close(filedesc);
    return 0;
}
