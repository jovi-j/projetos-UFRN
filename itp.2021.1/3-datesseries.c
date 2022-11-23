#include <stdio.h>

int diffdates(int days[], int months[], int years[]){
    int daysOftheMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int d1 = years[0] * 365 + days[0];
    int d2 = years[1] * 365 + days[1];

    for (int i = 0; i < months[0] - 1; i++) {
        d1 += daysOftheMonth[i];
    }

    for (int i = 0; i < months[1] - 1; i++) {
        d2 += daysOftheMonth[i];
    }

    return d2 - d1;
}


int main(int argc, char *argv[])
{
    int days[2], months[2], years[2];
    scanf("%d %d %d", &days[0], &months[0], &years[0]);
    scanf("%d %d %d", &days[1], &months[1], &years[1]);
    printf("%d\n", diffdates(days, months, years));
    return 0;
}
