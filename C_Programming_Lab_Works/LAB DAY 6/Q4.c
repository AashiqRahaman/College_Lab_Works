#include <stdio.h>
int isPrime(int num);
int main() {
    int num, i;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Prime factors of %d are: ", num);
    for (i = 2; i <= num; i++) {
        if (num % i == 0 && isPrime(i)) {
            printf("%d ", i);
            num /= i;
            i--;
        }
    }
    return 0;
}
int isPrime(int num) {
    int i;
    if (num < 2) {
        return 0;
    }
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}