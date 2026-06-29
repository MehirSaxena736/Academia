#include <stdio.h>

int arraySum(int arr[], int n) {
    if (n <= 0)
        return 0;
    return arr[n - 1] + arraySum(arr, n - 1);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = arraySum(arr, n);
    printf("Sum of all elements in the array: %d\n", sum);
    return 0;
}

