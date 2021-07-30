#include <stdio.h>

int factorial(int n)
{
    int result = n;

    while (--n > 0)
    {
        result *= n;
    }

    return result;
}

int main(){
    int answer = factorial(4);
    printf("%d\n", answer);
}