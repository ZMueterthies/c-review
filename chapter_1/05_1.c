#include <stdio.h>
/* 1.5 Character Input and Output */

/* copy input to output; 1st version */
// int main()
// {
//     int c;

//     c = getchar();
//     while(c != EOF) {
//         putchar(c);
//         c = getchar();
//     }
// }

/* copy input to output; 2nd version */
int main()
{
    int c;

    while((c = getchar()) != EOF)
        putchar(c);
}