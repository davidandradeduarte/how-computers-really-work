#include <stdio.h>
#include <signal.h>

int main(){
    int points = 27;
    int year = 2020;

    printf("points is %d and is stored at 0x%08x\n", points, &points);
    printf("year is %d and is stored at 0x%08x\n", year, &year);

    raise(SIGINT);

    return 0;
}