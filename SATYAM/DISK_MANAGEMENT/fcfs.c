#include <stdio.h>
#include <stdlib.h>
int main() {
    int RQ[100], n, initial, Totalhead = 0;
    printf("Enter the value of n :");
    scanf("%d", &n);
    printf("Enter the values :");
    for (int i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }
    printf("Enter the initial position :");
    scanf("%d", &initial);

    for (int i = 0; i < n; i++) {
        Totalhead = Totalhead + abs(RQ[i] - initial);
        initial = RQ[i];
    }
    for (int i = 0; i < n; i++) {
        printf("%d", RQ[i]);
    }
    printf("%d", Totalhead);
}