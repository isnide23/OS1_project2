#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        perror("Error: please enter a file.");
        return(-1);
    }

    int fp;

    fp = open(argv[1], O_RDONLY);

    char *buf = (char *) calloc(2048, sizeof(char));

    int count = read(fp, buf, 2048);

    write(STDOUT_FILENO, buf, count);
        
    close(fp);
    printf("\n");

    return 0;
}