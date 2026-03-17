#include <stdio.h>

typedef struct 
{
    int year;
    int month;
    int day;
}Data;

int main(void)
{
    Data d;
    Data *pD;
    d.year = 2026;
    d.month = 7;
    d.day = 19;

    Data d2 = 
    {
        .year = 2026,
        .month = 7,
        .day = 19
    };

    pD = &d;

    printf("%d-%d-%d", d.year, d.month, d.day);
    printf("%d-%d-%d", (*pD).year, (*pD).month, (*pD).day);
    printf("%d-%d-%d", pD->year, pD->month, pD->day);
    return 0;
    
}