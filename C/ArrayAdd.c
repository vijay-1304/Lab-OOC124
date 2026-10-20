#include <stdio.h>

int main()
{
    int arr[4];
    int sum = 0;
    int i;

    printf("Enter 4 elements:\n");

    for(i = 0; i < 4; i++)
    {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    printf("Addition of all elements = %d\n", sum);

    return 0;
}