#include <stdio.h>
/* 1.3 The For Statement */

/* print Fahrenheit-Celsius table */
int main()
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
    /* Exercise 1-5 */
        printf("\n");
        for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
}