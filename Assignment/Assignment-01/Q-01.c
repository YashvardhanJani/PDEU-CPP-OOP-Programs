// Take 10 integers from the user and find: Largest and smallest element, Average of all elements, Count of even and odd numbers

#include <stdio.h>

int main() {
    int arr[10];

    // Input 10 integers in one line
    printf("Enter 10 integers separated by space: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    int min = arr[0], max = arr[0], sum = 0, even = 0, odd = 0;

    // Single loop to calculate everything
    for (int i = 0; i < 10; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
        sum += arr[i];
        if (arr[i] % 2 == 0) even++;
        else odd++;
    }

    printf("Smallest Number is: %d\n", min);
    printf("Largest Number is: %d\n", max);
    printf("Average of all elements: %.2f\n", sum / 10.0);
    printf("%d integers are even & %d are odd.\n", even, odd);

    return 0;
}