#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char* argv[])
{
    const double pi = acos(-1);
    const double coefficient = pi / 180;
    double a = 90*coefficient;
    printf("%.6f\n",a);
    a = sin(90 * coefficient);
    printf("%.6f\n",a);
    printf("%f", a);
    return 0;
}
