#include <stdio.h>

int main(void)
{
    int x = 12;
    float y = 3.14;
    char *s = "Hello, world!";
    int m = 0;
    int t;

    printf("x is %d, y is %f\n", x, y);
    printf("%s\n", s);

    while (m < 5) {
        t = m * 5;
        printf("%d x 5 = %d\n", m, t);
        m++;
    }
}

