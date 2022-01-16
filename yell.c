#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        for(;;) {
            char *buf = (char *) calloc(2048, sizeof(char));
            int count = read(STDIN_FILENO, buf, 2048);
            for (int i = 0; i < count; i++) {
                buf[i] = toupper(buf[i]);
            }
            if (count == 0) {
                printf("\n");
                return 0;
            }
            write(STDOUT_FILENO, buf, count);
            
        }
        
    }

    for (int i = 1; i <= argc; i++) {
        int fp;
        fp = open(argv[i], O_RDONLY);

        int count = 2048;
        while (count > 0) {
            char *buf = (char *) calloc(2048, sizeof(char));
            count = read(fp, buf, 2048);
            for (int i = 0; i < count; i++) {
                buf[i] = toupper(buf[i]);
            }
            write(STDOUT_FILENO, buf, count);
        }
        close(fp);
        printf("\n");
    }

    return 0;
}