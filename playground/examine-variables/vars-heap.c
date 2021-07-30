#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(){
    int points = 27;
    int year = 2020;

    printf("points is %d and is stored at 0x%08x\n", points, &points);
    printf("year is %d and is stored at 0x%08x\n", year, &year);

    void * data = malloc(512);
    printf("data is 0x%08x and is stored at 0x%08x\n", data, &data);
    
    raise(SIGINT);

    return 0;
}